//number 6
#include <iostream>
using namespace std;

int f(int a)
{
  if(a == -2)
  {
    return 0;
  }
  
  if(a >= -2)
  {
    return a*a*a + 4*f(a - 1);
  }
  
}

int main()
{
  cout << "Enter number greater than -2: ";
  int num;
  cin >> num;
  int total = f(num);
  cout << total << endl;
  
  return 0;
}
