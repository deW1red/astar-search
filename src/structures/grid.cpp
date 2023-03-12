#include "grid.h"   


grid::grid(int xSize,int ySize,int startx,int starty,int goalx,int goaly){
    xsize = xSize;
    ysize = ySize;
    map = new tile*[ysize];
    for(int  i = 0;i<xSize;i++){
        map[i] = new tile[xsize];
    }
    for(int  i =0;i<ysize;i++){
        for(int  j = 0;j<xsize;j++){
            map[i][j].setX(j);
            map[i][j].setY(i);
        }
    }
    startTile = tileAt(startx,starty);
    startTile->setState(state::start);
    goalTile = tileAt(goalx,goaly);
    goalTile->setState(state::end);
}
void grid::printGrid(){
    for(int  i =0;i<ysize;i++){

        for(int  j = 0;j<xsize;j++){
            std::cout<<" | "<<map[i][j].printTile();
        }
        std::cout<<" |\n";
    }

}
tile* grid::tileAt(int x,int y){
    return &map[y][x];
}
tile* grid::getStart(){
    return startTile;
}
tile* grid::getGoal(){
    return goalTile;
}
void grid::setStart(int x,int y){
    startTile->setState(state::empty);
    startTile = tileAt(x,y);
    startTile->setState(state::start);
}
void grid::setGoal(int x,int y){
    goalTile->setState(state::empty);
    goalTile = tileAt(x,y);
    goalTile->setState(state::end);
}

float grid::getTileScore(tile* currentTile){
     return sqrt(pow(startTile->getX()-currentTile->getX(),2)+pow(startTile->getY()-currentTile->getY(),2))+heuristicFunction(currentTile,goalTile);
}


