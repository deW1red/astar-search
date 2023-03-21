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

#define BLOCKED state::blocked

using namespace std;

int xsize = 10,ysize = 10,startx =9,starty = 0,endx=6,endy=8;
double (*heuristicFunction)(tile* current,tile* goal) = &cartesian;
grid maingrid;
heap openlist;
int** closedlist;

int inclosed = 0,inopen = 0;

string response;

void printObstacleMenu(){
    cout<<"\nWybierz rodzaj przeszkody: [P]unkt / Linia [Pio]nowa / Linia [Poz]ioma / [Pro]stokat ";
    cin>>response;

    if(response == "P" ||response == "p" ||response == "Punkt" ||response == "punkt"){
        
        cout<<"\nPodaj wspolrzedne punktu (x y)  ";
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        maingrid.tileAt(x,y)->setState(BLOCKED);   

    }else if(response == "Pio" ||response == "pio" || response == "Linia Pionowa" ||response == "linia pionowa"|| response == "Pionowa" ||response == "pionowa"){
        
        cout<<"\nPodaj wspolrzedne poczatku linii i jej dlugosc (x y dlugosc)  ";
        int x,y,len;
        cin>>x>>y>>len;
        x--;
        y--;
        for(int i = y;i<y+len;i++){
            maingrid.tileAt(x,i)->setState(BLOCKED);          
        }
                            
    }else if(response == "Poz" ||response == "poz" || response == "Linia Pozioma" ||response == "linia pozioma"|| response == "Pozioma" ||response == "pozioma"){
        
        cout<<"\nPodaj wspolrzedne poczatku linii i jej dlugosc (x y dlugosc)  ";
        int x,y,len;
        cin>>x>>y>>len;
        x--;
        y--;
        for(int i = x;i<x+len;i++){
            maingrid.tileAt(i,y)->setState(BLOCKED);          
        }
                            
    }else{

        cout<<"\nPodaj wspolrzedne punktow na ktorych rozpiety bedzie prostokat (x1 y1 x2 y2)  ";
        int x1,y1,x2,y2,xp,xk,yp,yk;
        cin>>x1>>y1>>x2>>y2;

        x1--;
        y1--;
        x2--;
        y2--;
        xp = min(x1,x2);
        xk = max(x1,x2);
        yp = min(y1,y2);
        yk = max(y1,y2);

        for(int i = xp;i<=xk;i++){
            for(int j = yp;j<=yk;j++){
                maingrid.tileAt(i,j)->setState(BLOCKED);          
            }         
        }

    }
}

int main(){


    //Setup board
    cout<<"Program demonstrujacy algorytm znajdywania drogi A*\n\n";
    cout<<"Zdefiniuj mape - wymiary, punkt startowy i koncowy oraz zablokowane pola\n";
    cout<<"Czy chcesz uzyc ustawien domyslnych ? (t/n)  ";
    cin>>response;

    if(response == "T" || response == "t"){

        maingrid = grid(xsize,ysize,startx,starty,endx,endy,heuristicFunction);
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

    }else if(response == "N" || response == "n"){

        bool done = false;
        while(!done){
            cout<<"\nPodaj wymiary mapy (x y)  ";
            cin>>xsize;
            cin>>ysize;

            cout<<"\nPodaj polozenie punktu, z ktorego rozpocznie sie znajdywanie drogi (x y)  ";
            cin>>startx;
            cin>>starty;
            startx--;
            starty--;

            cout<<"\nPodaj polozenie punktu, do ktorego szukana bedzie droga (x y)  ";
            cin>>endx;
            cin>>endy;
            endx--;
            endy--;

            cout<<"\nWybierz funkcje heurystyczna, ktora bedzie uzywana przez algorytm [K]artezjanska/niemajeszczeinnych  ";
            cin>>response;
            if(response == "K" || response == "Kartezjańska" || response == "Kartezjanska"|| response == "kartezjańska" || response == "kartezjanska"){
                heuristicFunction = &cartesian;
            }

            maingrid = grid(xsize,ysize,startx,starty,endx,endy,heuristicFunction);

            cout<<"\nCzy chcesz dodac przeszkody? (t/n)  ";
            cin>>response;
            while(response == "T" || response == "t"){
                printObstacleMenu();
                maingrid.printGrid();
                cout<<"\nCzy chcesz kolejna przeszkode? (t/n)  ";
                cin>>response;    
            }
            cout<<"\n___[Obecna Mapa]___";
            maingrid.printGrid();
            cout<<"\n[Z]acznij szukanie drogi / [P]onownie zdefiniuj mape  ";
            cin>>response;
            if(response == "Z" || response == "z" || response == "Zacznij" || response == "zacznij"){
                done = true;                        
            }
        }

    }else{
        cout<<"Xo??!!1!";
        return 0;
    }

    






    //A* Algorithm
    closedlist = new int*[xsize];
    for(int  i =0;i<xsize;i++){
        closedlist[i] = new int[ysize];
    }
    for(int  i = 0;i<xsize;i++){
        for(int  j = 0;j<ysize;j++){
            closedlist[i][j] = -2;
        }
    }
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
                break;
            }else{
                maingrid.setTileG(currentTile,neighbourTile);
                maingrid.setTileH(neighbourTile);
            }

            if(openlist.isTileWithLowerScoreInHeap(neighbourTile)){
                inopen++;
                continue;
            }else if(closedlist[neighbourTile->getX()][neighbourTile->getY()] != -2 && closedlist[neighbourTile->getX()][neighbourTile->getY()] < neighbourTile->getScore()){
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
    //cout<<"\n\n\n"<<inopen<<"  "<<inclosed;
}