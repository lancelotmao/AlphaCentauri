/**
 * Created by lancemao on 2/28/16.
 */

/*
 * http server
 */
var http = require('http');
var url = require("url");
var fs = require('fs');
var xml2js = require('xml2js');

if (!fs.existsSync('models')) {
    fs.mkdirSync('models');
}

http.createServer(function (req, res) {
    var parsedUrl = url.parse(req.url, true);
    var pathname = parsedUrl.pathname;

    var modelName = parsedUrl.query.modelName;
    var type = parsedUrl.query.type;
    if (type == null) {
        type = 'zip';
    }
    var baseFolder = 'models';
    var modelFolder = baseFolder + '/' + modelName;
    var modelPath = modelFolder + '/' + modelName + '.' + type;

    switch (pathname) {
        case '/upload':
        {
            if (modelName == null) {
                sendResponse(res, 404, 'must specify modelName in query');
                return;
            }
            if (!fs.existsSync(modelFolder)) {
                console.log('Model ' + modelName + ' does not exist. creating folder');
                fs.mkdirSync(modelFolder);
            }
            console.log((new Date()) + ' uploading ' + modelPath);
        }
            break;

        default:
            break;
    }

    req.on("data", function (postDataChunk) {
        switch (parsedUrl.pathname) {
            case "/upload":
                fs.appendFileSync(modelPath, postDataChunk);
                break;
        }
    });

    req.on("end", function () {
        var status = 200;
        var msg;

        switch (parsedUrl.pathname) {
            case '/upload':
            {
                msg = 'Upload success';
            }
                break;

            case '/list':
            {
                fs.readdir(baseFolder, function(err, files){
                    sendResponse(res, status, JSON.stringify(files));
                });
            }
                break;

            case '/download':
            {
                if (!fs.existsSync(modelPath)) {
                    status = 404;
                    msg = 'download failed: ' + modelPath;
                } else {
                    finished = false;
                    fs.readFile(modelPath, "binary", function (err, file) {
                        if (err) {
                            status = 404;
                            msg = 'download failed: ' + modelPath;
                            res.writeHead(status, {
                                "Content-Type": "text/plain;charset=utf-8"
                            });
                            res.end(msg);
                        } else {
                            res.writeHead(status, {
                                "Content-Type": "application/octet-stream",
                                "Content-Length": fs.statSync(modelPath)['size'],
                                "Content-Disposition": modelName + '.' + type
                            });
                            res.write(file, "binary");
                            msg = 'download success';
                            res.end();
                        }

                        console.log((new Date()) + ' ' + msg + ': ' + appid + ', ' + modelName);
                    });
                }
            }
                break;

            default:
                status = 404;
                msg = 'path not found ' + pathname;
                break;
        }
    });
}).listen(8000);

console.log("Jupiter http server listening at 8000");

function sendResponse(res, status, msg) {
    res.writeHead(status, {
        "Content-Type": "text/plain;charset=utf-8"
    });
    console.log((new Date()) + ' ' + msg);
    res.end(msg);
}
