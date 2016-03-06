/*
 * test for http
 */
var http = require('http');
var fs = require('fs')
  , ursa = require('ursa')
  , crt
  , key
  , msg
  ;

crt = ursa.createPublicKey(fs.readFileSync('./../public.key'));

var options = {
    host: '127.0.0.1',
    port: 80,
    path: '/user/login',
    method: 'POST'
};

var post_data = crt.encrypt(JSON.stringify({
    username : 'test1',
    password : 'Pr0d1234'
}), 'utf8', 'base64');

console.log('encrypted', post_data, '\n');

var req = http.request(options, function(res) {
  	console.log('STATUS: ' + res.statusCode);
 	  console.log('HEADERS: ' + JSON.stringify(res.headers));
  	res.setEncoding('utf8');
  	res.on('data', function (chunk) {
    	console.log('BODY: ' + chunk);
  	});
});

req.end(post_data);
