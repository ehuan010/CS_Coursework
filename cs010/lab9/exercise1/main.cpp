#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int>integers(10);
  cout << "Enter "
       << integers.size()
       << " integers: ";
       
  for(int i = 0; i < integers.size(); i++)
  {
    cin >> integers[i];
  }
  
  
  cout << "Forward: ";
  for(int i = 0; i < integers.size(); i++)
  {
    cout << integers[i]
         << " ";
  }
  
  cout << endl
       << "Reverse: ";
  for(int i = integers.size()-1; i >= 0; i--)
  {
    cout << integers[i]
         << " ";
  }
  
  cout << endl
       << ">= 10: ";
  for(int i = 0; i < integers.size(); i++)
  {
    if(integers[i] >= 10)
    {
      cout << integers[i]
           << " ";
    }
  }
  
  cout << endl
       << "Max: ";
  int largest_so_far = integers[0];
  for(int i = 1; i < integers.size(); i++)
  {
    if(integers[i] > largest_so_far)
    {
      largest_so_far = integers[i];
    }
  }
  cout << largest_so_far
       << endl
       << "Min: ";
  
  int smallest_so_far = integers[0];
  for(int i = 1; i < integers.size(); i++)
  {
    if(integers[i] < smallest_so_far)
    {
      smallest_so_far = integers[i];
    }
  }
  cout << smallest_so_far
       << endl;
  return 0;
}
