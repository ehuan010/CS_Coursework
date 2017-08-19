//number four
#include <iostream>
using namespace std;

void swap(int &val1, int &val2)
{
  val1 = val1 + val2;
  val2 = val1 - val2;
  val1 = val1 - val2;
}

int main()
{
  int a = -15;
  int b = -7;
  swap(a, b);
  cout << a << " " << b << endl;
  
  return 0;
}
