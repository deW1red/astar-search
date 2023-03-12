#include "list.h"
#include <iostream>
list::list(){
    head = new node();
    head->setChild(nullptr);
    head->setContent(nullptr);
    len=1;
}
void list::pushNode(node* newNode){
    if(head->getContent() == nullptr){
        head->setContent(newNode->getContent());
        delete newNode;
    }else{
        getNodeAt(len-1)->setChild(newNode);
        len++;
    }


}
void list::removeNode(int nodeIndex){
    if(nodeIndex == len-1){
        getNodeAt(len-2)->setChild(nullptr);
    }else{
        getNodeAt(nodeIndex)->setContent(getNodeAt(nodeIndex+1)->getContent());
        getNodeAt(nodeIndex)->setChild(getNodeAt(nodeIndex+1)->getChild());
    }
    len--;
}
void list::swapNodes(int nodeA,int nodeB){
    scoreable* tmp = getNodeAt(nodeA)->getContent();
    getNodeAt(nodeA)->setContent(getNodeAt(nodeB)->getContent());
    getNodeAt(nodeB)->setContent(tmp);
    tmp = nullptr;
    delete tmp;
}
void list::setContent(int nodeIndex,scoreable* nodeContent){
    getNodeAt(nodeIndex)->setContent(nodeContent);
}
node* list::getNodeAt(int nodeIndex){
    node* headptr = head;
    for(int  i =0;i<nodeIndex;i++){
        headptr = headptr->getChild();
    }
    return headptr;
}
int list::getLength(){
    return len;
}
void list::print(){
    for(int  i =0;i<len;i++){
        std::cout<<getNodeAt(i)->getContent()->getScore()<<" ";
    }
}
void list::println(){
    for(int  i =0;i<len;i++){
        std::cout<<getNodeAt(i)->getContent()->getScore()<<" ";
    }
    std::cout<<std::endl;
}
int list::getScoreAt(int nodeIndex){
    return getNodeAt(nodeIndex)->getContent()->getScore();
}