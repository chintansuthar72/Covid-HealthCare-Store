#include "record.h"
#include "customer.h"

Node::Node(customer X) {
    data = X;
    next = nullptr;
}

record::record() {
    last_pointer = nullptr;
}

void record::add_entry(customer X) {
    Node *n = new Node(X);
    last_pointer = n;
}