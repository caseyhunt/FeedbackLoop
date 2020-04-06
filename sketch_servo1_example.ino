#include<Servo.h>
Servo sv_feedbackloop1;
int servo_position = 45;
int phrase1 = 0;
int phrase2 = 60;
int phrase3 = 120;
int phrase4 = 180;
int phrase5 = 240;
int phrase6 = 300;

void setup() {
  // put your setup code here, to run once:
  sv_feedbackloop1.attach(9); // servo signal pin
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A1);
  if (value > 800 && value < 1000) {
    Serial.println("Button1");
    sv_feedbackloop1.write(phrase1);
  } else if (value > 750 && value < 800) {
    Serial.println("Button2");
   sv_feedbackloop1.write(phrase2);    
  } else if (value > 650 && value < 750) {
    Serial.println("Button3");
    sv_feedbackloop1.write(phrase3);
  } else if (value > 480 && value < 650) {
    Serial.println("Button4");
   sv_feedbackloop1.write(phrase4);    
  } else if (value < 480) {
    Serial.println("Button5");
   sv_feedbackloop1.write(phrase5);
  }
  delay(1000);
}
