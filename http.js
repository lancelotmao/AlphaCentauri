var http = require('http');
var url = require("url");
var fs = require('fs');

var configFile = "projectconfig.pjt";

var html = '<a href="itms-services://?action=download-manifest&url=https://www.wecloudapp.com:10000">Install my awesome iOS app!</a>'

http.createServer(function (req, res) {
	res.end(html);
}).listen(10001);