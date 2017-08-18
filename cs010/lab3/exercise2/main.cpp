#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     cout << "Enter your first name: ";
     string first_name;
     cin >> first_name;
     
     cout << "Enter your middle initial: ";
     string middle_initial;
     cin >> middle_initial;
     
     cout << "Enter your last name: ";
     string last_name;
     cin >> last_name;
     
     cout << "Here are some email address suggestions: "
          << endl;
     
     cout << left
          << first_name.substr(0,1) 
          << setw(19)
          << last_name
          
          << first_name
          << setw(20-first_name.size())
          << last_name.substr(0,1)
          
          << first_name.substr(0,1)
          << middle_initial
          << setw(18)
          << last_name.substr(0,1)
          << endl;
     
     cout << first_name
          << middle_initial
          << setw(19-first_name.size())
          << last_name.substr(0,1)
          
          << first_name.substr(0,1)
          << middle_initial
          << setw(18)
          << last_name

          
          << first_name
          << "."
          << setw(19-first_name.size()-last_name.size())
          << last_name
          << endl;
          
     return(0);
}
