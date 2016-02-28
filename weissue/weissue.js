/*
 * http server
 */
 var http = require('http');
 var url = require("url");
 var mysql = require('mysql');

 var connection = mysql.createConnection({
  host: '120.25.219.17',
  port: 3306,
  user: 'lara',
  password: '!QAZ2wsx',
  database: 'weissue'
});

 connection.connect();

 http.createServer(function (req, res) {
  var parsedUrl = url.parse(req.url, true);
  var pathname = parsedUrl.pathname;

  console.log('responding to: ' + pathname);
  var postData = "";

  req.on("data", function (postDataChunk) {
    postData += postDataChunk;
  });

  req.on("end", function () {
    var status = 200;
    var msg;

    console.log('postData: ' + postData);

    var postObj = JSON.parse(postData);
    var appid = postObj['appid'];
    
    switch (parsedUrl.pathname) {
      case '/weissue/api/create':
      {
        var title = postObj['title'];
        var description = postObj['description'];
        var submittedBy = postObj['submittedBy'];
        var versionCode = postObj['versionCode'];
        if (title == null || description == null || submittedBy == null || appid == null || versionCode == null) {
          msg = 'title, description, submittedBy, appid, versionCode cannot be null';
          sendResponse(res, status, msg);
        } else {
          var uuid = guid();
          var sql = "INSERT INTO weissue.issue (uid, title, description, submittedBy, status, appid, versionCode, createdAt) VALUES ("
          + "\'" + uuid + "\'," + "\'" + title + "\', " + "\'" + description + "\'," + "\'" + submittedBy + "\', " + "\'open\'," + "\'" + appid + "\',"
          + "\'" + versionCode + "\'," + "now()" + ");"; 
          connection.query(sql, function(err, rows, fields){
            if (err) {
              console.log(err);
              connection.end();
            } else { 
              msg = 'create issue success';
              sendResponse(res, status, JSON.stringify({uuid:uuid}));
            }
          });
        }
      }
      break;

      case '/weissue/api/list':
      {
        var sql = "select * from weissue.issue where appid=\'" + appid + "\';"; 
        connection.query(sql, function(err, rows, fields){
          if (err) {
            msg = err;
            connection.end();
            status = 405;
          } else {
            msg = rows;
            console.log('', rows); 
          }
          sendResponse(res, status, JSON.stringify(msg));
        });
      }
      break;
    }
  });
}).listen(7000);

 console.log("We issue http server listening at 7000");

 function guid() {
  return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
    var r = Math.random()*16|0, v = c == 'x' ? r : (r&0x3|0x8);
    return v.toString(16);
  });
}

function sendResponse(res, status, msg) {
  res.writeHead(status, {
    "Content-Type": "text/plain;charset=utf-8"
  });
  console.log((new Date()) + ' ' + msg);
  res.end(msg);
}
