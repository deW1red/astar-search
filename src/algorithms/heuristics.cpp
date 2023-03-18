#include <cmath>
#include "heuristics.h"
double cartesian(tile* current,tile* goal){
    return double(pow(goal->getX()-current->getX(),2))+float(pow(goal->getY()-current->getY(),2));
}