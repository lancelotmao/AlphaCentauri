var WebSocketServer = require('websocket').server;
var http = require('http');
 
var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
server.listen(8080, function() {
    console.log((new Date()) + ' Server is listening on port 8080');
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

var clients = [];

wsServer.on('request', function(request) {
    if (!originIsAllowed(request.origin) 
      || request.requestedProtocols.indexOf('play_protocol') === -1) {
      // Make sure we only accept requests from an allowed origin 
      request.reject();
      console.log((new Date()) + ' Connection from origin ' + request.origin + ' rejected.');
      return;
    }

    var connection = request.accept('play_protocol', request.origin);
    
    console.log((new Date()) + ' Connection accepted ' + connection.remoteAddress);
    connection.on('message', function(message) {
        var msg = JSON.parse(message.utf8Data.toString());
        console.log('method = ' + msg["method"] + ' user = ' + msg["user"]);
        if (msg["method"] == 'register') {
          clients.push({'user' : msg["user"], 'connection' : connection});
          connection.sendUTF('register success');
          console.log('' + msg["user"] + ' registered');
        } else if (msg["method"] == 'command') {
          var command = msg.data.split(' ');
          if (command.length <= 2) {
            connection.sendUTF('invalid command');
            return;
          }
          var cmd = command[0];
          var action = command[1];
          var p = command[2];

          if (action === 'install') {
            var fs = require('fs');
            var path = "./mcloud_modules/" + p + '.js';
            if (!fs.existsSync(path)) {
              connection.sendUTF('file not found: ' + path);
              return;
            }
            var jsCode = fs.readFileSync(path, "utf8");
            connection.sendUTF(jsCode);
            console.log('install successfull for \"' + p + '\"');
          }
        } else {
          boardcast(message, msg["user"]);  
        }
    });
    connection.on('close', function(reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
        for (var i = 0;i < clients.length;++i) {
          if (clients[i] === connection) {
            clients.splice(i, 1);
            break;
          }
        }
    });

    function boardcast(message, user) {
      for (var i = 0;i < clients.length;++i) {
        var c = clients[i];
        if (c.user.toUpperCase() == user.toUpperCase()) {
          c.connection.sendUTF(message.utf8Data);
          console.log((new Date()) + 'sent: ' + message.utf8Data 
            + ' TO ' + c.connection.remoteAddress + ' [' + (i+1) + ']');
        }
      }
    }
});