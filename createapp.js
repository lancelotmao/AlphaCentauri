var mysql = require('mysql');
var fs = require('fs');

var connection = mysql.createConnection({
    host: '120.25.219.17',
    port: 3306,
    user: 'lara',
    password: '!QAZ2wsx'
});

try {
    connection.connect();
} catch(e) {}

exports.create = function(appid) {
    if (!fs.existsSync('apps/' + appid)) {
    	fs.mkdirSync('apps/' + appid);
    }

    var sql = "CREATE SCHEMA `" + appid + "` DEFAULT CHARACTER SET utf8 ;"; 
    connection.query(sql, function(err, rows, fields) {
    	console.log(err + rows);
    });
}
