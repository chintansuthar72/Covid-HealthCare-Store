#ifndef COVID_HEALTHCARE_STORE_RECORD_H
#define COVID_HEALTHCARE_STORE_RECORD_H

#include "customer.h"

struct Node
{
    customer data;
    Node* next;

    explicit Node(customer X);
};

class record
{
    Node* last_pointer;
public:
    record();
    void add_entry(customer X);
};


#endif //COVID_HEALTHCARE_STORE_RECORD_H
