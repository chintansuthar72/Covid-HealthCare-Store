#include "vaccine.h"
#include "string"
#include "iostream"
#include "Queue.h"

using namespace std;

extern Queue dozes[10000];
extern int vaccine_stock_coviShield;
extern int vaccine_stock_coVaccin;

// Set Customer's Name
void vaccine:: set_name() {
    string first_name, last_name;
    cout << "\nDear Customer ! Kindly Enter Your First Name : ";
    cin >> first_name;
    cout << "Enter Your Second Name : ";
    cin >> last_name;
    name = first_name + " " + last_name;
}

// Set Customer's Phone Number
void vaccine:: set_phone_number() {
    cout << "Please Enter Your Phone Number : ";
    cin >> phone_number;
}

// Print Bill
void vaccine:: print_vaccine_receipt()  {
    string vaccine_name;
    if (vaccine_type == 1) {
        vaccine_name = "covishield";
    } else if (vaccine_type == 2) {
        vaccine_name = "covaccin";
    }
    cout << "\n\n\n";
    cout << "--------------------------------------------------------\n";
    cout << "Vaccine ID   : " << ID << endl;
    cout << "Name         : " << name << endl;
    cout << "Phone Number : " << phone_number << endl;
    cout << "Vaccine type : " << vaccine_name << endl;
    cout << "Total Amount : " << total_amount << endl;
    cout << "Hope to see you for  second doze!! \n";
    cout << "--------------------------------------------------------\n";
    cout << "\n\n\n";
    int idx = (ID-17)%10000;
    dozes[idx].dequeue();
}

void vaccine:: set_vaccine_type() {
    cout << "Enter 1 for covishield(Rs.500) or Enter 2 for covaccin(Rs.500) : ";
    cin >> vaccine_type;
    if (vaccine_type == 1) {
        vaccine_stock_coviShield--;
    } else if (vaccine_type == 2) {
        vaccine_stock_coVaccin--;
    }
}

// Stock Check
bool vaccine:: stock_check() {
    if (vaccine_stock_coviShield <= 0 or vaccine_stock_coVaccin <= 0) {
        return false;
    }
    return true;
}

void vaccine:: set_total_amount() {
    if (vaccine_type == 1) {
        total_amount = (2 * 500);
    } else if (vaccine_type == 2) {
        total_amount = (2 * 500);
    }
}


void vaccine:: set_ID(int idx) {
    ID = (idx + 17) % 10000;
}

void vaccine:: get_data(int idx) {
    if (dozes[idx].empty())
    {
        cout << "You have completed all dozes. Stay safe,Stay healthy !!\n";
        return;
    }
    set_name();
    set_phone_number();
    set_vaccine_type();
    if (stock_check())
    {
        set_total_amount();
        print_vaccine_receipt();
        return;
    }
    else
    {
        cout << "No stock\n";
        return;
    }
}

long long int vaccine:: get_phone_number()
{
    return phone_number;
}