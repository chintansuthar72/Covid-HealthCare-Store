#ifndef COVID_HEALTHCARE_STORE_QUEUE_H
#define COVID_HEALTHCARE_STORE_QUEUE_H

class Queue
{
    int *arr;
    int size;
    int front, back;

public:
    Queue();
    void enqueue(int x);
    void dequeue();
    int Front();
    bool empty();
};

#endif //COVID_HEALTHCARE_STORE_QUEUE_H