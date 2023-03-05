#include "node.h"
#include "scoreable.h"
#include "../algorithms/heuristics.h"
void node::setLeft(node* a){
    leftChild = a;
}
void node::setRight(node* a){
    rightChild = a;
}
void node::setContent(scoreable* a){
    content = a;
}
node* node::getLeft(){
    return leftChild;
}
node* node::getRight(){
    return rightChild;
}
scoreable* node::getContent(){
    return content;
}
node::node(){
    leftChild = nullptr;
    rightChild = nullptr;
    content = nullptr;
}
node::node(scoreable* nodeContent){
    leftChild = nullptr;
    rightChild = nullptr;
    content = nodeContent;
}
node::node(scoreable* nodeContent,node* nodeLeftChild,node* nodeRightChild){
    leftChild = nodeLeftChild;
    rightChild = nodeRightChild;
    content = nodeContent;
}
