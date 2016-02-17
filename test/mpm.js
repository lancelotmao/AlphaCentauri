/*
 * test for http
 */
var http = require('http');
var fs = require('fs');

var HOST = '127.0.0.1';
// var HOST = '10.75.69.49';

var options = {
    host: HOST,
    port: 8888,
    path: '/upload?projectId=216203276&ci=2',
    method: 'POST'
};

var req = http.request(options, function(res) {
  	console.log('STATUS: ' + res.statusCode);
 	  console.log('HEADERS: ' + JSON.stringify(res.headers));
  	res.setEncoding('utf8');
  	res.on('data', function (chunk) {
    	console.log('BODY: ' + chunk);
  	});
});

var stream = fs.createReadStream('216203276.zip');
stream.on('data', function(data) {
  req.write(data);
});

stream.on('end', function() {
  req.end();
});
