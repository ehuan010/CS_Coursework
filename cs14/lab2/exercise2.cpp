#include <iostream>

using namespace std;

int counter = 0;

int xtopowerofn(int x, int n)
{
  counter += 1;
  if(x == 0)
  {
    return 0;
  }
  if(n == 0)
  {
    return 1;
  }
  if(n == 1)
  {
    return x;
  }
  else
  {
    return x * xtopowerofn(x, n-1);
  }
}

int improvedXtoN(int x, int n)
{
  counter += 1;
  if(x == 0)
  {
    return 0;
  }
  if(n == 0)
  {
    return 1;
  }
  if(n == 1)
  {
    return x;
  }
  
  if(n%2 == 0)
  {
    int temp = improvedXtoN(x, n/2);
    return temp * temp;
  }
  else
  {
    int temp = improvedXtoN(x, n/2);
    return x * temp * temp;
  }
}

int main()
{
  int x = 2;
  int n = 5;
  //change function call
  int solution = xtopowerofn(x,n);
  //int solution = improvedXtoN(x,n);
  cout << "Solution: " << solution << endl;
  cout << "# times called: " << counter << endl;
  
  
  return 0;
}
