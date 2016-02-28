/**
 * Created by lancemao on 2/28/16.
 */

var http = require('http');
var fs = require('fs');

 var host = '127.0.0.1';
//var host = '10.75.69.49';
var request = http.get("http://" + host + ":8000/download?modelName=astroboy", function(res) {
    console.log('HEADERS: ' + JSON.stringify(res.headers));
    if (res.statusCode == 404) {
        res.setEncoding('utf8');
        res.on('data', function (chunk) {
            console.log('BODY: ' + chunk);
        });
    } else {
        var file = fs.createWriteStream("astroboy_downloaded.zip");
        res.pipe(file);
    }
});