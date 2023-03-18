#include "tile.h"
tile::tile(){
    x = 0;
    y = 0;
    tileState = state::empty;
    setScore(2137);
    visualState = state::none;
}
tile::tile(double tileScore){
    x = 0;
    y = 0;
    tileState = state::empty;
    setScore(tileScore);
    visualState = state::none;
}
tile::tile(int xcord, int ycord,state newState){
    x = xcord;
    y = ycord;
    tileState = newState;
    setScore(2137);
    visualState = state::none;
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
    if(visualState == state::none){
        return stateToChar(tileState);
    }else{
        return stateToChar(visualState);
    }
    
}
void tile::setScore(double newScore){
    score  = newScore;
}
double tile::getScore(){
    return g+h;
}
void tile::setVisualState(state newVisualState){
    visualState = newVisualState;
}
state tile::getVisualState(){
    return visualState;
}
void tile::setg(int newG){
    g = newG;
}
void tile::seth(int newH){
    h = newH;
}
int tile::geth(){
    return h;
}
int tile::getg(){
    return g;
}