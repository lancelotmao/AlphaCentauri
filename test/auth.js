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

var HOST = '127.0.0.1';

crt = ursa.createPublicKey(fs.readFileSync('./../public.key'));

var userName = 'test' + new Date();
console.log('testing auth. registering user with user name:' + userName);

(function register() {
  var options = {
      host: HOST,
      port: 80,
      path: '/user/register',
      method: 'POST'
  };

  var post_data = crt.encrypt(JSON.stringify({
      username : userName,
      password : 'Pr0d1234'
  }), 'utf8', 'base64');

  var req = http.request(options, function(res) {
    	console.log('STATUS: ' + res.statusCode);
    	res.setEncoding('utf8');
    	res.on('data', function (chunk) {
      	// console.log('BODY: ' + chunk);
        if (res.statusCode == '200') {
          login();
        }
    	});
  });

  req.end(post_data);
})();

function login() {
  var options = {
      host: HOST,
      port: 80,
      path: '/user/login',
      method: 'POST'
  };

  var post_data = crt.encrypt(JSON.stringify({
      username : userName,
      password : 'Pr0d1234'
  }), 'utf8', 'base64');

  var req = http.request(options, function(res) {
      console.log('STATUS: ' + res.statusCode);
      res.setEncoding('utf8');
      res.on('data', function (chunk) {
        // console.log('BODY: ' + chunk);
        if (res.statusCode == 200) {
          logout();
        }
      });
  });

  req.end(post_data);
}

function logout() {
  var options = {
      host: HOST,
      port: 80,
      path: '/user/logout',
      method: 'POST'
  };

  var post_data = crt.encrypt(JSON.stringify({
      username : userName
  }), 'utf8', 'base64');

  var req = http.request(options, function(res) {
      console.log('STATUS: ' + res.statusCode);
      res.setEncoding('utf8');
      res.on('data', function (chunk) {
        // console.log('BODY: ' + chunk);
      });
  });

  req.end(post_data);
}
