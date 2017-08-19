#define UNDEFINED -1


#include <cstdlib>
#include <iostream>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

template <class HashFunction > 
class Dictionary {
 public:
  Dictionary(HashFunction hashFunction);
  ~Dictionary();
  string find(int key);
  void   add(int k, string value);
  int    getSize() const {return size;};
  int    getCapacity() const {return capacity;};
  double currentLoad() const {return (double) size/capacity;};
 private:
  HashFunction      hashFunction;
  pair<int,string>  *entries;
  int               capacity;
  int               size;  
};


class Naive {
 public:
int operator()(int x) {return x;}
} naive;

