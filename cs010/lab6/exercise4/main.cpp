#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    
    const int A = 1;
    const int B = 100;
    const int HEADS_TAILS = 50;
    
    int r = A + rand() % (B - A + 1);
    
    if(r<=HEADS_TAILS)
    {
        cout << r << endl << "heads\n";
    }
    else
    {
        cout << r << endl << "tails\n";
    }
    
    return 0;
}
