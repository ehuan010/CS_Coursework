#include <iostream>
using namespace std;

int main()
{
     cout << "Enter an integer: ";
     int integer;
     cin >> integer;
     int even = integer%2;
     if(even == 0)
     {
          cout << "The integer is even" << endl;
     }
     else
     {
          cout << "The integer is odd" << endl;
     }
     return (0);
}
