#include <vector>
#include <cmath>
using namespace std;

//wheel circumference = 12.566 cm per rev
//tweak timeTol so that motor count is accurate

//motor driver
int ain2Pin = 0;
int ain1Pin = 1;
int pwmaPin = 3;
int interrupt_pin = 4;
int sensorPin = 5;
//int analogPin = 20;

//estimate position
int motorCount = 0;
int prevTime = 0;
int currTime = 0;
int timeTol = 50;

//calculate angle
int rref = 100;
int rread = 100;

//calculate velocity
vector<double> verror;
double vref = 2.5;
double vread = 0.0;
double esum = 0.0;
int vrunning = 70;

void my_isr(){
  currTime = millis();
  if(currTime - prevTime > timeTol){
    motorCount++;
    Serial.print(motorCount);
    Serial.print(" Interrupts, ");
    Serial.print(motorCount/12.0);
    Serial.println(" Rotations (according to encoder)");
    //vread is the angular velocity given by motor encoders (1/12 of a rotation per change in time)
    vread = (1.0/12.0)/((currTime-prevTime)/1000.0); //not accurate rn
    verror.push_back(vref - vread);
    esum += (vref - vread);
    vrunning = calculatePwm(currTime, prevTime);
    prevTime = currTime;
    
    //Serial.print((motorCount/12.0)*12.566);
    //Serial.println(" cm travelled");
    //Serial.print("vread: ");
    //Serial.println(vread);
  }
  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ain1Pin,OUTPUT);
  pinMode(ain2Pin,OUTPUT);
  pinMode(pwmaPin,OUTPUT);
  pinMode(interrupt_pin, INPUT);
  pinMode(sensorPin, OUTPUT);
//pinMode(analogPin,INPUT);

  digitalWrite(sensorPin, HIGH);
  
  attachInterrupt(digitalPinToInterrupt(interrupt_pin), my_isr, FALLING);
  interrupts();
  Serial.begin(9600);
  
}

void driveForward(int val){
  analogWrite(pwmaPin, val);
  digitalWrite(ain2Pin, LOW);
  digitalWrite(ain1Pin, HIGH);
}

void driveReverse(int val){
  analogWrite(pwmaPin, val);
  digitalWrite(ain1Pin, LOW);
  digitalWrite(ain2Pin, HIGH);
}

void stopMotors(){
  analogWrite(pwmaPin, 0);
  digitalWrite(ain1Pin, 0);
  digitalWrite(ain2Pin, 0);
}

int calculateAngle(){
  return 1;
}

int calculatePwm(unsigned long ct, unsigned long pt){
  int newPwm = floor(2*verror[verror.size()-1] + 2*((verror[verror.size() - 1] - verror[verror.size() - 2])/(ct-pt)) + 2*currTime*esum);
  return newPwm;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //int readVal = analogRead(20);
  //Serial.println("Distance from wall: " + readVal);
  
  driveForward(70);
}
