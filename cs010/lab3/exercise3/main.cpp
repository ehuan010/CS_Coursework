#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     cout << "Enter a floating-point number with 4 decimal places: ";
     double decimal_number;
     cin >> decimal_number;
     
     cout << endl;
     
     //first line
     cout << fixed
          << setprecision(0)
          << left
          << setw(10)
          << decimal_number
          << decimal_number
          << endl;
          
     cout << setprecision(1)
          << setw(10)
          << decimal_number
          << decimal_number
          << endl;
          
     cout << setprecision(2)
          << setw(10)
          << decimal_number
          << decimal_number
          << endl;
          
     cout << setprecision(3)
          << setw(10)
          << decimal_number
          << decimal_number
          << endl;
          
     cout << setprecision(4)
          << setw(10)
          << decimal_number
          << decimal_number
          << endl;
          
     return(0);
}
