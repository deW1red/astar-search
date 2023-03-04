#include "scoreable.h"
#include "tilestates.h"
#ifndef TILE_H
#define TILE_H

class tile: public scoreable
{
    int x,y;
    state tileState;

public:
    tile();
    tile(int xcord, int ycord,state newState);

    void setX(int xcord),setY(int ycord),setState(state newState);
    int getX(),getY();

    state getState();
    char printTile();
    
};

#endif

