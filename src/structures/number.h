#include "scoreable.h"
#ifndef NUMBER_H
#define NUMBER_H
class number: public scoreable{
    int val;

    public:
    number(int numval);
    int getScore();

};
#endif