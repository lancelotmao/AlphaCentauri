/*
 * test for http
 */

var http = require('http');
var fs = require('fs');

var request = http.get("http://127.0.0.1:6666/download?appid=blue&bundleName=test&type=apk", function(res) {
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
