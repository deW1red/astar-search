#include "tile.h"
#include "list.h"
#include "tilestates.h"
#include "../algorithms/heuristics.h"
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
    double (*heuristicFunction)(tile* current,tile* goal);
    grid(),grid(int xSize,int ySize,int startx,int starty,int goalx,int goaly,double (*gridHeuristicFunction)(tile* current,tile* goal));
    
    int getXSize(),getYSize();
    tile *tileAt(int x,int y),*getStart(),*getGoal();
    list getNeighbouringTiles(tile* originTile);
    void printGrid(),setStart(int x,int y),setGoal(int x,int y),setTileG(tile* ancestorTile,tile* currentTile),setTileH(tile* currentTile);
};
#endif
