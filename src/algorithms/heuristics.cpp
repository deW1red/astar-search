#include <cmath>
#include "heuristics.h"
float cartesian(tile* current,tile* goal){
    return sqrt(float(pow(goal->getX()-current->getX(),2))+float(pow(goal->getY()-current->getY(),2)));
}