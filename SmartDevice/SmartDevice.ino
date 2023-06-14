// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 53

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   * When temp goes above a set number the air conditioning turns on
   * @params none 
   * @retune none
   */
   
  void airConditioning() { 
    int speedValue = 255; // Can be 0-255.
digitalWrite(M1,HIGH);
analogWrite(E1, speedValue);   //PWM Speed Control
  }
   
  
}

/*
 *when door bell is pressed ring door bell 
 *@params none
 *@retune none
 */

 void doorBell() {
  int crashSensorValue = digitalRead(crashSensor);
  tone(piezoPin, 1000); // Send 1KHz sound signal...
delay(100);
noTone(piezoPin);
 }

 /*
  * Lighting system set to turn off and on depending on the time
  * @params none
  * @return none
  */

  void lightControl() {
    int pirValue = digitalRead (pirSensor);
    if (pirSensorValue == HIGH){
    digitalWrite(ledRed, HIGH);
    }else{
    digitalWrite(ledRed, LOW);
    }

 /*
  * Servo motor set to open the door when  button is used
  * @params none
  * @return none
  */

  void doorControl() {
    digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
long duration = pulseIn(echoPin, HIGH);
// Calculating the distance
int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

// Servo position values range from 0-180
int servoPos = 100;
myservo.write(servoPos);
  }
    
  }
