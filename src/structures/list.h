#include "node.h"
#include "tile.h"
#include <iostream>
#ifndef LIST_H
#define LIST_H
class list{
    node* head;
    int len;

    public:
    list();
    void pushNode(node* newNode),removeNode(int nodeIndex),swapNodes(int nodeA,int nodeB),print(),println();
    node* getNodeAt(int nodeIndex);
    int getLength(),getScoreAt(int nodeIndex);
};
#endif