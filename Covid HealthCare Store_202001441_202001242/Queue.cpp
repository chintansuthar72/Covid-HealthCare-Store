#include "Queue.h"
#include "iostream"
using namespace std;


Queue :: Queue() {
    size = 2;
    front = -1;
    back = -1;
    arr = new int[2];
}

void Queue ::  enqueue(int x) {
    if (back == size - 1) {
        cout << "Queue Overflow" << endl;
        return;
    }
    back++;
    arr[back] = x;

    if (front == -1)
        front++;
}

void Queue :: dequeue() {
    if (front == -1 || front > back) {
        cout << "No element in Queue" << endl;
        return;
    }
    front++;
}

int Queue :: Front() {
    if (front == -1 || front > back) {
        cout << "No element in stack" << endl;
        return 0;
    }
    return arr[front];
}

bool Queue :: empty() {
    if (front == -1 || front > back)
        return true;
    else
        return false;
}
