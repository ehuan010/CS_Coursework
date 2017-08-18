#include <iostream>

using namespace std;

int d(int n, int k)
{
  if(k == 0 || k == n)
  {
    return 1;
  }
  return d(n - 1, k - 1) + d(n - 1, k);
}

int main()
{
  cout << d(5,5) << endl;
  return 0;
}
