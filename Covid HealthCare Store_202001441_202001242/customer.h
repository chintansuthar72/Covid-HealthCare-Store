#include <string>
using namespace std;

#ifndef COVID_HEALTHCARE_STORE_CUSTOMER_H
#define COVID_HEALTHCARE_STORE_CUSTOMER_H


class customer
{
    string customer_name;       // Name
    int ID;                     // Bill ID
    long long int phone_number; // Phone Number
    int items[5];               // stores the quantity of each of the items at respective indices alloted for items
    int total_amount;           // Total Amount

    // Set Customer's Name
    void set_name();

    // Set Customer's Phone Number
    void set_phone_number();

    // Calculate Total Amount
    void set_total_amount();

    // Select quantity of each of the items you want to buy
    void items_selection();

    // Check Item Stock
    void stock_check();

    // Print Bill
    void print_bill();
public:
    void set_ID(int idx);
    void get_data(int idx);
};


#endif //COVID_HEALTHCARE_STORE_CUSTOMER_H