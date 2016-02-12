
var http = require('http');
var url = require("url");
var fs = require('fs');
var AdmZip = require('adm-zip');
var xml2js = require('xml2js');

var clients = [];
var configFile = "projectconfig.pjt";

var WebSocketServer = require('websocket').server;
 
var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
 
wsServer = new WebSocketServer({
    httpServer: server,
    // You should not use autoAcceptConnections for production 
    // applications, as it defeats all standard cross-origin protection 
    // facilities built into the protocol and the browser.  You should 
    // *always* verify the connection's origin and decide whether or not 
    // to accept it. 
    autoAcceptConnections: false
});
 
function originIsAllowed(origin) {
	// put logic here to detect whether the specified origin is allowed. 
	return true;
}

wsServer.on('request', function(request) {
    if (!originIsAllowed(request.origin) || request.requestedProtocols.indexOf('play_protocol') === -1) {
		// Make sure we only accept requests from an allowed origin 
		request.reject();
		console.log((new Date()) + ' Connection from origin ' + request.origin + ' rejected.');
		return;
    }

    var connection = request.accept('play_protocol', request.origin);
    clients.push({connection : connection, taskNumber : 0});
    
    console.log((new Date()) + ' Connection accepted ' + connection.remoteAddress);
    connection.on('message', function(message) {
        var msg = JSON.parse(message.utf8Data.toString());
        console.log((new Date()) + ' msg = ' + JSON.stringify(msg));
        if (msg["method"] == 'done') {
        	finishPackage(connection);
        }
    });

    connection.on('close', function(reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
        for (var i = 0;i < clients.length;++i) {
			if (clients[i].connection === connection) {
				clients.splice(i, 1);
				break;
			}
        }
    });

    function finishPackage(connection) {
    	for (var i = 0;i < clients.length;++i) {
			if (connection == clients[i].connection) {
				clients[i].taskNumber--;
				break;
			}
		}

		// print out client status
		console.log('Oh yeah, one packaging task is completed. let\'s see client status');
		for (var i = 0;i < clients.length;++i) {
			console.log('Client [' + (i+1) + ']: Task Number: ' + clients[i].taskNumber);
		}
    }
});

exports.start = function () {
	server.listen(10001, function() {
	    console.log('Packager Server is listening on port 10001');
	});
};

exports.package = function (param) {
	console.log('Selecting least busy package client...');
	var min = 1000000;
	var leastBusyClient;
	for (var i = 0;i < clients.length;++i) {
		if (clients[i].taskNumber < min) {
			min = clients[i].taskNumber;
			leastBusyClient = clients[i];
		}
	}

	if (leastBusyClient != null) {
		console.log('Found client and send package command');
		leastBusyClient.taskNumber++;
		leastBusyClient.connection.sendUTF(JSON.stringify(param));
	} else {
		console.log('ERROR! No packager client connected');
	}
}