#include "scoreable.h"

#ifndef TILE_H
#define TILE_H

class tile: public scoreable
{
    int x,y;
    bool blockedState;
public:
    tile();
    tile(int xcord, int ycord,bool blocked);

    void setX(int xcord),setY(int ycord),setState(bool blocked);
    int getX(),getY();
    bool isBlocked();
};

#endif

