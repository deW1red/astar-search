#include "scoreable.h"
#ifndef NODE_H
#define NODE_H
class node
{
    node* child;
    scoreable *content;

    public:
    void setChild(node* a),setContent(scoreable* a);
    node *getChild();
    scoreable* getContent();
    node(),node(scoreable* nodeContent),node(scoreable* nodeContent,node* nodeChild);

};
#endif
