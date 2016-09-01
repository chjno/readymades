var capture;
var ctracker;
var videoInput;
var coords;
var butt;

function preload() {
  butt = loadImage('butt.png');
}

function setup() {
  createCanvas(640, 480);
  capture = createCapture(VIDEO);
  capture.id('inputVideo');
  capture.size(640, 480);
  capture.hide();

  videoInput = document.getElementById('inputVideo');

  ctracker = new clm.tracker();
  ctracker.init(pModel);
  ctracker.start(videoInput);

  imageMode(CENTER);
}

function draw() {
  background(0);
  push();
  translate(capture.width, 0);
  scale(-1, 1);
  image(capture, capture.width/2, capture.height/2);

  coords = ctracker.getCurrentPosition();

  // for (var i = 0; i < coords.length; i++){

  //   ellipse(coords[i][0], coords[i][1], 5, 5);
  // }

  if (coords) {
    var faceHeight = coords[7][1] - coords[20][1];
    // ellipse(coords[62][0], coords[62][1], 5, 5);
    if (faceHeight > 100){
      image(butt, coords[62][0], coords[62][1]);
    }
  }

  pop();


}