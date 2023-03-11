#include "node.h"
#include "scoreable.h"
#include "../algorithms/heuristics.h"
void node::setContent(scoreable* a){
    content = a;
}
scoreable* node::getContent(){
    return content;
}
node::node(){
    child = nullptr;
    content = nullptr;
}
node::node(scoreable* nodeContent){
    child  = nullptr;
    content = nodeContent;
}
node::node(scoreable* nodeContent,node* nodeChild){
    child = nodeChild;
    content = nodeContent;
}
void node::setChild(node* a){
    child = a;
}
node* node::getChild(){
    return child;
}