var http = require('http');
var fs = require('fs');
var sys = require('sys');
var exec = require('child_process').exec;
var WebSocketClient = require('websocket').client; 
var client = new WebSocketClient();
var ws_connection;

var HOST = '127.0.0.1';
// var HOST = '10.75.69.49';

var updateMsg = JSON.stringify({
    method : 'done'
});

if (!fs.existsSync('out')) {
    fs.mkdirSync('out');
}

client.on('connectFailed', function(error) {
    console.log('Connect Error: ' + error.toString());
});
 
client.on('connect', function(connection) {
    console.log('Connected to server');
    ws_connection = connection
    connection.on('error', function(error) {
        console.log("Connection Error: " + error.toString());
    });
    connection.on('close', function() {
        console.log('echo-protocol Connection Closed');
    });
    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log("Received: '" + message.utf8Data + "'");
            addTask(JSON.parse(message.utf8Data));
        }
    });
});

var taskQueue = [];
var idle = true;
function addTask(param) {
    console.log('adding task: ' + JSON.stringify(param));
    taskQueue.push(param);
    if (idle) {
        startPackage();
    }
}

function startPackage() {
    if (taskQueue.length == 0) {
        idle = true;
    } else {
        idle = false;
        var task = taskQueue.splice(0, 1)[0];
        console.log('start packaging: ' + JSON.stringify(task));
        download(task);
    }
}

function finishTask(task) {
    ws_connection.sendUTF(updateMsg);
    startPackage();
}

function download(task) {
    var taskPath = "out/" + task.projectId + '_' + task.ciId;
    if (!fs.existsSync(taskPath)) {
        fs.mkdirSync(taskPath);
    }

    var jsDownloadPath = 'download/mml';
    var request = http.get('http://' + HOST + ':8888/download?projectId='+task.projectId+'&ci='+task.ciId, function(res) {
        if (res.statusCode == 404) {
            res.setEncoding('utf8');
            res.on('data', function (chunk) {
                console.log('Download Error: ' + chunk);
            });
            finishTask(task);
        } else {
            var file = fs.createWriteStream(jsDownloadPath + "/MMLProject.zip");
            res.pipe(file);
        }

        res.on('end', function(){
            if (task.platform == 'android') {
                console.log('download finished. start native packaging for android');
                 unzipDownloadedMML(jsDownloadPath + "/MMLProject.zip");
                nativePackageAndroid();
            } else {
                console.log('download finished. start native packaging for iOS');
                nativePackageiOS();
            }
        });
    });

    function unzipDownloadedMML(zipFilePath){
        var AdmZip = require('adm-zip');
        // reading archives
        var zip = new AdmZip("./" + zipFilePath);
        /*target path and override*/
        zip.extractAllTo("./android/mCloudPackageTemplate/mCloudPlay/src/main/assets/mml/216203276/", true);
    }

    function nativePackageAndroid() {
        // TODO

        var cmd = 'cd ./android/mCloudPackageTemplate';
        var child = exec(cmd, function (error, stdout, stderr) {
            sys.print('stdout: ' + stdout + '\n');
            sys.print('stderr: ' + stderr + '\n');

            if (error == null) {
                console.log('open android project.');
                var cmd = 'gradle build';
                var child = exec(cmd, function (error, stdout, stderr) {
                    sys.print('stdout: ' + stdout + '\n');
                    sys.print('stderr: ' + stderr + '\n');

                    if (error == null) {
                        console.log('gradle build success. exporting apk...');
                        exportAPK();
                    } else {
                        console.log('exec error: ' + error);
                        finishTask(task);
                    }
                });
            } else {
                console.log('exec error: ' + error);
                finishTask(task);
            }
        });
        
    }

    function nativePackageiOS() {
        var cmd = 'xcodebuild -project ./iOS/mcloud.xcodeproj -scheme eCare archive -archivePath ' + taskPath + '/mcloud.xcarchive';
        var child = exec(cmd, function (error, stdout, stderr) {
            sys.print('stdout: ' + stdout + '\n');
            sys.print('stderr: ' + stderr + '\n');

            if (error == null) {
                console.log('xcode build success. exporting ipa...');
                exportIPA();
            } else {
                console.log('exec error: ' + error);
                finishTask(task);
            }
        });
    }

    function exportIPA() {
        var ipaPath = taskPath + '/' + task.projectId + '.ipa';
        if (fs.existsSync(ipaPath)) {
            fs.unlinkSync(ipaPath);
        }
        var cmd = 'xcodebuild -exportArchive -exportPath "' + ipaPath + '" -archivePath "' + taskPath + '/mcloud.xcarchive" -exportFormat ipa -exportProvisioningProfile "Huawei"';
        var child = exec(cmd, function (error, stdout, stderr) {
            sys.print('stdout: ' + stdout);
            sys.print('stderr: ' + stderr);

            if (error == null) {
                console.log('xcode export success. uploading...');
                upload(ipaPath, 'ipa');
            } else {
                console.log('exec error: ' + error);
                finishTask(task);
            }
            
        });
    }

    function copy(src, dst) {
        //fs.createReadStream(src).pipe(fs.createWriteStream(dst));
        var rs = fs.createReadStream(src);
        var ws = fs.createWriteStream(dst);

        rs.on('data', function (chunk) {
            if (ws.write(chunk) === false) {
                rs.pause();
            }
        });

        rs.on('end', function () {
            ws.end();
        });

        ws.on('drain', function () {
            rs.resume();
        });
    }

    function exportAPK() {
        var apkSrcPath = 'android/mCloudPackageTemplate/mCloudPlay/build/outputs/apk' + '/' + 'mCloudPlay-debug.apk';
        upload(apkSrcPath, 'apk');
    }

    function upload(productPath, type) {
        var options = {
            host: HOST,
            port: 8888,
            path: '/upload?projectId=' + task.projectId + '&ci=' + task.ciId + '&type=' + type,
            method: 'POST'
        };

        var req = http.request(options, function(res) {
            console.log('STATUS: ' + res.statusCode);
              console.log('HEADERS: ' + JSON.stringify(res.headers));
            res.setEncoding('utf8');
            res.on('data', function (chunk) {
                console.log('BODY: ' + chunk);
            });
        });

        if (fs.existsSync(productPath)) {
            var stream = fs.createReadStream(productPath);
            stream.on('data', function(data) {
                req.write(data);
            });

            stream.on('end', function() {
                req.end();
                finishTask(task);
            });
        } else {
            finishTask(task);
        }
    }
}

client.connect('ws://' + HOST + ':8889/', 'play_protocol');