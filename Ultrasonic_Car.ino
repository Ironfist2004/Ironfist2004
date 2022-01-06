#include <Servo.h>

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
const int servopin = 8;
Servo Servo1;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(pingPin, OUTPUT);
   pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
   pinMode(echoPin, INPUT);
   Servo1.attach(servoPin);
}

void loop() {
   long duration, inches;
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   Serial.print(inches);
   Serial.print("in");
   if (inches > 50) {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(1000);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
   }
   else {
    Servo1.write(40);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(1000);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
   }
   Serial.println();
   delay(100);
   
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
