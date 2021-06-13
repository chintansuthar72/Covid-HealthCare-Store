#include <string>
#include "customer.h"
#include <cstring>
#include "iostream"
using namespace std;

extern int price[];
extern int items_stock[];

// Set Customer's Name
void customer:: set_name()
{
    string first_name, last_name;
    cout << "Dear Customer ! Kindly Enter Your First Name : ";
    cin >> first_name;
    cout << "Enter Your Last Name : ";
    cin >> last_name;
    customer_name = first_name + " " + last_name;
}

// Set Customer's Phone Number
void customer:: set_phone_number()
{
    cout << "Please Enter Your Phone Number : ";
    cin >> phone_number;
}

// Calculate Total Amount
void customer:: set_total_amount()
{
    total_amount = 0;
    for (int i = 0; i < 5; i++)
    {
        total_amount += (items[i] * price[i]);
    }
}

// Select quantity of each of the items you want to buy
void customer:: items_selection()
{
    int n, m;
    cout << "0-mask(50 Rs)\n1-sanitizers(150 Rs)\n2-medicines(100 Rs.)\n3-covid suite(2000 Rs)\n4-hand gloves(200 Rs)\n";
    cout << "Enter index number of the item you want to buy!!\nEnter -1 to end this\n";
    cin >> n;
    while (n != -1)
    {
        if (n > 4)
        {
            cout << "Please enter valid index number----> valid index number range is from 0 to 4" << endl;
            cin >> n;
        }
        cout << "Now, enter the quantity you want for this item" << endl;
        cin >> m;
        items[n] = m;
        cout << "Enter index number of the item you want to buy!!\nEnter -1 to end this\n";
        cin >> n;
    }
}

// Check Item Stock
void customer:: stock_check()
{
    char a;
    int s;
    for (int i = 0; i < 5; i++)
    {
        if (items[i] <= items_stock[i])
        {
            items_stock[i] = items_stock[i] - items[i];
            if (items[i] != 0)
                cout << "Successfully taken from the stock!!" << endl;
        }
        if (items[i] > items_stock[i])
        {
            cout << "Enough stock not available" << endl;

            cout << "Do you still want some items from the available stock? Press 'y' or 'Y' to continue and 'n' or 'N' to end this" << endl;
            cin >> a;
            if (a == 'y' || a == 'Y')
            {
                cout << "what is the new quantity of this item you want from the available stock now?" << endl;
                cin >> s;

                items_stock[i] = items_stock[i] - s;
            }

            if (a == 'n' || a == 'N')
            {
                s = 0;
                items_stock[i] = items_stock[i] - s;
            }
        }
    }
}

// Print Bill
void customer:: print_bill()
{
    cout << "\n\n\n";
    cout << "-----------------------------------------------------------------\n";
    cout << "Bill ID : " << ID << endl;
    cout << "Customer Name : " << customer_name << endl;
    cout << "Customer Phone Number : " << phone_number << endl;
    cout << "-----------------------------------------------------------------\n";
    cout << "**ITEMS**\n";
    cout << "Item idx. || Item Name   ||  Amount ||  Price\n";
    cout << "   0      || mask        ||    " << items[0] << "    ||  " << items[0] * price[0] << "\n";
    cout << "   1      || sanitizers  ||    " << items[1] << "    ||  " << items[1] * price[1] << "\n";
    cout << "   2      || medicines   ||    " << items[2] << "    ||  " << items[2] * price[2] << "\n";
    cout << "   3      || covid suite ||    " << items[3] << "    ||  " << items[3] * price[3] << "\n";
    cout << "   4      || hand gloves ||    " << items[4] << "    ||  " << items[4] * price[4] << "\n";
    cout << "Total Amount : " << total_amount << endl;
    cout << "-----------------------------------------------------------------\n";
    cout << "\n\n\n";
}

void customer:: set_ID(int idx)
{
    ID = (idx + 11) % 10000;
}
void customer:: get_data(int idx)
{
    set_name();
    set_phone_number();
    items_selection();
    stock_check();
    set_total_amount();
    print_bill();
}