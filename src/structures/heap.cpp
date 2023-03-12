#include "heap.h"
#include <iostream>
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
    if(len > 0){
        node* returnNode = array.getNodeAt(len-1);
        popHeapify();
        return returnNode;
    }else{
        std::cout<<"WARNING: Popped empty heap! (sus)";
    }
    return new node(new scoreable());
    
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
    int current = 0;
    array.swapNodes(0,len-1);
    array.removeNode(len-1);
    len--;
    while(getFirstChildIndex(current) < len){
        if(getFirstChildIndex(current)+1 >= len){
            if(array.getScoreAt(getFirstChildIndex(current)) > array.getScoreAt(current)){
                break;
            }else{
                array.swapNodes(current,getFirstChildIndex(current));
                break;
            }
        }

        if(array.getScoreAt(getFirstChildIndex(current)) > array.getScoreAt(current) && array.getScoreAt(getFirstChildIndex(current)+1) > array.getScoreAt(current)){
            break;
        }else if(array.getScoreAt(getFirstChildIndex(current)) < array.getScoreAt(current) && array.getScoreAt(getFirstChildIndex(current)+1) > array.getScoreAt(getFirstChildIndex(current))){
            array.swapNodes(current,getFirstChildIndex(current));
            current  = getFirstChildIndex(current);
        }else{
            array.swapNodes(current,getFirstChildIndex(current)+1);
            current  = getFirstChildIndex(current)+1;
        }
    }
}
void heap::print(){
    array.print();
}