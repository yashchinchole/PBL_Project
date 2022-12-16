#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;

int dis_choice;

class bill
{
public:
    float total_bill;
    bill()
    {
        total_bill = 0;
    }
};

class travel : public bill
{
public:
    int d_city, a_city, mode;
    float travel_bill, return_travel_bill = 0;

    void place();
    void mean();
    void travel_invoice();
    void return_invoice();
};

class hotel : public travel
{
public:
    float hotel_bill = 0;

    void hotel_invoice();

    void display(string user)
    {
        fstream f;
        string cities_arr[3] = {"DELHI", "MUMBAI", "CHENNAI"};
        string mode_arr[3] = {"Airplane", "Train", "Bus"};
        cout << "\n\n\n\t\t\t\t\tINVOICE\n";
        cout << "\tYOUR TRAVEL BILL FROM " << cities_arr[d_city - 1] << " TO " << cities_arr[a_city - 1] << " IS :Rs " << travel_bill;
        cout << "\n\tYOUR OPTED MODE OF TRANSFORMATION IS : " << mode_arr[mode - 1];
        cout << "\n\tYOUR RETURN TRAVEL BILL IS :Rs " << return_travel_bill;
        cout << "\n\tYOUR HOTEL BILL IS :Rs " << hotel_bill;
        cout << "\n\n\tGRAND TOTAL :Rs " << total_bill;
        f.open("TRIP PLANNER.txt", ios::app | ios::out);
        f << "User name:" << user << endl
          << "Departure city: " << cities_arr[d_city - 1] << endl
          << "Departure city: " << cities_arr[a_city - 1] << endl
          << "Mode of transport: " << mode_arr[mode - 1] << endl
          << "Travel bill:Rs " << travel_bill << endl
          << "Return bill:Rs " << return_travel_bill << endl
          << "Hotel bill:Rs " << hotel_bill << endl
          << "Total bill:Rs " << total_bill << endl
          << "-----------------------" << endl;

        f.close();
    }
};

void travel ::place()
{
    int p;
xyz:
    cout << "\nDestinations : \n1)Delhi\n2)Mumbai\n3)Chennai";

    cout << "\n\nEnter The Choice of City (Departure) : ";
    cin >> d_city;

    cout << "\nEnter The Choice of city (Arrival) : ";
    cin >> a_city;
    try
    {

        if (a_city == d_city)
        {
            p = 1;
            throw(p);
        }
    }
    catch (int p)
    {
        cout << "\n\t\t !!!exception occured!!!" << endl
             << "arrival and departure city cannot be same you will get a round trip option later."
             << endl
             << endl;
        goto xyz;
    }
}

void travel ::mean()
{
    cout << "\nMode Of Transport:\n1)Airplane\n2)Train\n3)Bus ";
    cout << "\nEnter Choice : ";
    cin >> mode;

    if (a_city == 1)
    {
        if (mode == 1)
        {
            cout << "\nCost = 5000/-";
            travel_bill = 5000;
        }

        else if (mode == 2)
        {
            cout << "\nCost = 4000/-";
            travel_bill = 4000;
        }

        else if (mode == 3)
        {
            cout << "\nCost = 3000/-";
            travel_bill = 3000;
        }
    }

    else if (a_city == 3)
    {
        if (mode == 1)
        {
            cout << "\nCost = 4000/-";
            travel_bill = 4000;
        }

        else if (mode == 2)
        {
            cout << "\nCost = 2500/-";
            travel_bill = 2500;
        }

        else if (mode == 3)
        {
            cout << "\nCost = 2000/-";
            travel_bill = 2000;
        }
    }

    else if (a_city == 2)
    {
        if (mode == 1)
        {
            cout << "\nCost = 6000/-";
            travel_bill = 6000;
        }

        else if (mode == 2)
        {
            cout << "\nCost = 5500/-";
            travel_bill = 5500;
        }

        else if (mode == 3)
        {
            cout << "\nCost = 2500/-";
            travel_bill = 2500;
        }
    }
}

void travel ::travel_invoice()
{

abc:
    cout << "\n\nAre you a : \n1)Student\n2)Business\n3)Tourist\n";
    cin >> dis_choice;

    if (dis_choice == 1)
    {
        cout << "\nYou are eligible for 15% Student's Discount.";
        travel_bill = travel_bill - (travel_bill * 0.15);
    }

    else if (dis_choice == 2)
    {
        cout << "\nYou are eligible for 20% Co-operate Discount.";
        travel_bill = travel_bill - (travel_bill * 0.2);
    }

    else if (dis_choice == 3)
    {
        cout << "\nSorry! Being Tourist You are not eligible for any Discount.";
    }

    else
    {
        cout << "Wrong Choice.";
        goto abc;
    }

    total_bill = total_bill + travel_bill;
}

void travel ::return_invoice()
{
    if (d_city == 1)
    {
        if (mode == 1)
        {
            cout << "\nCost = 3500/-";
            return_travel_bill = 3500;
        }

        else if (mode == 2)
        {
            cout << "\nCost = 2800/-";
            return_travel_bill = 2800;
        }

        else if (mode == 3)
        {
            cout << "\nCost = 2100/-";
            return_travel_bill = 2100;
        }
    }

    else if (d_city == 3)
    {
        if (mode == 1)
        {
            cout << "\nCost = 2800/-";
            return_travel_bill = 2800;
        }

        else if (mode == 2)
        {
            cout << "\nCost = 1750/-";
            return_travel_bill = 1750;
        }

        else if (mode == 3)
        {
            cout << "\nCost = 1400/-";
            return_travel_bill = 1400;
        }
    }
    else if (d_city == 2)
    {
        if (mode == 1)
        {
            cout << "\nCost = 4200/-";
            return_travel_bill = 4200;
        }

        else if (mode == 2)
        {
            cout << "\nCost = 3850/-";
            return_travel_bill = 3850;
        }

        else if (mode == 3)
        {
            cout << "\nCost = 1750/-";
            return_travel_bill = 1750;
        }
    }

    total_bill += return_travel_bill;
}

void hotel ::hotel_invoice()
{
    int hotel_choice, stay;
    float base_price;

    if (a_city == 1)
    {
        cout << "\n\nHotel in Your Arrival City : ";
        cout << "\n1)JW Marriot\n2)Le Meridian\n3)Hyatt";

        cout << "\nEnter Hotel Choice : ";
        cin >> hotel_choice;

        cout << "\nEnter the number of days : ";
        cin >> stay;

        switch (hotel_choice)
        {
        case 1:
        {
            base_price = 1500;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        case 2:
        {
            base_price = 1250;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        case 3:
        {
            base_price = 1000;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        default:
            cout << "Wrong Choice";
        }
    }

    else if (a_city == 2)
    {
        cout << "\n\nHotel in Your Arrival City : ";
        cout << "\n1)Taj Hotel\n2)Oberoy\n3)Hotel Diamond";

        cout << "\nEnter Hotel Choice : ";
        cin >> hotel_choice;

        cout << "\nEnter the number of days : ";
        cin >> stay;

        switch (hotel_choice)
        {
        case 1:
        {
            base_price = 2500;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        case 2:
        {
            base_price = 2000;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        case 3:
        {
            base_price = 1800;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        default:
            cout << "Wrong Choice";
        }
    }

    else if (a_city == 3)
    {
        cout << "\n\nHotel in Your Arrival City : ";
        cout << "\n1)Double Tree Hilton\n2)Keys\n3)Regency";

        cout << "\nEnter Hotel Choice : ";
        cin >> hotel_choice;

        cout << "\nEnter the number of days : ";
        cin >> stay;

        switch (hotel_choice)
        {
        case 1:
        {
            base_price = 1850;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        case 2:
        {
            base_price = 1500;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        case 3:
        {
            base_price = 1300;

            cout << "\n1-Night Stay Cost : " << base_price;

            hotel_bill = base_price * stay;

            break;
        }

        default:
            cout << "Wrong Choice";
        }
    }

    else
        cout << "Invalid City";

    if (dis_choice == 1)
    {
        cout << "\nYou are eligible for 10% Student's Discout.";
        hotel_bill = hotel_bill - (hotel_bill * 0.1);
    }

    else if (dis_choice == 2)
    {
        cout << "\nYou are eligible for 15% Co-operate Discount.";
        hotel_bill = hotel_bill - (hotel_bill * 0.15);
    }

    else if (dis_choice == 3)
    {
        cout << "\nSorry! Being Tourist You are not eligible for any Discount.";
    }

    total_bill += hotel_bill;
}

int main()
{
    cout << endl
         << "\t\t........................." << endl
         << "\t\t|  TRIP PLANNER SYSTEM  |" << endl
         << "\t\t........................." << endl;

    int choice, ch;
    string user;
    cout << endl
         << "Enter your name:";
    cin >> user;
    cout << endl
         << "\nDo you Want to Generate Bill for Your journey.";
    cout << "Enter : \n1)Yes\n2)No\n";
    cin >> choice;

    if (choice == 1)
    {
        hotel t;

        t.place();
        t.mean();
        t.travel_invoice();

        cout << "\n\nDo You Want A Round Trip?\n1)Yes\nAny Other Key for No\n ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "\nYou Will get 30% discount on Return Tickets.";
            t.return_invoice();
        }

    pqr:
        cout << "\n\nDo You Want to Generate a bill for a Hotel?\n1)yes\n2)No\n";
        cin >> ch;

        if (ch == 1)
        {
            t.hotel_invoice();

            t.display(user);

            cout << "\n\nThank You For Choosing Our Services.";
            return 0;
        }

        else if (ch == 2)
        {
            t.display(user);

            cout << "\n\nThank You For Choosing Our Services.";
            return 0;
        }

        else
        {
            cout << "\nWrong Option";
            goto pqr;
        }
    }

    else if (choice == 2)
    {
        cout << "\n\nThank You For Choosing Our Services.";
        return 0;
    }

    else
    {
        cout << "\nWrong Option.";
        return 0;
    }
}