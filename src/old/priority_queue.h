#include "node.h"
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
class priority_queue
{
    int length;
    node* head;
    void balance();

    public:
        void push(scoreable* item);
        scoreable* pop();
        priority_queue(),priority_queue(node* headNode);
        int getLength();

};
#endif
