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

		    var filePath;
		    if (ciId !== undefined) {
		    	filePath = baseFolder + '/ci/' + ciId + '.zip';	
		    } else {
		    	filePath = baseFolder + '/release/' + projectId + '.zip';
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
        	fs.appendFile(filePath, postDataChunk, function() {
	        });
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
				msg = 'Upload success';
				if (ciId != null)
					compiler.package({method : 'package', projectId : projectId, ciId : ciId});
	        }
    		break;

    		case '/version':
    		{
    			finished = false;
    			var path = baseFolder + '/release/' + configFile;
    			var parser = new xml2js.Parser();
				fs.readFile(path, function(err, data) {
				    parser.parseString(data, function (err, result) {
				        var v = result['tns:Project']['$'].versionCode;
				        sendResponse(res, 200, v);
				    });
				});
    		}
    		break;

    		case '/deploy':
		    {
		    	var src = baseFolder + '/ci/' + ciId + '.zip';
		    	if (fs.existsSync(src)) {
		    		// finished = false;
					var dst = baseFolder + '/release/' + projectId + '.zip';
			    	// delete file if exists already
				    if (fs.existsSync(dst)) {
					    fs.unlinkSync(dst);
					}
					fs.createReadStream(src).pipe(fs.createWriteStream(dst));

					// reading archives
				    var zip = new AdmZip(src);
				    var zipEntries = zip.getEntries(); // an array of ZipEntry records

				    zipEntries.forEach(function(zipEntry) {
				        if (zipEntry.name === configFile) {
				            // console.log(zipEntry.toString('utf8'));
				            zip.extractEntryTo(zipEntry, baseFolder + '/release/', false, true);
				            msg = 'deploy success';
				        }
				    });
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
					filename = baseFolder + '/ci/' + ciId + '.zip';
		    	} else {
		    		filename = baseFolder + '/release/' + projectId + '.zip';
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
