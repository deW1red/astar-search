#include "scoreable.h"
#include "tile.h"

tile::tile(){
    x = 0;
    y = 0;
    blockedState = false;
}

tile::tile(int xcord, int ycord,bool blocked){
    x = xcord;
    y = ycord;
    blockedState = blocked;
}

void tile::setX(int xcord){
    x = xcord;
}
void tile::setY(int ycord){
    y = ycord;
}
void tile::setState(bool blocked){
    blockedState = blocked;
}

int tile::getX(){
    return x;
}
int tile::getY(){
    return y;
}
bool tile::isBlocked(){
    return blockedState;
}