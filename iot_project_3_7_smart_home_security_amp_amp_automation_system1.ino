#include <Servo.h>

Servo myServo;

// Ultrasonic
const int trigPin = 7;
const int echoPin = 6;

// Buzzer
const int buzzerPin = 8;

// Servo
const int servoPin = 9;

// LEDs
const int lightLED = 12;
const int tempLED = 13;
const int securityLED = 11;

// Sensors
const int ldrPin = A0;
const int tempPin = A1;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(lightLED, OUTPUT);
  pinMode(tempLED, OUTPUT);
  pinMode(securityLED, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.begin(9600);
}

void loop() {

  // ---------- Ultrasonic ----------
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;


  // ---------- LDR ----------
  int lightValue = analogRead(ldrPin);


  // ---------- Temperature ----------
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;


  // ---------- Serial Monitor ----------
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Light: ");
  Serial.print(lightValue);
  Serial.print(" | Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");


  // ---------- Security ----------
  if (distance < 10) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(securityLED, HIGH);
    myServo.write(90);
  } 
  else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(securityLED, LOW);
    myServo.write(0);
  }


  // ---------- Light ----------
  if (lightValue < 500) {
    digitalWrite(lightLED, HIGH);
  } 
  else {
    digitalWrite(lightLED, LOW);
  }


  // ---------- Temperature ----------
  if (temperatureC > 30) {
    digitalWrite(tempLED, HIGH);
  } 
  else {
    digitalWrite(tempLED, LOW);
  }

  delay(300);
}