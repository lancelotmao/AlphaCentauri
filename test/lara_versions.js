/*
 * test for http
 */
var http = require('http');
var fs = require('fs');

var host = "127.0.0.1";
// var host = "10.75.69.49";
var host = '120.25.219.17';

var request = http.get("http://" + host + ":6666/versions?appid=blue&bundleName=test,%20test2", function(res) {
	res.setEncoding('utf8');
  	res.on('data', function (chunk) {
    	console.log('BODY: ' + chunk);
  	});
});
