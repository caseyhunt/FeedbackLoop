
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

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

// define servos
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

// Default servo position in degrees
int servoPos1 = 0;
int servoPos2 = 0;
int servoPos3 = 0;
int servoPos4 = 0;


char receivedChar;
boolean newData = false;


void setup() {
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
  
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(7);
  servo4.attach(9);
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(10); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  recvOneChar();
 showNewData();
 controlServo2();
 controlServo1();
 controlServo3();
 controlServo4();

  delay(15);                           // waits for the servo to get there


    strip.setPixelColor(1, strip.Color(255, 255, 255));
    strip.setPixelColor(4, strip.Color(255, 255, 255));
    strip.setPixelColor(7, strip.Color(255, 255, 255));
    strip.setPixelColor(10, strip.Color(255, 255, 255));
  
strip.show();

//  color1(strip.Color( 20, 20, 255));
//  color2(strip.Color( 255, 0, 5));
//  color3(strip.Color( 186, 81, 223));
//  color4(strip.Color( 7, 203, 227));

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
//  strip.setPixelColor(3, color);
  strip.setPixelColor(4, color);
//  strip.setPixelColor(5, color);
//  strip.show();
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


void recvOneChar() {
 if (Serial.available() > 0) {
 receivedChar = Serial.read();
 newData = true;
 }
}

void showNewData() {
 if (newData == true) {
 Serial.print("This just in ... ");
 Serial.println(receivedChar);
 newData = false;
 }
}

void controlServo2() {
  
  if (receivedChar == 'e'){
      Serial.println("it's a e!");
  servoPos2=0;    // turn the LED off by making the voltage LOW
    servo2.write(servoPos2);
  delay(1000);      
    }

    if (receivedChar == 'f'){
      Serial.println("it's a f!");
  servoPos2=60;    // turn the LED off by making the voltage LOW
    servo2.write(servoPos2);
  delay(1000);      
    }

     if (receivedChar == 'g'){
      Serial.println("it's a g!");
  servoPos2=120;    // turn the LED off by making the voltage LOW
    servo2.write(servoPos2);
  delay(1000);      
    }

        if (receivedChar == 'h'){
      Serial.println("it's a h!");
  servoPos2=180;    // turn the LED off by making the voltage LOW
    servo2.write(servoPos2);
  delay(1000);      
    }
  }

void controlServo1() {
  
  if (receivedChar == 'a'){
      Serial.println("it's a a!");
  servoPos1=0;    // turn the LED off by making the voltage LOW
    servo1.write(servoPos1);
  delay(1000);      
    }

    if (receivedChar == 'b'){
      Serial.println("it's a b!");
  servoPos1=60;    // turn the LED off by making the voltage LOW
    servo1.write(servoPos1);
  delay(1000);      
    }

     if (receivedChar == 'c'){
      Serial.println("it's a c!");
  servoPos1=120;    // turn the LED off by making the voltage LOW
    servo1.write(servoPos1);
  delay(1000);      
    }

        if (receivedChar == 'd'){
      Serial.println("it's a d!");
  servoPos1=180;    // turn the LED off by making the voltage LOW
    servo1.write(servoPos1);
  delay(1000);      
    }
  }


void controlServo3() {
  
  if (receivedChar == 'i'){
      Serial.println("it's a i!");
  servoPos3=0;    // turn the LED off by making the voltage LOW
    servo3.write(servoPos3);
  delay(1000);      
    }

  if (receivedChar == 'j'){
      Serial.println("it's a j!");
  servoPos3=60;    // turn the LED off by making the voltage LOW
    servo3.write(servoPos3);
  delay(1000);      
    }

     if (receivedChar == 'k'){
      Serial.println("it's a k!");
  servoPos3=140;    // turn the LED off by making the voltage LOW
    servo3.write(servoPos3);
  delay(1000);      
    }

        if (receivedChar == 'l'){
      Serial.println("it's a l!");
  servoPos3=180;    // turn the LED off by making the voltage LOW
    servo3.write(servoPos3);
  delay(1000);      
    }
  }

  void controlServo4() {
  
  if (receivedChar == 'm'){
      Serial.println("it's a m!");
  servoPos4=0;    // turn the LED off by making the voltage LOW
    servo4.write(servoPos4);
  delay(1000);      
    }

    if (receivedChar == 'n'){
      Serial.println("it's a n!");
  servoPos4=60;    // turn the LED off by making the voltage LOW
    servo4.write(servoPos4);
  delay(1000);      
    }

     if (receivedChar == 'o'){
      Serial.println("it's a o!");
  servoPos4=120;    // turn the LED off by making the voltage LOW
    servo4.write(servoPos4);
  delay(1000);      
    }

        if (receivedChar == 'p'){
      Serial.println("it's a p!");
  servoPos4=180;    // turn the LED off by making the voltage LOW
    servo4.write(servoPos4);
  delay(1000);      
    }
  }
void blinkOnA() {
  if (receivedChar == 'a'){
      Serial.println("it's a A!");
  servoPos2=0;    // turn the LED off by making the voltage LOW
    servo2.write(servoPos2);
  delay(1000);      
    }
  }
//
//void offOnA() {
//  if (receivedChar == 'a'){
//      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000); 
//    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);     
//    Serial.println("it's an A!");
//    delay(1000);
//  }
//}
