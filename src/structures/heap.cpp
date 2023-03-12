#include "heap.h"
heap::heap(){
    len = 0;
}
int heap::getParentIndex(int nodeIndex){
    return floor((nodeIndex-1)/2);
}
int heap::getFirstChildIndex(int nodeIndex){
    return 2*nodeIndex+1;
}
void heap::push(node* newNode){
    len++;
    array.pushNode(newNode);
    pushHeapify();
}
node* heap::pop(){
    len--;
    return array.getNodeAt(0);
}
node* heap::peek(){
    return array.getNodeAt(0);
}
void heap::pushHeapify() {
    int current = len-1;
    while(current > 0){
        if(array.getNodeAt(getParentIndex(current))->getContent()->getScore() > array.getNodeAt(current)->getContent()->getScore()){
            array.swapNodes(current,getParentIndex(current));
        }else{
            break;
        }
        current = getParentIndex(current);
    }
}
void heap::popHeapify() {
    while(true){
        
    }
}
void heap::print(){
    array.print();
}