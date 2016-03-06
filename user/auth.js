var db = require('./../db.js');
var fs = require('fs')
var ursa = require('ursa');

var key = ursa.createPrivateKey(fs.readFileSync('./private.key'), '!QAZ2wsx');
var crt = ursa.createPublicKey(fs.readFileSync('./public.key'));

exports.rsaDecrypt = function(msg) {
    console.log('decrypting: ' + msg);
    var msg = key.decrypt(msg, 'base64', 'utf8');
    console.log('decrypted:', msg, '\n');
    return msg;
}

exports.getPublicKey = function(callback) {
    fs.readFile('./public.key', function(err, data) {
        callback(data);
    });
}

exports.register = function(uuid, username, password, callback) {
    if (username == null || password == null) {
        callback({status:405,"msg":'username, password cannot be null'});
    } else {
        var sql = "INSERT INTO common.user (uuid, name, password, createdAt) VALUES ("
        + "\'" + uuid + "\'," + "\'" + username + "\', " + "\'" + password + "\'," + "now()" + ");";
        console.log('register SQL: ' + sql);
        db.connection.query(sql, function(err, rows, fields){
            if (err) {
                callback({status:405,"msg":err});
            } else { 
                genAccessToken(uuid, callback);
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
                genAccessToken(rows[0].uuid, callback);
            }
        });
    }
}

exports.logout = function(username, callback) {
    if (username == null || password == null) {
        callback('username, password cannot be null');
    } else {
        var sql = "select * from common.user where name=\'" + username + "\';"; 
        console.log('logout SQL: ' + sql);
        db.connection.query(sql, function(err, rows, fields){
            if (err) {
                callback({status:500, msg:err});
            } else if (rows.length == 0) { 
                callback({status:405});
            } else {
                removeAccessToken(rows[0].uuid, callback);
            }
        });
    }
}

function genAccessToken(uuid, callback) {
    var now = '' + new Date();
    var data = JSON.stringify({uuid:uuid});
    console.log('gen access token for: ' + data);;

    var encrypted = encrypt(data);

    var sql = "UPDATE common.user SET accessToken=" + "\'" + encrypted + "\', updatedAt=now() where uuid=" + "\'" + uuid + "\';";
    console.log('genAccessToken SQL: ' + sql);
    db.connection.query(sql, function(err, rows, fields){
        if (err) {
            callback({status:405,"msg":err});
        } else { 
            callback({status:200,uuid:uuid, accessToken:encrypted});
        }
    });
}

function removeAccessToken(uuid, callback) {
    var now = '' + new Date();
    var data = JSON.stringify({uuid:uuid});
    console.log('remove access token for: ' + data);;

    var encrypted = encrypt(data);

    var sql = "UPDATE common.user SET accessToken=\'\', updatedAt=now() where uuid=" + "\'" + uuid + "\';";
    console.log('removeAccessToken SQL: ' + sql);
    db.connection.query(sql, function(err, rows, fields){
        if (err) {
            callback({status:405,"msg":err});
        } else { 
            callback({status:200,uuid:uuid, accessToken:encrypted});
        }
    });
}

var crypto = require('crypto'),
    algorithm = 'aes-128-ctr',
    password = 'd6F3Efeq';

function encrypt(text){
  var cipher = crypto.createCipher(algorithm,password)
  var crypted = cipher.update(text,'utf8','hex')
  crypted += cipher.final('hex');
  return crypted;
}
 
function decrypt(text){
  var decipher = crypto.createDecipher(algorithm,password)
  var dec = decipher.update(text,'hex','utf8')
  dec += decipher.final('utf8');
  return dec;
}
