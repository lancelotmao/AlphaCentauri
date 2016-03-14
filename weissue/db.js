var mysql = require('mysql');

var connection = mysql.createConnection({
    host: '120.25.219.17',
    port: 3306,
    user: 'lara',
    password: '!QAZ2wsx',
    database: 'weissue'
});

try {
    connection.connect();
} catch(e) {}

exports.getUsers = function(appid, callback) {
    // stores user info for sending
    var users = [];

    var sql = "select * from weissue.app_user where appid=\'" + appid + "\';"; 
    connection.query(sql, function(err, rows, fields) {
        users = [];
        userIndex = 0;
        totalUser = rows.length;
        for (var i = 0;i < rows.length;++i) {
            var user = rows[i];
            console.log('getting user info for: ' + user.userid);
            var uSQL = "select uuid,name,email from common.user where uuid=\'" + user.userid + "\';";
            connection.query(uSQL, function(err, row, fields) {
                if (row.length > 0) {
                    users.push(row[0]);
                    userIndex++;
                    if (userIndex >= totalUser) {
                        console.log('Got all user, now sending response');
                        callback(JSON.stringify(users));
                    }
                }
            });
        }
    });
}

exports.create = function(appid, postObj, callback) {
    var title = postObj['title'];
    var description = postObj['description'];
    var submittedBy = postObj['submittedBy'];
    var handler = postObj['handler'];
    var versionCode = postObj['versionCode'];
    var deviceModel = postObj['deviceModel'];
    var osVersion = postObj['osVersion'];
    var controller = postObj['controller'];
    var network = postObj['network'];
    var memory = postObj['memory'];
    var language = postObj['language'];
    if (title == null || description == null || submittedBy == null || handler == null || appid == null || versionCode == null) {
        callback('title, description, submittedBy, handler, appid, versionCode cannot be null');
    } else {
        var uuid = guid();
        var sql = "INSERT INTO weissue.issue (uid, title, description, submittedBy, handler, status, appid, versionCode, deviceModel, osVersion, controller, network, memory, language, createdAt) VALUES ("
        + "\'" + uuid + "\'," + "\'" + title + "\', " + "\'" + description + "\'," + "\'" + submittedBy + "\', " + "\'" + handler + "\', " + "\'open\'," + "\'" + appid + "\',"
        + "\'" + versionCode + "\'," + "\'" + deviceModel + "\'," + "\'" + osVersion + "\'," + "\'" + controller + "\'," + "\'" + network + "\'," + "\'" + memory + "\'," + "\'" + language + "\'," + "now()" + ");"; 
        connection.query(sql, function(err, rows, fields){
            if (err) {
                console.log(err);
            } else { 
                callback("" + JSON.stringify({uuid:uuid}));
            }
        });
    }
}

exports.list = function(appid, callback) {
    var sql = "select * from weissue.issue where appid=\'" + appid + "\';"; 
    connection.query(sql, function(err, rows, fields){
        if (err) {
            console.log(err);
            callback('db error. create');
        } else {
            callback(JSON.stringify(rows));
        }
    });
}

exports.uploadScreenshot = function(issueid, callback) {
    var uuid = guid();
    var sql = "INSERT INTO weissue.issue_screenshot (issueid, ssid) VALUES ("
    + "\'" + issueid + "\'," + "\'" + uuid + "\'" + ");"; 
    connection.query(sql, function(err, rows, fields){
        if (err) {
            console.log(err);
            callback('db error. uploadScreenshot');
        } else {
            callback(JSON.stringify({uuid:uuid}));
        }
    });
}

exports.screenshotList = function(issueid, callback) {
    var sql = "select ssid from weissue.issue_screenshot where issueid=\'" + issueid + "\';";
    connection.query(sql, function(err, rows, fields){
        if (err) {
            console.log(err);
            callback('db error. screenshotList');
        } else {
            callback(rows);
        }
    });
}

function guid() {
    return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
        var r = Math.random()*16|0, v = c == 'x' ? r : (r&0x3|0x8);
        return v.toString(16);
    });
}

function getUser(users, userid) {
    var uSQL = "select * from common.user where uuid=\'" + userid + "\';";
    connection.query(uSQL, function(err, row, fields) {
        if (row.length > 0) {
            users.push(row[0]);
        }
    });
}

