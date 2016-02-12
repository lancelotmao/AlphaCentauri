/*
 * test for http
 */
var http = require('http');

var post_data = JSON.stringify({
    user : 'test1',
    project : '47389279843',
    data : '<Button &="${t : \'abc\'}"> <![CDATA[var x = 1;]]></Button>'
});

var options = {
    host: '127.0.0.1',
    port: 8888,
    path: '/',
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

// write data to request body
req.write(post_data + "\n");
req.end();
