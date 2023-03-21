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
void heap::push(tile* nodeContent){
    len++;
    array.pushNode(new node(nodeContent));
    pushHeapify();
}
tile* heap::pop(){
    if(len > 0){
        node* returnNode = array.getNodeAt(len-1);
        popHeapify();
        return returnNode->getContent();
    }else{
        std::cout<<"WARNING: Popped empty heap! (sus)";
    }
    return new tile();
    
}
tile* heap::peek(){
    return array.getNodeAt(0)->getContent();
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
void heap::printTiles(){
    for(int  i= 0;i<array.getLength();i++){
        std::cout<<"("<<array.getNodeAt(i)->getContent()->getX()<<","<<array.getNodeAt(i)->getContent()->getY()<<")  ";
    }
    std::cout<<"\n";
}
int heap::getLength(){
    return len;
}
bool heap::isTileWithLowerScoreInHeap(tile* currentTile){
    for(int i=0;i<array.getLength();i++){
        tile* arrayTile = array.getNodeAt(i)->getContent();
        if(currentTile->getX() == arrayTile->getX() && currentTile->getY() == arrayTile->getY() && currentTile->getScore() >= arrayTile->getScore()){
            return true;
        }else{
            //std::cout<<currentTile->getScore()<<" < "<<arrayTile->getScore()<<"\n";
        }
    }
    return false;
}