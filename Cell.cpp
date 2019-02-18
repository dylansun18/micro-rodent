#include "Cell.h"

Cell::Cell(){
  x = 0; 
  y = 0;
  distance = 0;
}

Cell::Cell(int xIn, int yIn){
  x = xIn;
  y = yIn;
  distance = 0;
}

int Cell::getX(){
  return x;
}

int Cell::getY(){
  return y;
}

int Cell::getDistance(){
  return distance;
}

void Cell::setX(int xIn){
  x = xIn;
}

void Cell::setY(int yIn){
  y = yIn;
}

void Cell::setDistance(int distanceIn){
  distance = distanceIn;
}
