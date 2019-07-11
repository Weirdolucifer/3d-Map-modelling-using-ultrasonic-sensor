#include <Servo.h>
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int trigPin3 = 6;
const int echoPin3 = 7;
const int trigPin4 = 8;
const int echoPin4 = 9;
const int trigPin5 = 11;
const int echoPin5 = 12;
// Variables for the duration and the distance
long duration;
int distance;
int pdis;
int fdis1;
int fdis2;
int a1;
int a2;
double rad;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin4, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin4, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin5, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin5, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(10); // Defines on which pin is the servo motor attached
}
void loop() {
  pdis = 15;
  for(int i=65;i<=115;i++){
  myServo.write(i);


  distance = calculateDistance1();
  Serial.print(distance);
  
  distance = calculateDistance2();
  Serial.print(" "); 
  Serial.print(distance);
  distance = calculateDistance3();
  Serial.print(" "); 
  Serial.print(distance);
  distance = calculateDistance4();
  Serial.print(" "); 
  Serial.print(distance);

 
  Serial.print(" "); 
  Serial.print(i);
  Serial.print("\n");
  delay(30);
  }
  
  
  
  pdis = 15;
  for(int i=115;i>65;i--){
  myServo.write(i);

  distance = calculateDistance1();
  Serial.print(distance);
  
  distance = calculateDistance2();
  Serial.print(" "); 
  Serial.print(distance);
  distance = calculateDistance3();
  Serial.print(" "); 
  Serial.print(distance);
  distance = calculateDistance4();
  Serial.print(" "); 
  Serial.print(distance);

 
  Serial.print(" "); 
  Serial.print(i);
  Serial.print("\n"); 
  delay(30);
  }

 
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance1(){

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

int calculateDistance2(){

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

int calculateDistance3(){

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

int calculateDistance4(){

  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration = pulseIn(echoPin4, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
int calculateDistance5(){

  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);
  duration = pulseIn(echoPin5, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
