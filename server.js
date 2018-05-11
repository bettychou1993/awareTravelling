var express = require('express'); // web server application
var app = express(); // webapp
var http = require('http').Server(app); // connects http library to server
var io = require('socket.io')(http); // connect websocket library to server
var serverPort = 8001;
var serialPort = require('serialport'); // serial library
var readLine = serialPort.parsers.Readline; // read serial data as lines
var Blynk = require('blynk-library');
var AUTH = '216fe6e9f7d04cf88a0b6355c6934c81'; //blynk notification
var blynk = new Blynk.Blynk(AUTH);
var v9 = new blynk.VirtualPin(9);
var term = new blynk.WidgetTerminal(3);
var EventEmitter = require('events').EventEmitter;
var eventEmitterInfinity = new EventEmitter();
var y = require('events').EventEmitter.defaultMaxListeners = 10000;

//---------------------- WEBAPP SERVER SETUP ---------------------------------//
// use express to create the simple webapp
app.use(express.static('public')); // find pages in public directory

// start the server and say what port it is on
http.listen(serverPort, function() {
  console.log('listening on *:%s', serverPort);
});
//----------------------------------------------------------------------------//
//---------------------- SERIAL COMMUNICATION --------------------------------//
// start the serial port connection and read on newlines
const serial = new serialPort('/dev/ttyUSB0', {
 baudRate:9600

});
const parser = new readLine({
  delimiter: '\r\n'
});

// Read data that is available on the serial port and send it to the websocket
serial.pipe(parser);
parser.on('data', function(data) { // on data from the arduino
    console.log(data);
    var transmitData = data;
    io.emit('new-pos',transmitData); 

    if (data >= 350){
    v9.on('read', function(){
    v9.write(new Date().getSeconds());
    blynk.notify("hey, skip the Cornell Tech now!");
});}

});

// this is the websocket event handler and say if someone connects
// as long as someone is connected, listen for messages
io.on('connect', function(socket) {
  console.log('a user connected');
  io.emit('reset'); // call reset to make sure the website is clean

// if you get the 'disconnect' message, say the user disconnected
  io.on('disconnect', function() {
    console.log('user disconnected');
  });
});

const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', function connection(ws) {
  ws.on('message', function incoming(message) {
    console.log('received: %s', message);
  });

  ws.send('something');
});
