#include <iostream>
using namespace std;

int main()
{
    int num;
    int num2;
    int total = 0;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Enter another integer: ";
    cin >> num2;
    while(num >= num2)
    {
        cout << "Enter an integer: ";
        cin >> num;
        cout << "Enter another integer: ";
        cin >> num2;
    }
    cout << num;
    while(num < num2)
    {
         
        total += num;
        num++;
        cout << " + "
             << num;
    }
    cout <<" = "
         << total + num2
         << endl;
    
    return 0;
}
