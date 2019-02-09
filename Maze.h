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
    void setWallNorth(int x, int y);
    void setWallEast(int x, int y);
    void setWallSouth(int x, int y);
    void setWallWest(int x, int y);
    
  private:
    int dimension;
    //Cell currentcell;
    //Cell[dimension][dimension] cells;
    //bool wallsH [dimension+1][dimension+1];
    //bool wallsV [dimension+1][dimension+1];
    
    
};

#endif
