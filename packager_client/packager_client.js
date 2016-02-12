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
    var taskPath = "" + task.projectId + '_' + task.ciId;
    if (!fs.existsSync(taskPath)) {
        fs.mkdirSync(taskPath);
        // fs.mkdirSync(taskPath + '/out');
    }

    var jsPath = 'android/mml';
    var request = http.get('http://' + HOST + ':8888/download?projectId='+task.projectId+'&ci='+task.ciId, function(res) {
        if (res.statusCode == 404) {
            res.setEncoding('utf8');
            res.on('data', function (chunk) {
                console.log('Download Error: ' + chunk);
            });
            finishTask(task);
        } else {
            var file = fs.createWriteStream(jsPath + "/MMLProject.zip");
            res.pipe(file);
        }

        res.on('end', function(){
            console.log('download finished. start native packaging');

            // TODO
            nativePackage();
        });
    });

    function nativePackage() {
        var cmd = 'xcodebuild -scheme eCare archive -archivePath ' + taskPath + '/mcloud.xcarchive';
        var child = exec(cmd, function (error, stdout, stderr) {
            sys.print('stdout: ' + stdout);
            sys.print('stderr: ' + stderr);

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
                upload();
            } else {
                console.log('exec error: ' + error);
                finishTask(task);
            }
            
        });
    }

    function upload() {
        finishTask(task);
    }
}

client.connect('ws://' + HOST + ':8889/', 'play_protocol');