#include "tile.h"
#include "../algorithms/heuristics.h"
#include <iostream>

#ifndef NODE_H
#define NODE_H
class node
{
    node* child;
    tile *content;

    public:
    void setChild(node* a),setContent(tile* a);
    node *getChild();
    tile* getContent();
    node(),node(tile* nodeContent),node(tile* nodeContent,node* nodeChild);

};
#endif
