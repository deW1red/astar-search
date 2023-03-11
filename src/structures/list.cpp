#include "list.h"
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
        delete getNodeAt(len-1);
        getNodeAt(len-2)->setChild(nullptr);
    }else{
        getNodeAt(nodeIndex)->setContent(getNodeAt(nodeIndex+1)->getContent());
        getNodeAt(nodeIndex)->setChild(getNodeAt(nodeIndex+1)->getChild());
        delete getNodeAt(nodeIndex+1);
    }
    len--;
}
void list::swapNodes(int nodeA,int nodeB){
    node* tmp;
    tmp->setChild(getNodeAt(nodeA)->getChild());
    tmp->setContent(getNodeAt(nodeA)->getContent());
    getNodeAt(nodeA)->setChild(getNodeAt(nodeB)->getChild());
    getNodeAt(nodeA)->setContent(getNodeAt(nodeB)->getContent());
    getNodeAt(nodeB)->setChild(tmp->getChild());
    getNodeAt(nodeB)->setContent(tmp->getContent());
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