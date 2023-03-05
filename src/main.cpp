#include <iostream>
#include "structures/grid.h"
#include "structures/tile.h"
#include "structures/tilestates.h"
#include "structures/priority_queue.h"
#include <random>
#include <cstdlib>
#include <time.h>
using namespace std;


int main(){
    srand(time(NULL));
    grid mainGrid(10,10);
     for(int  i =0;i<10;i++){
        for(int  j = 0;j<10;j++){
            int a = rand()%3;
            if(a == 2){
                mainGrid.tileAt(i,j)->setState(state::blocked);
            }
        }
    }
    mainGrid.tileAt(0,0)->setState(state::start);
    mainGrid.tileAt(9,9)->setState(state::end);
    mainGrid.printGrid();
    return 0;
}