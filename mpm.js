/*
 * http server
*/
var http = require('http');
var url = require("url");
var fs = require('fs');
var AdmZip = require('adm-zip');
var xml2js = require('xml2js');
var compiler = require('./packager.js');

var configFile = "projectconfig.pjt";

http.createServer(function (req, res) {
	var parsedUrl = url.parse(req.url, true);
    var pathname = parsedUrl.pathname;

	// get project id from query
	var projectId = parsedUrl.query.projectId;

	// get ci id
	var ciId = parsedUrl.query.ci;

	// used for packaging
	var platform = parsedUrl.query.platform;

	var type = parsedUrl.query.type;
	if (type == null) {
    	type = 'zip';
    }

	var baseFolder = 'packages/' + projectId;

    switch (pathname) {
    	case '/upload':
    	{
    		if (!fs.existsSync('packages')) {
		    	fs.mkdirSync('packages');
		    }

		    // create folder if not exist
		    if (!fs.existsSync(baseFolder)) {
		    	console.log('Project ' + projectId + ' does not exist. creating folder');
		    	fs.mkdirSync(baseFolder);
		    	fs.mkdirSync(baseFolder + '/ci');
		    	fs.mkdirSync(baseFolder + '/release');
		    }

		    var ciDir = baseFolder + '/ci/' + ciId;
		    if (!fs.existsSync(ciDir)) {
		    	fs.mkdirSync(ciDir);
		    }

		    var filePath;
		    if (ciId !== undefined) {
		    	filePath = ciDir + '/' + ciId + '.' + type;	
		    } else {
		    	filePath = baseFolder + '/release/' + projectId + '.' + type;
		    }

		    // delete file if exists already
		    if (fs.existsSync(filePath)) {
			    fs.unlinkSync(filePath);
			}
		    console.log((new Date()) + ' uploading ' + filePath);
		}
	    break;

	    case '/deploy':
	    {
	    	console.log((new Date()) + ' deploying ' + projectId + ' with ci id: ' + ciId);
	    }
	    break;
	}

    req.on("data", function (postDataChunk) {
    	switch (parsedUrl.pathname) {
    		case "/upload":
        	fs.appendFileSync(filePath, postDataChunk);
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
    			var dir;
    			var filePath;
			    if (ciId !== undefined) {
			    	dir = baseFolder + '/ci/' + ciId + '/';
			    	filePath = dir + ciId + '.' + type;	
			    } else {
			    	dir = baseFolder + '/release/';
			    	filePath = dir + projectId + '.' + type;
			    }

			    if(fs.existsSync(filePath)) {
	    			// reading archives
				    var zip = new AdmZip(filePath);
				    var zipEntries = zip.getEntries(); // an array of ZipEntry records

				    zipEntries.forEach(function(zipEntry) {
				        if (zipEntry.name === configFile) {
				            zip.extractEntryTo(zipEntry, dir, false, true);
				        }
				    });

					msg = 'Upload success';
					if (ciId != null && platform != null && type === 'zip')
						compiler.package({method : 'package', projectId : projectId, ciId : ciId, platform : platform});
				} else {
					msg = 'Upload failed, no data';
				}
	        }
    		break;

    		case '/version':
    		{
    			finished = false;
    			var path = baseFolder + '/release/' + configFile;
    			getVersion(path, function(err, v){
					console.log('version for ' + projectId + ': ');
				    sendResponse(res, 200, v);
    			});
    		}
    		break;

    		case '/deploy':
		    {
		    	var src = baseFolder + '/ci/' + ciId + '/' + ciId + '.' + type;
		    	var dst = baseFolder + '/release/' + projectId + '.' + type;
		    	if (fs.existsSync(src)) {
		    		var srcConfig = baseFolder + '/ci/' + ciId + '/' + configFile;
					var dstConfig = baseFolder + '/release/'+ configFile;
					if (!fs.existsSync(dstConfig)) {
						deploy(src, dst, srcConfig, dstConfig);
						msg = 'deploy success';
					} else if (fs.existsSync(srcConfig)) {
						finished = false;
						getVersion(srcConfig, function(err, srcV){
							getVersion(dstConfig, function(err, dstV){
								console.log('comparing version: ' + srcV + ' ' + dstV);
								if (parseInt(srcV) > parseInt(dstV)) {
									deploy(src, dst, srcConfig, dstConfig);
									msg = 'deploy success';
								} else {
									status = 405;//TODO
									msg = 'deploy failed, ci target [' + ciId + '] version too low ci version: ' + srcV + ', current deployed version: ' + dstV;
								}
								sendResponse(res, status, msg);
							});
						});
					}
				} else {
					status = 404;
					msg = 'deploy failed, ci target [' + ciId + '] does not exist';
				}
		    }
		    break;

		    case '/download':
		    {
		    	finished = false;
		    	var filename;
		    	if (ciId != null) {
					filename = baseFolder + '/ci/' + ciId + '/' + ciId + '.' + type;
		    	} else {
		    		filename = baseFolder + '/release/' + projectId + '.' + type;
		    	}
		    	
		    	fs.readFile(filename, "binary", function(err, file) {
					if(err) {        
						status = 404;
						msg = 'download failed: ' + filename;
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
					
					console.log((new Date()) + ' ' + msg + ': ' + projectId);
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
}).listen(8888);

console.log("mCloud Package Manager http server listening at 8888");

// start compiler server
compiler.start();

function sendResponse(res, status, msg) {
	res.writeHead(status, {
	    "Content-Type": "text/plain;charset=utf-8"
	});
	console.log((new Date()) + ' ' + msg);
	res.end(msg);
}

function getVersion(path, callback) {
	var parser = new xml2js.Parser();
	fs.readFile(path, function(err, data) {
	    parser.parseString(data, function (err, result) {
	    	var v;
	    	if (result == null) {
	    		v = '-1';
	    	} else {
		        v = result['tns:Project']['$'].versionCode;
		    }
	    	callback(err, v);
	    });
	});
}

function deploy(src, dst, srcConfig, dstConfig) {
	// delete file if exists already
    if (fs.existsSync(dst)) {
	    fs.unlinkSync(dst);
	}
	fs.createReadStream(src).pipe(fs.createWriteStream(dst));
	fs.createReadStream(srcConfig).pipe(fs.createWriteStream(dstConfig));
}
