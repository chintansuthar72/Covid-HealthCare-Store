#include "string"
using namespace std;

#ifndef COVID_HEALTHCARE_STORE_VACCINE_H
#define COVID_HEALTHCARE_STORE_VACCINE_H


class vaccine
{
    string name;
    long long int phone_number;
    int ID;
    int total_amount;
    int vaccine_type; // 1-(covishield) and 2-(covaccin)

    // Set Customer's Name
    void set_name();

    // Set Customer's Phone Number
    void set_phone_number();

    // Print Bill
    void print_vaccine_receipt();

    void set_vaccine_type();

    // Stock Check
    bool stock_check();

    void set_total_amount();

public:
    void set_ID(int idx);
    void get_data(int idx);
    long long int get_phone_number();
};


#endif //COVID_HEALTHCARE_STORE_VACCINE_H