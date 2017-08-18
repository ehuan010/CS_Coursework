#include <iostream>
#include "dog.h"

using namespace std;

Dog::Dog()
:name(""),breed("")
{
}

Dog::Dog(const string &name)
:name(name),breed("")
{
}

Dog::Dog(const string &name, const string &breed)
:name(name),breed(breed)
{
}

string Dog::new_name(const string &newname)
{
  this->name = newname;
  return this->name;
}


void Dog::printn()
{
  if(name != "" && breed == "")
  {
    cout << name;
  }
  else if(name != "" && breed != "")
  {
    cout << name << " : " << breed;
  }
  else
  {
  }
}
