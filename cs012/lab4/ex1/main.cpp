#include <iostream>
#include "person.h"

using namespace std;

int main()
{
  Dog* pet = new Dog("Fido", "Golden Retriever");
  
  Person sally = Person("Sally",pet);
  Person tron = Person("Tron");
  Person bob = Person("Bob",pet);
  sally.print();
  tron.print();
  bob.print();
  pet->new_name("Clifford");
  sally.print();
  tron.print();
  bob.print();
  
}
