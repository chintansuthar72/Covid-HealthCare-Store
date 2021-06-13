#include <iostream>
#include "Queue.h"
#include "customer.h"
#include "record.h"
#include "vaccine.h"
using namespace std;

int update_stock_number = 1546;

int items_stock[] = {1000, 1000, 1000, 1000, 1000}; // stock of items for class customer
int price[] = {50, 150, 100, 2000, 200}; // price of items
int vaccine_stock_coviShield = 500;
int vaccine_stock_coVaccin = 500;
Queue dozes[10000];

void second_doze(vaccine X,int vaccine_ID,long long int &phone_number)
{
    int idx = (vaccine_ID-17)%10000;
    if(phone_number == X.get_phone_number())
    {
        if(dozes[idx].empty())
        {
            cout << "All dozes are taken.\n\n";
        }
        else if(dozes[idx].Front() != 2)
        {
            cout << "Wrong configuration.Please Enter valid ID.\n\n";
        }
        else
        {
            dozes[idx].dequeue();
            cout << "Dear, You have now taken second doze and till You have completed all dozes. Stay safe,Stay healthy !!\n\n\n";
        }
    }
    else
    {
        cout << "Wrong configuration.Please Enter valid ID. or Phone number.\n\n";
    }
}

void update_stock()
{
    int tmp;
    cout << "Enter update stock number : ";
    cin >> tmp;

    if (tmp == 1546)
    {
        cout << "Enter amount of covaccin vaccines : ";
        cin >> tmp;
        vaccine_stock_coVaccin += tmp;

        cout << "Enter amount of covishield vaccines : ";
        cin >> tmp;
        vaccine_stock_coviShield += tmp;

        for (int i = 0; i < 5; i++)
        {
            int x = 0;
            cout << "Enter numbers for item of index " << i << ": ";
            cin >> x;
            items_stock[i] += x;
        }
        cout << "** Stock updated **\n\n\n";
    }
    else
    {
        cout << "Wrong Number !!!" << endl;
        return;
    }
}

int main()
{
    record data;
    vaccine Vaccine[10000];
    int idx_of_customer = 0;
    int idx_of_vaccine = 0;

    for(int i=0; i<10000;i++)
    {
        dozes[i].enqueue(1);
        dozes[i].enqueue(2);
    }

    cout << "\n\nWelcome to Covid Health Store !!\n";
    cout << "** Wear mask, Sanitize yourself and be Safe  **\n\n\n";

    while (true)
    {
        int tmp;
        cout << "1 - Stock Update\n2 - Medicine store\n3 - Vaccine registration program\n4 - close store\n";
        cin >> tmp;

        if (tmp == 4)
        {
            break;
        }
        switch (tmp)
        {
            case 1:
            {
                update_stock();
                break;
            }

            case 2:
            {
                if (idx_of_customer < 10000)
                {
                    customer X;
                    X.set_ID(idx_of_customer);
                    X.get_data(idx_of_customer);
                    data.add_entry(X);
                    idx_of_customer++;
                }
                break;
            }

            case 3:
            {
                char check;
                cout << "Have you got 1st doze ? ('y' or 'n') : ";
                cin >> check;

                if (check == 'y')
                {
                    int vaccine_ID;
                    cout << "Enter your vaccine ID : ";
                    cin >> vaccine_ID;
                    long long int phone_number;
                    cout << "Enter your phone number : ";
                    cin >> phone_number;
                    int idx = (vaccine_ID-17)%10000;
                    second_doze(Vaccine[idx],vaccine_ID,phone_number);
                }
                else
                {
                    if (idx_of_vaccine < 10000)
                    {
                        Vaccine[idx_of_vaccine].set_ID(idx_of_vaccine);
                        Vaccine[idx_of_vaccine].get_data(idx_of_vaccine);

                        idx_of_vaccine++;
                    }
                }
                break;
            }

            default:
                cout << "Please Enter valid number....\n";
                break;
        }
    }

    return 0;
}
