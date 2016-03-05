var db = require('./../db.js');
var fs = require('fs');

exports.register = function(uuid, username, password, callback) {
    if (username == null || password == null) {
        callback('username, password cannot be null');
    } else {
        var sql = "INSERT INTO common.user (uuid, name, password, createdAt) VALUES ("
        + "\'" + uuid + "\'," + "\'" + username + "\', " + "\'" + password + "\'," + "now()" + ");";
        console.log('register SQL: ' + sql);
        db.connection.query(sql, function(err, rows, fields){
            if (err) {
                callback({status:405,"msg":err});
            } else { 
                callback({status:200,uuid:uuid});
            }
        });
    }
}

exports.login = function(username, password, callback) {
    if (username == null || password == null) {
        callback('username, password cannot be null');
    } else {
        var sql = "select * from common.user where name=\'" + username + "\' AND password=\'" + password + "\';"; 
        console.log('login SQL: ' + sql);
        db.connection.query(sql, function(err, rows, fields){
            if (err) {
                callback({status:500, msg:err});
            } else if (rows.length == 0) { 
                callback({status:405});
            } else {
                callback({status:200, uuid:rows[0].uuid});
            }
        });
    }
}
