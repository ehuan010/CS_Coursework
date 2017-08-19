#include<iostream>

using namespace std;

//Simple Recursion
int sumArr(int a[], int sz) {
 if (sz == 0) return 0;
 else return a[sz-1] + sumArr(a,sz-1);
}
//fixed size of stack so might cause stack overflow. change size using
//ulimit -s unlimited    command and also g++ -O3 sum.cpp and other stuff

//Iterative version
int sumArrIt(int a[], int sz) {
  int s = 0;
  for(int i = 0; i < sz; i++) {
    s+=a[i];
  }
  return s;
}

//Hmmmm ....
int sumArrV2(int a[], int sz) {
  if (sz == 0) return 0;
  else {
    int* b = new int[sz-1];
    for(int i=1; i < sz;i++) {
      b[i-1] = a[i];
    }
    return a[0] + sumArrV2(b,(sz-1));
  }
}
//O(n^2)
//making copy of array is n^2 because it depends on size of array
//huge waste of space
//This causes the sumArrayV2 to not be able to finish

int main() {
  for (int k = 0; k < 25; k ++) {
    //Shift operator (See documentation)
    int sz = 1 << k;
    //Notice the array is created with new (why?)
    //The size of the array changes each time you go through the for loop.
    int* x = new int[sz];
    for(int i = 0; i < sz; i++) {
      x[i] = 1;
    }
    cout << sumArrV2(x,sz)  << endl; //Change the function called, compile and run
  }
}


/* Compiling and running: 
 *                        g++ sum.cpp -o prog && time ./prog
 *
 * DO NOT USE COMPILER OPTIMIZATIONS!!!
 */
 
 /**
  * Function     O-notation     User-Time     Finished(T/F)    
  * sumArrIt     O(n)           .580s         T
  * sumArr       O(n)           .203s         T
  * summArrV2    O(n^2)         infinite      F
  * 
  **/
