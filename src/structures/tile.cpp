#include "tile.h"

#include "scoreable.h"
#include "tilestates.h"
#include <cmath>

tile::tile(){
    x = 0;
    y = 0;
    tileState = state::empty;
}

tile::tile(int xcord, int ycord,state newState){
    x = xcord;
    y = ycord;
    tileState = newState;
}

void tile::setX(int xcord){
    x = xcord;
}
void tile::setY(int ycord){
    y = ycord;
}
void tile::setState(state newState){
    tileState = newState;
}

int tile::getX(){
    return x;
}
int tile::getY(){
    return y;
}
state tile::getState(){
    return tileState;
}
char tile::printTile(){
    return stateToChar(tileState);
}

int tile::getScore(tile* startTile,tile* goalTile,float (*heur)(tile* current,tile* goal)){
    return sqrt(pow(startTile->getX()-x,2)+pow(startTile->getY()-y,2))+heur(this,goalTile);
}