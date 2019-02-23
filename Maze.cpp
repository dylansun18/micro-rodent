#include "Maze.h"
#include "Cell.h"

Maze::Maze(){
  initWalls();
  initCells();
  floodFill();
}

void Maze::initCells(){
//  for(int i = 0; i < 8; i++){
//    for(int j = 0; j < 8; j++){
//      cells[i][j] = new Cell(i,j);
//    }
//  }
//  cells[8/2][8/2].setDistance(0);
//  cells[8/2 - 1][8/2].setDistance(0);
//  cells[8/2][8/2 - 1].setDistance(0);
//  cells[8/2 - 1][8/2 - 1].setDistance(0);
}

void Maze::initWalls(){
  for(int i=0; i < 9; i++){
    for(int j = 0 ; j < 9; j++){
       wallsH[i][j] = false;
       wallsV[i][j] = false;
    }
  }
}

void Maze::floodFill(){
  int counter = 0;
  int ocounter = 8-2;
  for(int i = 0; i < 8; i++){
    counter = ocounter;
    for(int j = 0; j < 8; j++){
      cells[i][j].setDistance(counter);
      if(j < (8/2)-1){
        counter--;
      }
      else if(j == (8/2)-1){
      }
      else{
        counter++;
      }
    }
    if(i < (8/2)-1){
      ocounter--;
    }
    else if(i == (8/2)-1){
      
    }
    else{
      ocounter++;
    }
  }
}

void Maze::setWallNorth(int x, int y){
  wallsH[y+1][x] = true;
}

void Maze::setWallSouth(int x, int y){
  wallsH[y][x] = true;
}

void Maze::setWallEast(int x, int y){
  wallsH[y][x+1] = true;
}

void Maze::setWallWest(int x, int y){
  wallsH[y][x] = true;
}

Cell Maze::getCell(int x, int y){
  return cells[x][y];
}
