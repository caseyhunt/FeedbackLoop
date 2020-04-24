// NEOPIXELS
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    13

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 12

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// add Servo library (standard library)
#include <Servo.h>

// define servos
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

// Default servo position in degrees
int servoPos = 0;


// setup() function -- runs once at startup --------------------------------

void setup() {

// define servo signal inputs (DIGITAL PWM 3, 5, 6, 9
servo1.attach(3);
servo2.attach(5);
servo3.attach(7);
servo4.attach(9);

// servoScan();
// servo setup for website dropdown choices
// box1 = past, younger, current, future
// box2 = stronger, smarter, braver, wiser
// box3 = dedicated, creative, confident, hard-working
// box4 = admirable, compassionate, industrious, loving

// need to find out the format of how value gets passed from website to arduino.

String box1 = "future"; // _POST("dropdown1");
String box2 = "wiser"; // _POST("dropdown2");
String box3 = "hard-working"; // _POST("dropdown3");
String box4 = "loving"; // _POST("dropdown4");

Serial.println(box1);

choiceServo1(box1);
choiceServo2(box2);
choiceServo3(box3);
choiceServo4(box4);

// future...create random selections from 4 separate arrays
String array1 = "past, younger, current, future";
String array2 = "stronger, smarter, braver, wiser";
String array3 = "dedicated, creative, confident, hard-working";
String array4 = "admirable, compassionate, industrious, loving";



  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Fill along the length of the strip in various colors...
  // colorWipe(strip.Color(255,   0,   0), 100); // Red
  // colorWipe(strip.Color(  0, 255,   0), 100); // Green
  // colorWipe(strip.Color(  0,   0, 255), 100); // Blue

  // colorWipe(strip.Color( 20, 20, 255), 100); // blue
  // colorWipe(strip.Color( 255, 0, 5), 100); // red
  // colorWipe(strip.Color( 186, 81, 223), 100); // magenta
  // colorWipe(strip.Color( 7, 203, 227), 100); // cyan

  color1(strip.Color( 20, 20, 255));
  color2(strip.Color( 255, 0, 5));
  color3(strip.Color( 186, 81, 223));
  color4(strip.Color( 7, 203, 227));
  

// LED 1,2,3    = blue #2A42EA rgb(42, 66, 234)
  // LED 4,5,6    = red #FF3220 rgb(255, 50, 32)
  // LED 7,8,9    = magenta #BA51DF rgb(186, 81, 223)
  // LED 10,11,12 = cyan #07CBE3 rgb(7, 203, 227)
   
}


// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}


// fill 0, 1, 2 with color1
void color1(uint32_t color) {
  strip.setPixelColor(0, color);
  strip.setPixelColor(1, color);
  strip.setPixelColor(2, color);
  strip.show();

}



// fill 3, 4, 5 with color2
void color2(uint32_t color) {
  strip.setPixelColor(3, color);
  strip.setPixelColor(4, color);
  strip.setPixelColor(5, color);
  strip.show();
}


// fill 6, 7, 8 with color3
void color3(uint32_t color) {
  strip.setPixelColor(6, color);
  strip.setPixelColor(7, color);
  strip.setPixelColor(8, color);
  strip.show();
}


// fill 9, 10, 11 with color4
void color4(uint32_t color) {
  strip.setPixelColor(9, color);
  strip.setPixelColor(10, color);
  strip.setPixelColor(11, color);
  strip.show();
}

// servo setup

void servoScan() {
// scan servos from 0 to 180 degrees
  for(servoPos = 0; servoPos < 180; servoPos++) {
    servo1.write(servoPos);
    servo2.write(servoPos);
    servo3.write(servoPos);
    servo4.write(servoPos);
    delay(100);
  }

  // scan back from 180 to 0 degrees
  for(servoPos = 180; servoPos > 0; servoPos--) {
    servo1.write(servoPos);
    servo2.write(servoPos);
    servo3.write(servoPos);
    servo4.write(servoPos);
    delay(100);
  }
}


void choiceServo1(String choice) {
  Serial.println("choiceServo1: " + choice);
  servoPos = 0;
  if(choice="past") {
    servoPos = 0;
  } else if(choice="younger") {
    servoPos = 90;
  } else if(choice="current") {
    servoPos = 180;
  } else if(choice="future") {
    servoPos = 270;
  }
  // end if
  servo1.write(servoPos);
}

void choiceServo2(String choice) {
  Serial.println("choiceServo2: " + choice);
  servoPos = 0;
  if(choice="stronger") {
    servoPos = 0;
  } else if(choice="smarter") {
    servoPos = 90;
  } else if(choice="braver") {
    servoPos = 180;
  } else if(choice="wiser") {
    servoPos = 270;
  }
  // end if
  servo2.write(servoPos);
}

void choiceServo3(String choice) {
  Serial.println("choiceServo3: " + choice);
  servoPos = 0;
  if(choice="dedicated") {
    servoPos = 0;
  } else if(choice="creative") {
    servoPos = 90;
  } else if(choice="confident") {
    servoPos = 180;
  } else if(choice="hard-working") {
    servoPos = 270;
  }
  // end if
  servo3.write(servoPos);
}


void choiceServo4(String choice) {
  Serial.println("choiceServo4: " + choice);
  servoPos = 0;
  if(choice="admirable") {
    servoPos = 0;
  } else if(choice="compassionate") {
    servoPos = 90;
  } else if(choice="industrious") {
    servoPos = 180;
  } else if(choice="loving") {
    servoPos = 270;
  }
  // end if
  servo4.write(servoPos);
}
