/*
 * http server
 */
 var http = require('http');
 var url = require("url");
 var mysql = require('mysql');
 var fs = require('fs');

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
  var appid = parsedUrl.query.appid;

  console.log('responding to: ' + pathname);

  if (appid != null && !fs.existsSync(appid)) {
    fs.mkdir(appid, null);
    fs.mkdir(appid + '/screenshot', null);
    fs.mkdir(appid + '/voice', null);
  }

  var postData = "";
  var uploadingUUID;

  switch (pathname) {
      case '/weissue/api/upload_screenshot':
      uploadingUUID = guid();
      break;
  }

  req.on("data", function (postDataChunk) {
    switch (parsedUrl.pathname) {
    case "/weissue/api/upload_screenshot":
      fs.appendFileSync(appid + '/screenshot/' + uploadingUUID, postDataChunk);
      break;

    default:
      postData += postDataChunk;
      break;
    }
  });

  req.on("end", function () {
    var status = 200;
    var msg;

    // console.log('postData: ' + postData);
    var postObj;
    try {
      postObj = JSON.parse(postData);
      appid = postObj['appid'];
    } catch(e) {
      console.log(e);
    }
    
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

      case "/weissue/api/upload_screenshot":
      {
        msg = 'upload screen shot success';
        sendResponse(res, status, msg);
      }
      break;

      case "/weissue/api/download_screenshot":
      {
        var ssdir = appid + '/screenshot';
        var ss = fs.readdirSync(ssdir);
        if (ss.length == 0) {
            status = 404;
            msg = 'screen shot download failed: ' + appid;
            sendResponse(res, status, msg);
        } else {
          finished = false;
          var path = ssdir + '/' + ss[0];
          console.log('downloading screen shot: ' + path);
          fs.readFile(path, "binary", function (err, file) {
              if (err) {
                  status = 404;
                  msg = 'download failed: ' + path;
                  res.writeHead(status, {
                      "Content-Type": "text/plain;charset=utf-8"
                  });
                  res.end(msg);
              } else {
                  res.writeHead(status, {
                      "Content-Type": "application/octet-stream",
                      "Content-Length": fs.statSync(path)['size']
                  });
                  res.write(file, "binary");
                  msg = 'download success';
                  res.end();
              }
          });
        }
      }
      break;

      default:
      console.log('path not valid: ' + pathname);
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
