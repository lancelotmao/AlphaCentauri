/*
 * http server
*/
var http = require('http');
var url = require("url");
var fs = require('fs');
var createApp = require('./createapp.js');

if (!fs.existsSync('apps')) {
	fs.mkdirSync('apps');
}

http.createServer(function (req, res) {
	var parsedUrl = url.parse(req.url, true);
    var pathname = parsedUrl.pathname;

	// get App ID
	var appid = parsedUrl.query.appid;

	switch (pathname) {
    	case '/':
    	{
    		fs.readFile('site/index.html', "utf8", function(err, data){
    			res.end(data);
    		});
    	}
    	break;

    	case '/user/register':
    	{
    		var un = parsedUrl.query.username;
    		var pwd = parsedUrl.query.password;
    		var auth = require('./user/auth.js');
    		auth.register(guid(), un, pwd, function(data) {
    			res.end(data);
    		});
    	}
    	break;

    	case '/user/login':
    	{
    		var un = parsedUrl.query.username;
    		var pwd = parsedUrl.query.password;
    		var auth = require('./user/auth.js');
    		auth.login(un, pwd, function(data) {
    			res.writeHead(data.status);
    			res.end(JSON.stringify(data));
    		});
    	}
    	break;

    	case '/createapp':
    	{
    		createApp.create(guid(), function(data) {
    			console.log('create app result: ' + data);
    			res.end(data);
    		});
		}
	    break;

	    default:
	    break;
	}

    req.on("data", function (postDataChunk) {
    	switch (parsedUrl.pathname) {
    		case "/upload":
        	fs.appendFileSync(bundlePath, postDataChunk);
	        break;
        }
    });

    req.on("end", function () {
    	switch (parsedUrl.pathname) {
    		case '/upload':
    		{
    			msg = 'Upload success';
	        }
    		break;

    		case '/version':
    		{
    			
    		}
    		break;

    		case '/versions':
    		{
    			
    		}
    		break;

    		case '/download':
		    {
		    	
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

function sendResponse(res, status, msg) {
	res.writeHead(status, {
	    "Content-Type": "text/plain;charset=utf-8"
	});
	console.log((new Date()) + ' ' + msg);
	res.end(msg);
}
