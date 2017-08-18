#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

void swap(int& one, int& two)
{
int temp;
temp = one;
one = two;
two = temp;
}

void order(int& one, int& two, int& three)
{
  if(one<two && two<three)
  {
  }
  else if(one>two && one>three && two>three)
  {
    swap(one, three);
  }  
  else if(three<one && three<two && one < two )
  {
    swap(one, three);
    swap(two, three);
  }
  else if(one > three && one > two && two > one)
  {
    swap(one, three);
    swap(two, three);
    }
  else if(one<two && three < two)
  {
    swap(two, three);
  }
  else if(one<three && two<one)
  {
    swap(one, two);
  }
  else if(three < one && three<two)
  {
    swap(three,one);
    swap(two, three);
  }
  else if(three<two && one>three)
  {
    swap(one, three);
  }
  else if(one>two && two <three)
  {
    swap(one, two);
    swap(two, three);
  }
  else if(one>two && one < three)
  {
    swap(one, three);
    swap(two, three);
  }    
  else if(two< one && two < three && one < three)
  {
    swap(one, two);
  }
  else if(one>three && two<three && one < two)
  {
    swap(one, three);
  }
}


int main()
{
  cout <<"Input three integers with spaces in between each integer: ";
  int one;
  int two;
  int three;
  cin >> one;
  cin >> two;
  cin >> three;
  
  order(one, two, three);
  cout << "Ascending order: " << one << " " << two << " " << three << endl;
  
  return 0;
}
