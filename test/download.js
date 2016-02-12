/*
 * test for http
 */

var http = require('http');
var fs = require('fs');

var request = http.get("http://127.0.0.1:8888/download?projectId=216203276", function(res) {
	if (res.statusCode == 404) {
		res.setEncoding('utf8');
	  	res.on('data', function (chunk) {
	    	console.log('BODY: ' + chunk);
	  	});
	} else {
		var file = fs.createWriteStream("lance_download.zip");
		res.pipe(file);
	}
});
