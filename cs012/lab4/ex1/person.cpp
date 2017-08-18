#include <iostream>
#include "person.h"

using namespace std;

Person::Person()
:name(),dog(NULL)
{
}

Person::Person(const string &name)
:name(name),dog(NULL)
{
}

Person::Person(const string &name, Dog *dog)
:name(name),dog(dog)
{
}

void Person::print()
{
  cout << name << endl << "     " ; 
  if(dog != NULL)
  {
    dog->printn();
  }
  cout << endl;
}
