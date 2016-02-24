/*
 * test for http
 */

var http = require('http');
var fs = require('fs');

var host = '127.0.0.1';
// var host = '10.75.69.49';
var request = http.get("http://" + host + ":6666/download?appid=blue&bundleName=test", function(res) {
	console.log('HEADERS: ' + JSON.stringify(res.headers));
	if (res.statusCode == 404) {
		res.setEncoding('utf8');
	  	res.on('data', function (chunk) {
	    	console.log('BODY: ' + chunk);
	  	});
	} else {
		var file = fs.createWriteStream("haha.apk");
		res.pipe(file);
	}
});
