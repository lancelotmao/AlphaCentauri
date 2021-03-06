
var data = {
      title: 'I found an issue',
      description: 'this is a naughty bug', 
      submittedBy: 'tester', 
      handler: 'lance', 
      appid: 'jupiter', 
      versionCode:'1',
      deviceModel:'iPhone 6+',
      osVesion:'iOS 9.2',
      controller:'DemoViewController',
      network:'WIFI',
      memory:'30M/1024M',
      language:'en-US',
}
var listParam = {appid: 'jupiter'};
/*
 * test for http
 */
var http = require('http');
var fs = require('fs');

var HOST = '127.0.0.1';
// var HOST = '10.75.69.49';
// var HOST = '120.25.219.17';

var options = {
      host: HOST,
      port: 7000,
      path: '/weissue/api/create',
      method: 'POST'
};

var req = http.request(options, function(res) {
      console.log('STATUS: ' + res.statusCode);
      console.log('HEADERS: ' + JSON.stringify(res.headers));
      res.setEncoding('utf8');
      res.on('data', function (chunk) {
            console.log('BODY: ' + chunk);
      });

      res.on('end', function(res){
            listIssues();
      });
});

console.log(JSON.stringify(data));
req.end(JSON.stringify(data));

function listIssues() {
      console.log('listing issues...');
      var options = {
            host: HOST,
            port: 7000,
            path: '/weissue/api/list',
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
      req.end(JSON.stringify(listParam));
}

