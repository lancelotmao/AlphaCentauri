var WebSocketClient = require('websocket').client; 
var client = new WebSocketClient();
 
var updateMsg = {
    method : 'preview',
    device : 'iPhone6',
};

client.on('connectFailed', function(error) {
    console.log('Connect Error: ' + error.toString());
});
 
client.on('connect', function(connection) {
    var timer;
    console.log('WebSocket Client Connected');
    connection.on('error', function(error) {
        console.log("Connection Error: " + error.toString());
    });
    connection.on('close', function() {
        clearInterval(timer);
        console.log('echo-protocol Connection Closed');
    });
    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log("Received: '" + message.utf8Data + "'");
        } else {
            console.log('Received binary');
            var fs = require('fs');
            fs.writeFile('images/image' + randomColor() + '.png', message.binaryData, function (err) {
                if (err) throw err;
                console.log('It\'s saved!');
            });
        }
    });

    timer = setInterval(function(){
      updateMsg.data = 'PreviewMCLOUD!@#<Page><Body><SmartLayout width=\"match_parent\" height=\"match_parent\" background=\"#' + randomColor() + '\"> </SmartLayout></Body></Page>MCLOUD!@#var x=1;'
        connection.sendUTF(JSON.stringify(updateMsg));
    }, 1000);
    
    function randomColor() {
        return ''+Math.floor(Math.random()*16777215).toString(16);
    }
});
 
// client.connect('ws://10.75.69.49:8082/', 'play_protocol');
client.connect('ws://127.0.0.1:8082/', 'play_protocol');