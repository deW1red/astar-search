#include "node.h"
#include "../algorithms/heuristics.h"
#include <iostream>
void node::setContent(tile* a){
    content = a;
}
tile* node::getContent(){
    return content;
}
node::node(){
    child = nullptr;
    content = nullptr;
}
node::node(tile* nodeContent){
    child  = nullptr;
    content = nodeContent;
}
node::node(tile* nodeContent,node* nodeChild){
    child = nodeChild;
    content = nodeContent;
}
void node::setChild(node* a){
    child = a;
}
node* node::getChild(){
    return child;
}