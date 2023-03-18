#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include "structures/grid.h"
#include "structures/tile.h"
#include "structures/tilestates.h"
#include "structures/list.h"
#include "structures/heap.h"
#include "structures/node.h"
#include "algorithms/heuristics.h"
#define size 10
using namespace std;
grid maingrid(size,size,9,0,6,8);
heap openlist;
int closedlist[size][size];
int inclosed = 0,inopen = 0;
int main(){
    for(int  i = 0;i<size;i++){
        for(int  j = 0;j<size;j++){
            closedlist[i][j] = -2137;
        }
    }
    srand(time(0));
    //Setup board
    maingrid.tileAt(6,7)->setState(state::blocked);
    maingrid.tileAt(2,7)->setState(state::blocked);
    maingrid.tileAt(3,7)->setState(state::blocked);
    maingrid.tileAt(4,7)->setState(state::blocked);
    maingrid.tileAt(5,7)->setState(state::blocked);
    maingrid.tileAt(6,7)->setState(state::blocked);
    maingrid.tileAt(7,7)->setState(state::blocked);
    maingrid.tileAt(8,7)->setState(state::blocked);
    maingrid.tileAt(9,7)->setState(state::blocked);
    maingrid.tileAt(1,7)->setState(state::blocked);
    maingrid.printGrid();

    openlist.push(maingrid.getStart());
    maingrid.getStart()->setVisualState(state::visited);
    cout<<endl;

    bool finished = false;

    while(openlist.getLength() > 0 && !finished){
        tile* currentTile = openlist.pop();

        list neighbours = maingrid.getNeighbouringTiles(currentTile);

        for(int i = 0;i<neighbours.getLength();i++){

            tile* neighbourTile = neighbours.getNodeAt(i)->getContent();


            if(neighbourTile == maingrid.getGoal()){
                neighbourTile->setVisualState(state::visited);
                finished = true;
            }else{
                maingrid.setTileG(currentTile,neighbourTile);
                maingrid.setTileH(neighbourTile);
            }

            if(openlist.isTileWithLowerScoreInHeap(neighbourTile)){
                inopen++;
                continue;
            }else if(closedlist[neighbourTile->getX()][neighbourTile->getY()] != -2137 && closedlist[neighbourTile->getX()][neighbourTile->getY()] < neighbourTile->getScore()){
                inclosed++;
                continue;
            }else{
                if(neighbourTile->getVisualState() == state::none){
                   neighbourTile->setVisualState(state::checked);     
                }
                openlist.push(neighbourTile);
            }
            
        }

        currentTile->setVisualState(state::visited);
        closedlist[currentTile->getX()][currentTile->getY()] = currentTile->getScore();
        
        //cout<<"\n"<<openlist.getLength()<<"\n";
    }
    maingrid.printGrid();
    cout<<"\n\n\n"<<inopen<<"  "<<inclosed;
}