/*
 * test for socket
 */
var net = require('net');

var client = new net.Socket();
client.connect(5474, '127.0.0.1', function() {
	console.log('Connected');
	client.write('test1');
});

client.on('data', function(data) {
	console.log('Received: ' + data);
	//client.destroy(); // kill client after server's response
});

client.on('close', function() {
	console.log('Connection closed');
});