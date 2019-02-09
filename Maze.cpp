#include "Maze.h"

Maze::Maze(){
  initWalls();
  initCells();
  floodFill();
}

void Maze::initCells(){
  for(int i = 0; i < dimension; i++){
    for(int j = 0; j < dimension; j++){
      //cells[i][j] = new Cell(i,j,255);
    }
  }
  //cells[dimension/2][dimension/2].setDistance(0);
  //cells[dimension/2 - 1][dimension/2].setDistance(0);
  //cells[dimension/2][dimension/2 - 1].setDistance(0);
  //cells[dimension/2 - 1][dimension/2 - 1].setDistance(0);
}

void Maze::initWalls(){
  for(int i=0; i <= dimension; i++){
    for(int j = 0 ; j <= dimension; j++){
       //wallsH[i][j] = false;
       //wallsV[i][j] = false;
    }
  }
}

void Maze::floodFill(){
  
}

void Maze::setWallNorth(int x, int y){
  //wallsH[y+1][x] = true;
}

void Maze::setWallSouth(int x, int y){
  //wallsH[y][x] = true;
}

void Maze::setWallEast(int x, int y){
  //wallsH[y][x+1] = true;
}

void Maze::setWallWest(int x, int y){
  //wallsH[y][x] = true;
}
