#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     cout << fixed
          << setprecision(2)
          << "CASH REGISTER/CHANGE CALCULATOR\n";
     
     //user input
     cout << "Enter purchase amount: ";
     double purchase_amount;
     cin >> purchase_amount;
     
     cout << "Enter amount received: ";
     double amount_received;
     cin >> amount_received;
     
     //line break
     cout << endl;
     
     double total_change = amount_received - purchase_amount;
     //calculation
     cout << "Total Change: $"
          << total_change
          << endl;
     
     //line break
     cout << endl;
     
     total_change = total_change * 100;
     int cents = static_cast <int>(total_change+0.5);
     int dollar_bills = cents/100;    //integer 1
     cents = cents%100;    //integer 71
     int quarters = cents/25;   // integer 2
     cents = cents%25;   //remainder of coins 21
     int dimes = cents/10; // two dimes
     cents = cents%10;
     int nickels = cents/5; // should be 0 because 1 cent left
     cents = cents%5;
     int pennies = cents/1; 
     
     
     //each type of currency to give back to the customer
     cout << right
          << a
          << "dollars "
          << left
          << dollar_bills
          << endl;
          
     cout << right
          << a
          << "quarters "
          << left
          << quarters
          << endl;
          
     cout << right
          << a
          << "dimes "
          << left
          << dimes
          << endl;
          
     cout << right
          << a
          << "nickels "
          << left
          << nickels
          << endl;
          
     cout << right
          << a
          << "pennies "
          << left
          << pennies
          << endl;
          
     return(0);
}
