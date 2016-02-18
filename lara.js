/*
 * http server
*/
var http = require('http');
var url = require("url");
var fs = require('fs');
var AdmZip = require('adm-zip');
var xml2js = require('xml2js');

var configFile = "AndroidManifest.xml";

http.createServer(function (req, res) {
	var parsedUrl = url.parse(req.url, true);
    var pathname = parsedUrl.pathname;

	// get App ID
	var appid = parsedUrl.query.appid;

	var bundleName = parsedUrl.query.bundleName;

	if (appid == null || bundleName == null) {
		sendResponse(res, 404, 'must specify appid and bundName in query');
		return;
	}

	var type = parsedUrl.query.type;
	if (type == null) {
    	type = 'zip';
    }

	var baseFolder = 'packages_native/' + appid;
	var bundleFolder = baseFolder + '/' + bundleName;
	var bundlePath = bundleFolder + '/' + bundleName + '.' + type;

    switch (pathname) {
    	case '/upload':
    	{
    		if (!fs.existsSync('packages_native')) {
		    	fs.mkdirSync('packages_native');
		    }

		    // create folder if not exist
		    if (!fs.existsSync(baseFolder)) {
		    	console.log('Project ' + appid + ' does not exist. creating folder');
		    	fs.mkdirSync(baseFolder);
		    }

		    if (!fs.existsSync(bundleFolder)) {
		    	console.log('Bundle ' + bundleName + ' does not exist. creating folder');
		    	fs.mkdirSync(bundleFolder);
		    }
		    
		    // delete file if exists already
		    if (fs.existsSync(bundlePath)) {
			    // fs.unlinkSync(filePath);
			}
		    console.log((new Date()) + ' uploading ' + bundlePath);
		}
	    break;
	}

    req.on("data", function (postDataChunk) {
    	switch (parsedUrl.pathname) {
    		case "/upload":
        	fs.appendFileSync(bundlePath, postDataChunk);
	        break;
        }
    });

    req.on("end", function () {
    	var status = 200;
		var msg;
		var finished = true;
    	
    	switch (parsedUrl.pathname) {
    		case '/upload':
    		{
    			// reading archives
			    var zip = new AdmZip(bundlePath);
			    var zipEntries = zip.getEntries(); // an array of ZipEntry records

			    zipEntries.forEach(function(zipEntry) {
			        if (zipEntry.name === configFile) {
			            zip.extractEntryTo(zipEntry, bundleFolder, false, true);
			        }
			    });

				msg = 'Upload success';
	        }
    		break;

    		case '/version':
    		{
    			finished = false;
    			var path = bundleFolder + '/' + configFile;
		    	fs.readFile(path, "binary", function(err, file) {
					if(err) {        
						status = 404;
						msg = 'get version failed: ' + path;
						res.writeHead(status, {
				            "Content-Type": "text/plain;charset=utf-8"
				        });
				        res.end(msg);
					} else {
						res.writeHead(status, {
				            "Content-Type": "text/plain;charset=utf-8"
				        });
						res.write(file, "binary");
						msg = 'get version success';
						res.end();
					}
					
					console.log((new Date()) + ' ' + msg + ': ' + appid + ', ' + bundleName);
				});
    		}
    		break;

    		case '/download':
		    {
		    	finished = false;
		    	
		    	fs.readFile(bundlePath, "binary", function(err, file) {
					if(err) {        
						status = 404;
						msg = 'download failed: ' + bundlePath;
						res.writeHead(status, {
				            "Content-Type": "text/plain;charset=utf-8"
				        });
				        res.end(msg);
					} else {
						res.writeHead(status, {
				            "Content-Type": "text/plain;charset=utf-8"
				        });
						res.write(file, "binary");
						msg = 'download success';
						res.end();
					}
					
					console.log((new Date()) + ' ' + msg + ': ' + appid + ', ' + bundleName);
				});
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
}).listen(6666);

console.log("Lara Package Manager http server listening at 6666");

function sendResponse(res, status, msg) {
	res.writeHead(status, {
	    "Content-Type": "text/plain;charset=utf-8"
	});
	console.log((new Date()) + ' ' + msg);
	res.end(msg);
}