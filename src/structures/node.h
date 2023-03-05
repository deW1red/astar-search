#include "scoreable.h"
#ifndef NODE_H
#define NODE_H
class node
{
    node *leftChild,*rightChild;
    scoreable *content;

    public:
    void setLeft(node* a),setRight(node* a),setContent(scoreable* a);
    node *getLeft(),*getRight();
    scoreable* getContent();
    node(),node(scoreable* nodeContent),node(scoreable* nodeContent,node* nodeLeftChild,node* nodeRightChild);

};
#endif
