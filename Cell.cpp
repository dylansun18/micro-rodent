#include "Cell.h"

Cell::Cell(int xIn, int yIn, int distanceIn){
  x = xIn;
  y = yIn;
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
