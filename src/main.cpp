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
#include "structures/number.h"
#include "algorithms/heuristics.h"

using namespace std;
static grid maingrid(10,10,0,0,9,9);

int main(){
    srand(time(NULL));
    maingrid.heuristicFunction = &cartesian;
    cout<<maingrid.tileAt(5,5)->

}