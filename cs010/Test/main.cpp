#include <iostream>
#include <string>
using namespace std;

int main()
{
     cout << "Please enter string:";
     string a;
     cin >> a;
     getline(cin,a);
     cout << a;
     return(0);
}
