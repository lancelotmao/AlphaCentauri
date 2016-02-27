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

connection.query('select * from issue;', function(err, rows, fields){
  if (err) {
    console.log(err);
    connection.end();
  } else {
    console.log('', rows);  
  }
});

http.createServer(function (req, res) {
  var parsedUrl = url.parse(req.url, true);
  var pathname = parsedUrl.pathname;

  var postData = "";

  req.on("data", function (postDataChunk) {
    postData += postDataChunk;
  });

  req.on("end", function () {
    var status = 200;
    var msg;
    var finished = true;

    console.log('postData: ' + postData);

    var postObj = JSON.parse(postData);
    
    switch (parsedUrl.pathname) {
      case '/weissue/api/create':
      {
        finished = false;
        var title = postObj['title'];
        var description = postObj['description'];
        var submittedBy = postObj['submittedBy'];
        var appid = postObj['appid'];
        var versionCode = postObj['versionCode'];
        if (title == null || description == null || submittedBy == null || appid == null || versionCode == null) {
          msg = 'title, description, submittedBy, appid, versionCode cannot be null';
          sendResponse(res, status, msg);
        } else {
          var sql = "INSERT INTO weissue.issue (uid, title, description, submittedBy, status, appid, versionCode, createdAt) VALUES \
          (uuid()," + "\'" + title + "\', " + "\'" + description + "\'," + "\'" + submittedBy + "\', " + "\'open\'," + "\'" + appid + "\',"
          + "\'" + versionCode + "\'," + "now()" + ");"; 
          connection.query(sql, function(err, rows, fields){
            if (err) {
              console.log(err);
              connection.end();
            } else {
              console.log('', rows);  
              msg = 'create issue success';
              sendResponse(res, status, msg);
            }
          });
        }
      }
      break;

      default:
      status = 404;
      msg = 'path not found ' + pathname;
      break;
    }

    // for asynchronous service, finish later
    if (finished) {
      sendResponse(res, status, msg);
  }
  });
}).listen(7000);

console.log("We issue http server listening at 7000");

function sendResponse(res, status, msg) {
  res.writeHead(status, {
      "Content-Type": "text/plain;charset=utf-8"
  });
  console.log((new Date()) + ' ' + msg);
  res.end(msg);
}
