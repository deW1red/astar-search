#include "tilestates.h"
#include <cmath>
#ifndef TILE_H
#define TILE_H

class tile
{
    int x,y,g,h;
    double score;
    state tileState;
    state visualState;


public:
    tile();
    tile(double tileScore);
    tile(int xcord, int ycord,state newState);

    void setX(int xcord),setY(int ycord),setState(state newState),setScore(double newScore),setVisualState(state newVisualState),setg(int newG),seth(int newH);
    int getX(),getY(),getg(),geth();
    double getScore();

    state getState(),getVisualState();
    char printTile();
};

#endif

