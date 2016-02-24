/*
 * test for http
 */
var http = require('http');
var fs = require('fs');

var request = http.get("http://127.0.0.1:6666/versions?appid=blue&bundleName=test,%20test2", function(res) {
	res.setEncoding('utf8');
  	res.on('data', function (chunk) {
    	console.log('BODY: ' + chunk);
  	});
});
