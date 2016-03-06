/*
 * http server
*/
var http = require('http');
var https = require('https');
var url = require("url");
var fs = require('fs');
var auth = require('./user/auth.js');
var createApp = require('./createapp.js');

if (!fs.existsSync('apps')) {
	fs.mkdirSync('apps');
}

http.createServer(function (req, res) {
	var parsedUrl = url.parse(req.url, true);
    var pathname = parsedUrl.pathname;

	// get App ID
	var appid = parsedUrl.query.appid;

	var postData = "";

	switch (pathname) {
		case '/createapp':
    	{
    		createApp.create(guid(), function(data) {
    			console.log('create app result: ' + data);
    			res.end(data);
    		});
		}
	    break;

	    case '/publicKey':
	    auth.getPublicKey(function(data) {
	    	res.end(data);
	    })
	    break;

	    case '/user/register':
	    case '/user/login':
	    break;

	    default:
    	homePage(pathname, res);
    	break;
	}

    req.on("data", function (postDataChunk) {
    	switch (parsedUrl.pathname) {
    		case "/upload":
        	fs.appendFileSync(bundlePath, postDataChunk);
	        break;

	        default:
	        postData += postDataChunk;
	        break;
        }
    });

    req.on("end", function () {
    	switch (parsedUrl.pathname) {
    		case '/user/register':
	    	{
	    		try {
		    		var decrypted = JSON.parse(auth.rsaDecrypt(postData));
		    		var un = decrypted.username;
		    		var pwd = decrypted.password;
		    		console.log('registering username=' + un + ' password=' + pwd);
		    		auth.register(guid(), un, pwd, function(data) {
		    			var msg = JSON.stringify(data);
		    			console.log('register result:' + msg);
		    			res.writeHead(data.status);
		    			res.end(msg);
		    		});
		    	} catch(e) {
		    		res.end('register failed. unknown error');
		    	}
	    	}
	    	break;

	    	case '/user/login':
	    	{
	    		var un = parsedUrl.query.username;
	    		var pwd = parsedUrl.query.password;
	    		try {
		    		var decrypted = JSON.parse(auth.rsaDecrypt(postData));
		    		var un = decrypted.username;
		    		var pwd = decrypted.password;
		    		console.log('logging in username=' + un + ' password=' + pwd);
		    		auth.login(un, pwd, function(data) {
		    			var msg = JSON.stringify(data);
		    			console.log('login result:' + msg);
		    			res.writeHead(data.status);
		    			res.end(msg);
		    		});
		    	} catch(e) {
		    		res.end('login failed. unknown error');
		    	}
	    	}
	    	break;

		    default:
		    status = 404;
		    msg = 'path not found ' + pathname;
		    break;
    	}
	});
}).listen(80);

console.log("http server listening at 80");

function guid() {
	return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
		var r = Math.random()*16|0, v = c == 'x' ? r : (r&0x3|0x8);
		return v.toString(16);
	});
}

function homePage(path, res) {
	if (path === '/') {
		path = 'site/index.html';
	} else {
		path = 'site/' + path;
	}
	fs.readFile(path, "utf8", function(err, data){
		console.log('' + data);
		res.end(data);
	});
}

// https server
var options = {
	key: fs.readFileSync('private.pem'),
	cert: fs.readFileSync('public.pem'),
	passphrase: 'M9l0d6539684'
};

var a = https.createServer(options, function(req, res) {
	var parsedUrl = url.parse(req.url, true);
    var pathname = parsedUrl.pathname;
	console.log('https serving: ' + pathname);

    switch(pathname) {
		case '/user/register':
    	{
    		var un = parsedUrl.query.username;
    		var pwd = parsedUrl.query.password;
    		var auth = require('./user/auth.js');
    		console.log('registering username=' + un + ' password=' + pwd);
    		auth.register(guid(), un, pwd, function(data) {
    			var msg = JSON.stringify(data);
    			console.log('register result:' + msg);
    			res.writeHead(data.status);
    			res.end(msg);
    		});
    	}
    	break;

    	case '/user/login':
    	{
    		var un = parsedUrl.query.username;
    		var pwd = parsedUrl.query.password;
    		var auth = require('./user/auth.js');
    		console.log('logging in username=' + un + ' password=' + pwd);
    		auth.login(un, pwd, function(data) {
    			var msg = JSON.stringify(data);
    			console.log('login result:' + msg);
    			res.writeHead(data.status);
    			res.end(msg);
    		});
    	}
    	break;

    	default:
    	homePage(pathname, res);
    	break;
    }
}).listen(443);

console.log("https server listening at 443");
