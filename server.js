/*
 * http server
*/
var http = require('http');
var url = require("url");
var fs = require('fs');
var AdmZip = require('adm-zip');
var xml2js = require('xml2js');
var sys = require('sys');
var exec = require('child_process').exec;
var os = require('os');

var configFile = "AndroidManifest.xml";
var aapt = os.platform() == 'linux' ? 'aapt_linux' : 'aapt_mac';
console.log('OS name: ' + os.platform() + ' aapt: ' + aapt);

http.createServer(function (req, res) {
	var parsedUrl = url.parse(req.url, true);
    var pathname = parsedUrl.pathname;

	// get App ID
	var appid = parsedUrl.query.appid;

	switch (pathname) {
    	case '/':
    	{
    		fs.readFile('site/index.html', "utf8", function(err, data){
    			res.end(data);
    		});
    	}
    	break;

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

		    if (type == null) {
		    	type = 'zip';
		    }
		    bundlePath = bundleFolder + '/' + bundleName + '.' + type;
			bundleFileName = bundleName + '.' + type;

			console.log((new Date()) + ' uploading ' + bundlePath);
		}
	    break;

	    default:
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
    	switch (parsedUrl.pathname) {
    		case '/upload':
    		{
    			msg = 'Upload success';
	        }
    		break;

    		case '/version':
    		{
    			finished = false;
    			var cmd = "./" + aapt + " dump badging " + bundlePath + " | sed '/^package/ !d' | sed 's/.*versionCode=.\\([0-9]*\\).*/\\1/g'";
    			var child = exec(cmd, function(err, stdout, stderr) {
    				if(err) {        
						status = 404;
						res.writeHead(status, {
				            "Content-Type": "text/plain;charset=utf-8"
				        });
						msg = 'get version failed: ' + bundlePath + ' ' + err;
						res.end(msg);
					} else {
						status = 200;
						res.writeHead(status, {
				            "Content-Type": "text/plain;charset=utf-8"
				        });
						msg = stdout;
						res.end(msg);
					}
					console.log((new Date()) + ' ' + msg);
    			});
    		}
    		break;

    		case '/versions':
    		{
    			console.log('checking versions for: ' + bundleName);
    			finished = false;
    			var versions = [];
    			var completeCounter = 0;
    			var bundles = bundleName.split(',');
    			for (var i = 0, n = bundles.length;i < n;++i) {
    				var trimedName = bundles[i].trim();
    				var bp = 'packages_native/' + appid + '/' + trimedName + '/' + trimedName + '.apk';
    				getVersion(bp, trimedName, function(bn, v) {
    					var x = {};
    					x[bn] = v;
    					versions.push(x);
    					completeCounter++;
    					if (completeCounter == n) {
							status = 200;
							res.writeHead(status, {
					            "Content-Type": "text/plain;charset=utf-8"
					        });
							msg = JSON.stringify(versions);
							console.log((new Date()) + ' versions: ' + msg);
							res.end(msg);
    					}
    				});
    			}
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
				            "Content-Type": "application/octet-stream",
				            "Content-Length": fs.statSync(bundlePath)['size'],
				            "Content-Disposition": bundleFileName
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
	});
}).listen(80);

console.log("http server listening at 80");

function getVersion(bundlePath, bundleName, callback) {
	var cmd = "./" + aapt + " dump badging " + bundlePath + " | sed '/^package/ !d' | sed 's/.*versionCode=.\\([0-9]*\\).*/\\1/g'";
	var child = exec(cmd, function(err, stdout, stderr) {
		if(stderr) {
			callback(bundleName, '-1');      
		} else {
			callback(bundleName, stdout.trim());
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
