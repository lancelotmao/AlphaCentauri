/*
 * http server
 */
var http = require('http');
var url = require("url");
var mysql = require('mysql');
var fs = require('fs');
var db = require('./db.js');

if (!fs.existsSync('screenshot')) {
  fs.mkdir('screenshot', null);
}

http.createServer(function (req, res) {
  var parsedUrl = url.parse(req.url, true);
  var pathname = parsedUrl.pathname;
  var appid = parsedUrl.query.appid;
  var type = parsedUrl.query.type;

  // current index retrieved from DB
  var userIndex;

  // total number of user for an app
  // when userIndex is equal to totalUser
  // we send out response
  var totalUser;

  console.log('responding to: ' + pathname);

  if (appid != null && !fs.existsSync(appid)) {
    fs.mkdir(appid, null);
  }

  var postData = "";
  var issueID = parsedUrl.query.issueid;
  var uploadingUUID;

  switch (pathname) {
    case '/weissue/api/upload_screenshot':
    {
      uploadingUUID = guid();
      var path = 'screenshot/' + issueID;
      if (!fs.existsSync(path)) {
        fs.mkdir(path);
      }
    }
    break;
  }

  req.on("data", function (postDataChunk) {
    switch (parsedUrl.pathname) {
      case "/weissue/api/upload_screenshot":
      fs.appendFileSync('screenshot/' + issueID + '/' + uploadingUUID + '.' + type, postDataChunk);
      break;

      default:
      postData += postDataChunk;
      break;
    }
  });

  req.on("end", function () {
    try {
      var status = 200;
      var msg;

      // console.log('postData: ' + postData);
      var postObj;
      if (postData != null) {
        try {
          postObj = JSON.parse(postData);
          appid = postObj['appid'];
        } catch(e) {
          console.log(e);
        }
      }
      
      switch (parsedUrl.pathname) {
        case '/weissue/api/users':
        { 
          if (appid) {
            db.getUsers(appid, function(data) {
              sendResponse(res, status, data);
            });
          } else {
              sendResponse(res, status, 'must specify appid');
          }
        }
        break;

        case '/weissue/api/create':
        {
          if (postObj == null) {
            sendResponse(res, status, JSON.stringify({status:405,msg:'post data is NULL'}));
          } else {
            db.create(appid, postObj, function(data) {
              sendResponse(res, status, data);
            });
          }
        }
        break;

        case '/weissue/api/list':
        {
          db.list(appid, function(data) {
            sendResponse(res, status, data);
          });
        }
        break;

        case "/weissue/api/upload_screenshot":
        {
          db.uploadScreenshot(issueID, function(data){
            msg = data;
            sendResponse(res, status, msg);
          });
        }
        break;

        case "/weissue/api/download_screenshot":
        {
          var ssdir = 'screenshot/' + issueID;
          if (fs.existsSync(ssdir)) {
            var ss = fs.readdirSync(ssdir);
            if (ss.length == 0) {
              status = 404;
              msg = 'screen shot download failed: ' + issueID;
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
          } else {
            status = 404;
            msg = 'screen shot download failed: ' + issueID;
            sendResponse(res, status, msg);
          }
        }
        break;

        case '/weissue/api/screenshotList':
        {
          db.screenshotList(issueID, function(data) {
            sendResponse(res, status, JSON.stringify(data));
          });
        }
        break;

        default:
        console.log('path not valid: ' + pathname);
        break;
      }
    }catch(ex) {
      console.log('Exception: ' + ex);
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

function getUser(users, userid) {
  var uSQL = "select * from common.user where uuid=\'" + userid + "\';";
  connection.query(uSQL, function(err, row, fields) {
    if (row.length > 0) {
      users.push(row[0]);
    }
  });
}

function sendResponse(res, status, msg) {
  res.writeHead(status, {
    "Content-Type": "text/plain;charset=utf-8"
  });
  console.log((new Date()) + ' ' + msg);
  res.end(msg);
}
