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

  // Return the number of elements
  int size() const {return sz;}
  
  // Returns true if the element is in the set,false otherwise
  bool exists(int elem) const;

  // Compute the intersection with the specified set. 
  // Update this set with the result
  void intersect(const Set &s);
  
  // True if the specified set is completely contained on this set
  // False otherwise
  bool isSubset(const Set &s);

  void printSet();

private:
  void doubleSpace();
  int binarySearch(int key, int imin, int imax) const ;
  int sz;
  int reserved;
  int* data;
};

void Set::doubleSpace() {
  int* newdata = new int[reserved*2];
  for(int i = 0; i < reserved; i++) {
    newdata[i] = data[i];
  }
  reserved = reserved*2;
  delete[] data;
  data = newdata;
}

Set::Set(int reserve=10) {
  data = new int[reserve];
  reserved = reserve;
  sz = 0;
}

Set::~Set() {
  delete[] data;
}

void Set::add(int elem) {}

void Set::intersect(const Set &s) {}

bool Set::isSubset(const Set &s) {
  return 0;
}


bool Set::exists(int elem) const {}

int Set::binarySearch(int key, int imin, int imax) const {}


int main() {
  srand(10);

  Set s1;
  Set s2;
  Set s3;
  
  for (int i = 0 ; i < 100; i++) {
    s1.add(i);
  }

  s2.add(30);
  s2.add(0);
  s2.add(1);

  s1.printSet();
  s2.printSet();
  s1.intersect(s2);

  s1.printSet();
  cout << s1.isSubset(s1) << endl;
  cout << s1.isSubset(s2) << endl;
  cout << s1.isSubset(s3) << endl;
}
