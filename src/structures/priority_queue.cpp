#include "scoreable.h"
#include "priority_queue.h"
#include "../algorithms/heuristics.h"
void priority_queue::push(scoreable* item){
    length++;
}
void priority_queue::balance(){

}

scoreable* priority_queue::pop(){

}
priority_queue::priority_queue(){
    head = nullptr;
    length = 0;
}
priority_queue::priority_queue(node* headNode){
    head = headNode;
    length = 1;
}
int priority_queue::getLength(){
    return length;
}