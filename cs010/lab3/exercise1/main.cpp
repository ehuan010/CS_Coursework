#include <iostream>
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
     
     cout << first_name.substr(0,1)
          << middle_initial.substr(0)
          << last_name.substr(0,1) 
          << last_name.size()
          << endl;
          
     cout << first_name 
          << last_name.substr(0,1) 
          << first_name.size()
          << endl;
          
     cout << first_name.substr(0,1)
          << last_name
          << first_name.size() + last_name.size()
          << endl;
          
     return(0);
}
