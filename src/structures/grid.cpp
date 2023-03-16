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

list* grid::getNeighbouringTiles(tile* originTile){
    list* returnList;
    int x = originTile->getX();
    int y = originTile->getY();
    if(x == 0 && y == 0){
        returnList->pushNode(new node(tileAt(x,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y)));
        returnList->pushNode(new node(tileAt(x+1,y+1)));
    }else if(x == xsize -1 && y == 0){
        returnList->pushNode(new node(tileAt(x,y+1)));
        returnList->pushNode(new node(tileAt(x-1,y)));
        returnList->pushNode(new node(tileAt(x-1,y+1)));
    }else if(x == 0 && y == ysize - 1){
        returnList->pushNode(new node(tileAt(x+1,y)));
        returnList->pushNode(new node(tileAt(x,y-1)));
        returnList->pushNode(new node(tileAt(x+1,y-1)));
    }else if(x == xsize -1 && y == ysize -1){
        returnList->pushNode(new node(tileAt(x,y-1)));
        returnList->pushNode(new node(tileAt(x-1,y)));
        returnList->pushNode(new node(tileAt(x-1,y-1)));
    }else if(x == 0){
        returnList->pushNode(new node(tileAt(x,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y)));
        returnList->pushNode(new node(tileAt(x,y-1)));
        returnList->pushNode(new node(tileAt(x+1,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y-1)));
    }else if(y == 0){
        returnList->pushNode(new node(tileAt(x,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y)));
        returnList->pushNode(new node(tileAt(x-1,y)));
        returnList->pushNode(new node(tileAt(x-1,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y+1)));
    }else if(x == xsize -1){
        returnList->pushNode(new node(tileAt(x,y+1)));
        returnList->pushNode(new node(tileAt(x,y-1)));
        returnList->pushNode(new node(tileAt(x-1,y)));
        returnList->pushNode(new node(tileAt(x-1,y+1)));
        returnList->pushNode(new node(tileAt(x-1,y-1)));
    }else if(y == ysize -1){
        returnList->pushNode(new node(tileAt(x+1,y)));
        returnList->pushNode(new node(tileAt(x,y-1)));
        returnList->pushNode(new node(tileAt(x-1,y)));
        returnList->pushNode(new node(tileAt(x+1,y-1)));
        returnList->pushNode(new node(tileAt(x-1,y-1)));
    }else {
        returnList->pushNode(new node(tileAt(x,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y)));
        returnList->pushNode(new node(tileAt(x,y-1)));
        returnList->pushNode(new node(tileAt(x-1,y)));
        returnList->pushNode(new node(tileAt(x-1,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y+1)));
        returnList->pushNode(new node(tileAt(x+1,y-1)));
        returnList->pushNode(new node(tileAt(x-1,y-1)));
    }

    return returnList;
}


