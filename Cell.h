#ifndef CELL_H
#define CELL_H

class Cell{
  private:
    int x;
    int y;
    int distance;
    
  public:
    int getX();
    int getY();
    int getDistance();
    void setX(int x);
    void setY(int y);
    void setDistance(int distanceIn);
    Cell(int xIn, int yIn, int distanceIn);
};

#endif
