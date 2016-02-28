/**
 * Created by lancemao on 2/28/16.
 */

var http = require('http');
var fs = require('fs');

 var host = '127.0.0.1';
//var host = '10.75.69.49';
var request = http.get("http://" + host + ":8000/list", function(res) {
    console.log('HEADERS: ' + JSON.stringify(res.headers));
    res.on('data', function (chunk) {
        console.log('BODY: ' + chunk);
    });
});