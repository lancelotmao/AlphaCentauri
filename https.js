var https = require('https');
var fs = require('fs');

var options = {
	key: fs.readFileSync('key.pem'),
	cert: fs.readFileSync('cert.pem')
};

var a = https.createServer(options, function(req, res) {
	console.log('connected...');
	res.setHeader('content-type', 'application/xml');
	// res.writeHead(200);
	res.end(fs.readFileSync('info.plist'));
}).listen(10001);
