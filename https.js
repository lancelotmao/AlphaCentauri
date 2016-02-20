var https = require('https');
var fs = require('fs');

var options = {
	key: fs.readFileSync('private.pem'),
	cert: fs.readFileSync('public.pem'),
	passphrase: 'M9l0d6539684'
};

var a = https.createServer(options, function(req, res) {
	console.log('connected...');
	res.setHeader('content-type', 'application/xml');
	// res.writeHead(200);
	res.end(fs.readFileSync('info.plist'));
}).listen(10000);
