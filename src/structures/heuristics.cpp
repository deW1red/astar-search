#include "heuristics.h"
int cartesian(tile* current,tile* goal){
    return sqrt(pow(goal->getX()-current->getX(),2)+pow(goal->getY()-current->getY(),2));
}