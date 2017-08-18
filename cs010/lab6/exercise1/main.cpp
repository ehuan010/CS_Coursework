#include <iostream>
using namespace std;

int main()
{
    int day;
    int grains = 1;
    int total_grains = 0;
    
    for(day=1;day<=30;day++)
    {
        total_grains = total_grains + grains;
        grains = grains * 2;
        cout << "Day " 
             << day 
             << ": " 
             << total_grains
             << " grains of rice" 
             << endl;
    }
    return 0;
}
