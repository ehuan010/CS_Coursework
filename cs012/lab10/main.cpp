#include "intlist.h"

int main()
{
  //IntNode node;
  IntList list;
  list.push_front(10);
  list.push_front(5);
  list.push_back(15);
  list.insert(0,100);
  list.insert(3,3);
  list.erase(3);
  list.push_back(700);
  list.pop_front();
  list.print();
  
  return 0;
}
