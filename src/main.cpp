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
node* a,b;

int main(){
    srand(time(NULL));
    /*grid mainGrid(10,10);
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
    cout<<"\n";
    cout<<mainGrid.tileAt(5,5)->getScore(mainGrid.tileAt(0,0),mainGrid.tileAt(9,9),&cartesian);
    return 0;*/


    heap testheap;
    cout<<endl;
    for(int  i =0;i<1000;i++){
        int a = 100+rand()%1000000;
        testheap.push(new node(new number(a)));
        
    }
    testheap.push(new node(new number(testheap.peek()->getContent()->getScore()-1)));
    cout<<"Heap: ";
    testheap.print();
    cout<<endl;
    /*list lista;
    lista.pushNode(new node(new number(1)));
    lista.pushNode(new node(new number(2)));
    lista.pushNode(new node(new number(3)));
    lista.pushNode(new node(new number(4)));
    lista.pushNode(new node(new number(5)));
    lista.pushNode(new node(new number(6)));
    lista.pushNode(new node(new number(7)));
    lista.pushNode(new node(new number(8)));
    lista.pushNode(new node(new number(9)));
    lista.pushNode(new node(new number(10)));
    lista.pushNode(new node(new number(-1)));
    lista.println();
    lista.swapNodes(0,10);
    lista.swapNodes(1,2);
    lista.swapNodes(0,10);
    lista.println();*/
}