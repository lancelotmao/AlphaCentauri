var db = require('./db.js');
var fs = require('fs');

exports.create = function(appid, callback) {
    if (!fs.existsSync('apps/' + appid)) {
    	fs.mkdirSync('apps/' + appid);
    }

    var sql = "CREATE SCHEMA `" + appid + "` DEFAULT CHARACTER SET utf8 ;"; 
    db.connection.query(sql, function(err, rows, fields) {
    	if (err) {
    		callback(err);
    	} else {
    		callback(JSON.stringify(rows))
    	}
    });
}
