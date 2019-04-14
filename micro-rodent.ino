#include <vector>
#include <cmath>
#include "Maze.h"
using namespace std;

//wheel circumference = 12.566 cm per rev
//tweak timeTol so that motor count is accurate

//motor driver
const int ain2Pin = 0;
const int ain1Pin = 1;
const int pwmaPin = 3;
const int interrupt_pin = 4;
const int sensorPin = 5;
const int analogPin = 20;

//Maze stuff
Maze m1;
int cells[4][4] = 
  {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
bool wallsH[5][5]=
  {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
  }
int currentCell1 = 3;
int currentCell2 = 0;
bool wallsH [5][5];
bool wallsV [5][5];

//estimate position
int angle = 0;
double xDist = 0.2;
double yDist = 0;
int r1 = 100;
int r2 = 300;
int r3 = 200;

//calculate velocity
vector<double> verror;
double vref = 1.4;
double vread = 0.0;
double esum = 0.0;
int vCalc = 70;

//states
bool inReverse = false;
bool inNewCell = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(ain1Pin,OUTPUT);
  pinMode(ain2Pin,OUTPUT);
  pinMode(pwmaPin,OUTPUT);
  pinMode(interrupt_pin, INPUT);
  pinMode(sensorPin, OUTPUT);
  pinMode(analogPin,INPUT);

  digitalWrite(sensorPin, HIGH);
  
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

void centerRobot(){
  if(r2 < 80){
    inReverse = false;
  }
  vCalc = 50;
}

void rotate(int amount){
  
}

void makeDecision(){
  int sCellValues[4] = {0,0,0,0};
  sCellValues[0] = cells[currentCell1][currentCell2+1];
  sCellValues[1] = cells[currentCell1+1][currentCell2];
  sCellValues[2] = cells[currentCell1][currentCell2-1];
  sCellValues[3] = cells[currentCell1-1][currentCell2];

  if(wallsH[currentCell1][currentCell2]){
    sCellValues[0]= 10000;
  }
  if(wallsH[currentCell1][currentCell2-1]){
    sCellValues[2]= 10000;
  }
  
  int minIndex = 0;
  for(int i = 0; i < 4; i++){
    if(sCellValues[i] < sCellValues[minIndex]){
      minIndex = i;
    }
  }
}

void updateLocation(int x, int y){
  
}

void reactReadings(){
  if(r2 > 100){
    inReverse = true;
  }
  vCalc = 30 + 200/r2;
  if(r1 - r3 > 50){
    rotate(-2);
  }
  if(r3 - r1 > 50){
    rotate(2);
  }
}

void printMaze(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      Serial.print(m1.getCell(i,j).getDistance());
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println("print");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int readVal = analogRead(20);
  r2 = readVal;
  Serial.print("Distance from wall: ");
  Serial.println(readVal);
  if(inNewCell){
     makeDecision();
     updateLocation(xDist,yDist);
     inNewCell = false;
  }
  
  if(!inReverse){
    reactReadings();
    driveForward(vCalc); //2.3 rotations per sec, 28.9cm/s
    Serial.print("vCalc ");
    Serial.println(vCalc);
    xDist += (0.004*vCalc) * sin(angle);
    yDist += (0.004*vCalc) * cos(angle);
    Serial.print("xDist ");
    Serial.println(xDist);
    Serial.print("yDist ");
    Serial.println(yDist);

  }
  else{
    centerRobot();
    driveReverse(vCalc);
    Serial.print("vCalc ");
    Serial.println(vCalc);
    xDist += (0.004*vCalc) * sin(angle);
    yDist -= (0.004*vCalc) * cos(angle);
    Serial.print("xDist ");
    Serial.println(xDist);
    Serial.print("yDist ");
    Serial.println(yDist);
  }
  delay(100);
}
