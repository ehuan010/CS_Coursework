//number 3
#include <iostream>
using namespace std;

int count_odd(int num)
{
  if(num < 10)
  {
    return num%2;
  }
  
  if( (num%10)%2 == 1 )
  {
    return 1 + count_odd(num/10);
  }
  else
  {
    return count_odd(num/10);
  }
  
}

int main()
{
  int a = 1111444556;
  int total_odd_ints = count_odd(a);
  cout << total_odd_ints << endl;
  return 0;
}
