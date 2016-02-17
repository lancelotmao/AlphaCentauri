var WebSocketServer = require('websocket').server;
var http = require('http');
 
var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
server.listen(8082, function() {
    console.log((new Date()) + ' Server is listening on port 8082');
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

function generateUUID(){
    var d = new Date().getTime();
    var uuid = 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
        var r = (d + Math.random()*16)%16 | 0;
        d = Math.floor(d/16);
        return (c=='x' ? r : (r&0x3|0x8)).toString(16);
    });
    return uuid;
}

// phones
var clients = [];

// ide user
var ideClients = [];

// a temp array storing currently serving phones
// removed after preview generation
var serving = [];

wsServer.on('request', function(request) {
    if (!originIsAllowed(request.origin) 
      || request.requestedProtocols.indexOf('play_protocol') === -1) {
      // Make sure we only accept requests from an allowed origin 
      request.reject();
      console.log((new Date()) + ' Connection from origin ' + request.origin + ' rejected.');
      return;
    }

    // firstly we save every connection to ide client
    // after we receive register message from cell phone
    // we will remove from ide client. By doing so, we avoid
    // ide sending extra information identify itself
    var connection = request.accept('play_protocol', request.origin);
    ideClients.push({'uuid' : generateUUID(), 'connection' : connection});
    
    console.log((new Date()) + ' Connection accepted ' + connection.remoteAddress);
    connection.on('message', function(message) {
        if (message.type == 'utf8') {
          var msg = JSON.parse(message.utf8Data.toString());
          if (msg.method == null) {
            var emsg = 'invalid method';
            connection.sendUTF(emsg);
            return;
          }
          console.log('method = ' + msg["method"]);
          if (msg["method"] == 'register') {
            clients.push({'device' : msg["device"], 'connection' : connection});
            connection.sendUTF('register success');
            console.log('' + msg["device"] + ' registered');
            for (var i = 0;i < ideClients.length;++i) {
              var c = ideClients[i];
              if (c.connection == connection) {
                console.log('remove client from ideClients');
                ideClients.splice(i, 1);
                break;
              }
            }
          } else if (msg["method"] == 'preview') {
            // find sender
            var sender;
            for (var i = 0;i < ideClients.length;++i) {
              var c = ideClients[i];
              if (c.connection == connection) {
                sender = c;
                break;
              }
            }

            executePreview(sender, msg, null);
          } else if (msg["method"] == 'phoneList'){
            var result = [];
            for (var i = 0;i < clients.length;++i) {
              result.push({model : clients[i].device});
            }
            connection.sendUTF(JSON.stringify(result));
          } else {
            boardcast(message, msg["user"]);  
          }
        } else {
          for (var i = 0;i < serving.length;++i) {
            var c = serving[i];
            if (c.handler.connection === connection) {
              console.log('Got preview data for: ' + c.sender.uuid);
              c.sender.connection.sendBytes(message.binaryData);

              // serving complete
              serving.splice(i, 1);
              c.handler.serving = false;
              break;
            }
          }
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

        for (var i = 0;i < ideClients.length;++i) {
          if (ideClients[i].connection === connection) {
            ideClients.splice(i, 1);
            break;
          }
        }

        for (var i = 0;i < serving.length;++i) {
          if (serving[i].connection === connection) {
            serving.splice(i, 1);
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

    function executePreview(sender, msg, timer) {
      var device = msg.device;
      var available;
      for (var i = 0;i < clients.length;++i) {
        var c = clients[i];
        if (c.device.toUpperCase() == device.toUpperCase() && !c.serving) {
          c.serving = true;
          available = c;
          clearTimeout(timer);
          serving.push({'sender':sender,'handler':c});
          c.connection.sendUTF(JSON.stringify(msg));
          console.log((new Date()) + 'sent: preview request FROM ' + sender.uuid + ' TO ' + c.connection.remoteAddress + ' [' + (i+1) + ']');
          break;
        }
      }

      // if no phone available, wait and retry
      if (!available && senderValid(sender)) {
        console.log((new Date()) + ' no phone available');
        var timer = setTimeout(function(){
          executePreview(sender, msg, timer);
        }, 1000);
      }
    }

    function senderValid(sender) {
      for (var i = 0;i < ideClients.length;++i) {
        if (ideClients[i] === sender) {
          return true;
        }
      }
      return false;
    }
});