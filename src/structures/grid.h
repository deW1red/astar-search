#include "tile.h"
#include "list.h"
#include "algorithms/heuristics.h"
#include <iostream>
#include <cmath> 
#ifndef GRID_H
#define GRID_H
class grid
{
    
    int xsize,ysize;
    tile** map;
    tile *startTile,*goalTile;

public:
    static float (*heuristicFunction)(tile* current,tile* goal);
    grid(int xSize,int ySize,int startx,int starty,int goalx,int goaly);
    
    int getXSize(),getYSize();
    tile *tileAt(int x,int y),*getStart(),*getGoal();
    float grid::getTileScore(tile* currentTile);
    list* getNeighbouringTiles(tile* originTile);
    void printGrid(),setStart(int x,int y),setGoal(int x,int y);
};
#endif
