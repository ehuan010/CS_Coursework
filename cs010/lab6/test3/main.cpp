#include <iostream>
using namespace std;

int main()
{
    int num;
    int num2;
    int x;
    int total = 0;
    
    do
    {
        cout << "Enter an integer: ";
        cin >> num;
        cout << "Enter another integer: ";
        cin >> num2;
    }
    while(num > num2);
    
    for(x = num; x <= num2; x++)
    {
        if(x < num2)
        {
            cout << x << " + ";
        }
        else
        {
            cout << x << " = ";
        }
    total += x;
    }
    cout << total
         << endl;
    
    return 0;
}
