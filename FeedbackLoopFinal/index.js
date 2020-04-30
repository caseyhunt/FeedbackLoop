


//setting up serialport!
const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')
const port = new SerialPort('/dev/ttyACM0', {
  baudRade: 9600
})


// Switches the port into "flowing mode"
port.on('data', function (data) {
  console.log('Data:', data)
})

// Pipe the data into another stream (like a parser or standard out)
const parser = port.pipe(new Readline({ delimiter: '\r\n' }))
parser.on('data', console.log)



port.write('a', function(err) {
  if (err) {
    return console.log('Error on write: ', err.message)
  }
  console.log('message written')
})

// Open errors will be emitted as an error event
port.on('error', function(err) {
  console.log('Error: ', err.message)
})

//setting up websocket!
const express = require('express')
const app = express()
var http = require('http').createServer(app);
var io = require('socket.io')(http);


var viewCount = 0;
var connectedUsers = 0;


app.use(express.static(__dirname));

app.get('/', function(req,res){


  res.sendFile(__dirname + '/index.html');
});


  io.on('connection', function(socket){
      console.log('a user connected');
      viewCount ++;
      connectedUsers ++;
      socket.emit("user connected", viewCount, connectedUsers);
      console.log(viewCount);


      socket.on('disconnect', function(){
        connectedUsers --;
        console.log('user disconnected');
        console.log('connected users= ', connectedUsers);
        // io.emit("user disconnected");
        io.emit('disconnect');
      });

      socket.on('blink', function(){
        port.write('a', function(err) {
          if (err) {
            return console.log('Error on write: ', err.message)
          }
        console.log('message written')
      })
      console.log('blinking');
    });
    socket.on('stopblink', function(){
      port.write('b', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log('message written')
      })
      console.log('stop blinking');
    });



  socket.on('younger', function(){
    port.write('a', function(err) {
      if (err) {
        return console.log('Error on write: ', err.message)
      }
    console.log('message written')
  });
  console.log('younger');
});

socket.on('present', function(){
  port.write('b', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('present');
});

socket.on('future', function(){
  port.write('c', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('future');
});

socket.on('wiser', function(){
  port.write('e', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('wiser');
});

socket.on('smarter', function(){
  port.write('f', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('smarter');
});

socket.on('braver', function(){
  port.write('g', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('braver');
});

socket.on('dedicated', function(){
  port.write('i', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('dedicated');
});

socket.on('creative', function(){
  port.write('j', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('creative');
});

socket.on('loving', function(){
  port.write('k', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('loving');
});

socket.on('confident', function(){
  port.write('m', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('confident');
});

socket.on('admirable', function(){
  port.write('p', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('admirable');
});

socket.on('industrious', function(){
  port.write('o', function(err) {
    if (err) {
      return console.log('Error on write: ', err.message)
    }
  console.log('message written')
});
console.log('industrious');
});

  });

  http.listen(65510, function(){
    console.log('listening on *:65510');
  });
