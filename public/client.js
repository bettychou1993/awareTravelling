// See post: http://asmaloney.com/2014/01/code/creating-an-interactive-map-with-leaflet-and-openstreetmap/
//var test = 1000;


var map = L.map( 'map', {
  center: [40.755855, -73.95464],
  minZoom: 2,
  zoom: 15
})

L.tileLayer( 'http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
  attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a>',
  subdomains: ['a', 'b', 'c']
}).addTo( map )

var myURL = jQuery( 'script[src$="client.js"]' ).attr( 'src' ).replace( 'client.js', '' )

var myIcon = L.icon({
  iconUrl: myURL + 'images/pin24.png',
  iconRetinaUrl: myURL + 'images/pin48.png',
  iconSize: [29, 24],
  iconAnchor: [9, 21],
  popupAnchor: [0, -14]
})

for ( var i=0; i < markers.length; ++i )
{
 L.marker( [markers[i].lat, markers[i].lng], {icon: myIcon} )
  .bindPopup( '<a href="' + markers[i].url + '" target="_blank">' + markers[i].name + '</a>' )
  .addTo( map );
}



var socket = io();        // websocket to the server


    socket.on('new-pos', function(newPosition) { // handling new sensor values

	var threshold = newPosition;
	if(threshold>300){
L.marker([40.755803,-73.954862], {icon: myIcon}) .addTo(map)
          .bindPopup('<strong>Pollution Alert</strong><br>high alcohol levels. Skip this route for now!')
          .openPopup();	

}
    });







