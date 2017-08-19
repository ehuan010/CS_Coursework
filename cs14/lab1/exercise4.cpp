//number 5
#include <iostream>
using namespace std;

int main()
{
  cout << "Input a positive integer: ";
  int posint;
  cin >> posint;
  if(posint == 1)
  {
    cout << "1 ";
  }
  else
  {
    cout << "1 2 2 ";
    int prevnum = 2;
    int num = 2;
    int printnum = 0;
    while(prevnum*num <= posint)
    {
      printnum = num * prevnum;
      cout << printnum << " ";
      prevnum = num;
      num = printnum;
    }
  }
  return 0;
}
