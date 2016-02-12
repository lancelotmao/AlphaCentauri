var WebSocketClient = require('websocket').client; 
var client = new WebSocketClient();
 
var updateMsg = JSON.stringify({
    method : 'payload',
    user : 'test1',
    project : '47389279843',
    name : 'Home.pg', // page name
    data : '<Button &="${t : \'abc\'}"> <![CDATA[var x = 1;]]></Button>'
});

client.on('connectFailed', function(error) {
    console.log('Connect Error: ' + error.toString());
});
 
client.on('connect', function(connection) {
    console.log('WebSocket Client Connected');
    connection.on('error', function(error) {
        console.log("Connection Error: " + error.toString());
    });
    connection.on('close', function() {
        console.log('echo-protocol Connection Closed');
    });
    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log("Received: '" + message.utf8Data + "'");
        }
    });
    
    connection.sendUTF(updateMsg);
});
 
client.connect('ws://10.75.69.49:8080/', 'play_protocol');
// client.connect('ws://127.0.0.1:8080/', 'play_protocol');