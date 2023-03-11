#include "node.h"
#include <iostream>
#ifndef LIST_H
#define lIST_H
class list{
    node* head;
    int len;

    public:
    list();
    void pushNode(node* newNode),removeNode(int nodeIndex),swapNodes(int nodeA,int nodeB),setContent(int nodeIndex,scoreable* nodeContent),print();
    node* getNodeAt(int nodeIndex);
    int getLength();
};
#endif