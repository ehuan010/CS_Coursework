/**
 ** Implements the ADT Set using an sorted array as backup.
 ** Student Names:
 **
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Set {
public:
  //Create a new vector
  Set(int reserve);
  //Destructor
  ~Set();
  //Add a new element to the set
  void add(int elem);
  // Returns true if the element is in the set,false otherwise
  bool exists(int elem);
  void printSet();
private:
  void doubleSpace();
  int binarySearch(int key, int imin, int imax);
  int* data;
  int sz;
  int reserved;
};


Set::Set(int reserve=1) {
  data = new int[reserve];
  reserved = reserve;
  sz = 0;
}

Set::~Set() {
  delete[] data;
}


void Set::doubleSpace() {
    int* newdata = new int[reserved*2];
    for(int i = 0; i < reserved; i++) {
      newdata[i] = data[i];
    }
    reserved = reserved*2;
    data = newdata;
}

void Set::add(int elem) {
  if (sz == reserved) {
    doubleSpace();
  }
  //Find where we are inserting

  //We return if we find the element already on the set
  
  //We move all the elements after i 

  //Finally we add the element and update the size
}



bool Set::exists(int elem) {
  //Call internal method

}

int Set::binarySearch(int key, int imin, int imax)
{
  //You can get this from wikipedia but be careful
}

void Set::printSet() {
  cout << "{";
  for (int i = 0; i < sz; i++) {
    cout << data[i] << " ";
  }
  cout << "}" << endl;
}


int main() {
  srand(10);
  Set s;
  for (int i = 0; i < 10000; i++) {
    int elem = rand()%500;  
    if (elem != 0 && elem != 354 && elem != 499) s.add(elem);
  }
  s.printSet();

  cout << "exists 1: " << s.exists(1)      << endl;
  cout << "exists 12: " << s.exists(12)    << endl;
  cout << "exists 354: " << s.exists(354)  << endl;
  cout << "exists 357: " << s.exists(357)  << endl;
  cout << "exists 498: " << s.exists(498)  << endl;
  cout << "exists 499: " << s.exists(499)  << endl;
}
