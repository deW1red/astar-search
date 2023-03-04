#include "tile.h"

#ifndef GRID_H
#define GRID_H
class grid
{
    
    int xsize,ysize;
    tile** map;

public:
    grid(int xSize,int ySize);
    
    int getXSize(),getYSize();
    tile* tileAt(int x,int y);

    void printGrid();
    //void setXSize(int x),setYSize(int y),setSize(int x, int y);
};
#endif
