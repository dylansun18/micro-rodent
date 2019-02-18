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
  floodFillBR(8/2,8/2,0);
  floodFillTR(8/2-1,8/2,0);
  floodFillBL(8/2,8/2-1,0);
  floodFillTL(8/2-1,8/2-1,0);
}

void Maze::floodFillBR(int x, int y, int d){
  if(x>7 || y> 7){
    return;
  }
  else{
    cells[x][y].setDistance(d);
    floodFillBR(x+1, y, d+1);
    floodFillBR(x, y+1, d+1);
  }
}

void Maze::floodFillBL(int x, int y, int d){
  if(x > 7 || y < 0){
    return;
  }
  else{
    cells[x][y].setDistance(d);
    floodFillBL(x+1, y, d+1);
    floodFillBL(x, y-1, d+1);
  }
}

void Maze::floodFillTL(int x, int y, int d){
  if(x < 0 || y < 0){
    return;
  }
  else{
    cells[x][y].setDistance(d);
    floodFillTL(x-1, y, d+1);
    floodFillTL(x, y-1, d+1);
  }
}

void Maze::floodFillTR(int x, int y, int d){
  if(x < 0 || y > 7){
    return;
  }
  else{
    cells[x][y].setDistance(d);
    floodFillTR(x-1, y, d+1);
    floodFillTR(x, y+1, d+1);
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
