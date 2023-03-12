#include "tile.h"
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

float tile::getScore(){
   
}