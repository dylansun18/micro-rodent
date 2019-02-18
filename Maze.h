#ifndef MAZE_H
#define MAZE_H

#include "Cell.h"

//include StackList.h
class Maze{
  public:
    Maze();
    void initCells();
    void initWalls();
    void floodFill();
    void floodFillBR(int x, int y, int d);
    void floodFillBL(int x, int y, int d);
    void floodFillTL(int x, int y, int d);
    void floodFillTR(int x, int y, int d);
    void setWallNorth(int x, int y);
    void setWallEast(int x, int y);
    void setWallSouth(int x, int y);
    void setWallWest(int x, int y);
    Cell getCell(int x, int y);
    
  private:
    int dimension;
    Cell currentcell;
    Cell cells[8][8];
    bool wallsH [9][9];
    bool wallsV [9][9];
    
    
};

#endif
