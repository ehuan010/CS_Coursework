#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "dog.h"

using namespace std;

class Person
{
  private:
  
  string name;
  Dog* dog;
  
  public:
  
  Person();
  Person(const string &name);
  Person(const string &name, Dog *dog);
  void print();
};

#endif
