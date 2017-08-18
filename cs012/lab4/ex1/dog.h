#ifndef DOG_H
#define DOG_H
#include <string>

using namespace std;

class Dog
{
  private:
  
  string name;
  string breed;
  
  public:
  
  Dog();
  Dog(const string &name);
  Dog(const string &name, const string &breed);
  string new_name(const string &newname);
  void printn();
};

#endif
