#include <iostream>
using namespace std;

int main()
{
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int F = 0;
    int entry;
    const int SENTINEL = -1;
    
    while(entry != SENTINEL)
    {
        cout << "Enter a score(-1 to quit): ";
        cin >> entry;
        if(entry >=90 && entry <=100)
        {
            A++;
        }
        else if(entry >=80 && entry <90)
        {
            B++;
        }
        else if(entry >=70 && entry <80)
        {
            C++;
        }
        else if(entry >=60 && entry <70)
        {
            D++;
        }
        else if(entry <60 && entry >=0)
        {
            F++;
        }
    }
    cout << A << "A's\n"
         << B << "B's\n"
         << C << "C's\n"
         << D << "D's\n"
         << F << "F's\n";
    return 0;
}
