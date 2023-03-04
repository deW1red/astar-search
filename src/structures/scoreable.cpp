#include "scoreable.h"
#include "random"

int scoreable::getScore(){
    return rand()%101;
}