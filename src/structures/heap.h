#include "scoreable.h"
#include "list.h"
#include <cmath>
#include <iostream>
#ifndef HEAP_H
#define HEAP_H
class heap{
    list array;
    int len;
    void pushHeapify();
    void popHeapify();
    int getParentIndex(int nodeIndex),getFirstChildIndex(int nodeIndex);
    
    public:
    heap();
    void push(node* newNode),print();
    node *pop(),*peek();   
    
};
#endif