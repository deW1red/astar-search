#include "tile.h"
#include "grid.h"   
#include <iostream>
#include <cmath> 

grid::grid(int xSize,int ySize){
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

