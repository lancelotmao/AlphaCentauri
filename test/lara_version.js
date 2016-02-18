/*
 * test for http
 */
var http = require('http');
var fs = require('fs');

var options = {
    host: '127.0.0.1',
    port: 6666,
    path: '/version?appid=blue&bundleName=test',
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

req.end();
