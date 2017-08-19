#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int luckyRun(double d[], int k, int size)
{
  int i = 0;
  int inarow = 0;
  while(inarow != k && i < size)
  {
    if(d[i] >= 0.5)
    {
      inarow += 1;
      i += 1;
    }
    else
    {
      inarow = 0;
      i += 1;
    }
  }
  if(inarow == k)
  {
    return i;
  }
  else
  {
    return -1;
  }
}


int main() {
  //Pseudo Random number generator always return the same sequence unless we change the seed
  // We use the current time
  srand48(time(NULL));
  
  double numbers[100];
  for(int i = 0; i < 100; ++i)
  {
    numbers[i] = drand48();
  }
  
  int k = 5;
  int size = 100;
  int test = luckyRun(numbers, k, size);
  
  //best case is k
  //worst case go through entire array
  
  for (int k = 0; k < 100; k ++) {
    //Generate 100 random numbers
    cout << drand48()  << endl; 
  }
  cout << "Index number: " << test << endl;
}


