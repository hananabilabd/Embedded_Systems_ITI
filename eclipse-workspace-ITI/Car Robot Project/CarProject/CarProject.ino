
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
int pwm3 = 3; 
int pwm5 = 5;
int pwm6 = 6;
int pwm9 = 9;  
int val = 0;         // variable to store the read value
int state = 0;
void setup()
{
  pinMode(pwm3, OUTPUT);   // sets the pin as output
  pinMode(pwm5, OUTPUT);   // sets the pin as output
  pinMode(pwm6, OUTPUT);   // sets the pin as output
  pinMode(pwm9, OUTPUT);   // sets the pin as output
  //Serial.begin(38400); // Default communication rate of the Bluetooth module
  //Serial.begin(57600);
  

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

}


void loop() {
  if(mySerial.available() > 0){ // Checks whether data is comming from the serial port
    state = mySerial.read(); // Reads the data from the serial port
 }
 if (state == 0) {
  analogWrite(pwm3, 0);// analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(pwm5, 0);
  analogWrite(pwm6, 0);
  analogWrite(pwm9, 0);
 }
 else if (state == 1) {//forward
  analogWrite(pwm3, 0);
  analogWrite(pwm5, 255);
  analogWrite(pwm6, 0);
  analogWrite(pwm9, 255);
  Serial.print("hii");          //Print Value inside data in Serial monitor
    Serial.print("\n"); 
 }
 else if (state == 2) {//backward
  analogWrite(pwm3, 255);
  analogWrite(pwm5, 0);
  analogWrite(pwm6, 255);
  analogWrite(pwm9, 0);
 }
 else if (state == 3) {//right
  analogWrite(pwm3, 0);
  analogWrite(pwm5,155);
  analogWrite(pwm6, 0);
  analogWrite(pwm9, 255);
 }
 else if (state == 4) {//left
 analogWrite(pwm3, 0);
  analogWrite(pwm5, 255);
  analogWrite(pwm6, 0);
  analogWrite(pwm9,155);
 } 
}
