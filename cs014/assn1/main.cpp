/*
 * main.cpp
 *
 *  Created on: Jan 9, 2010, edit Jun 30, 2012
 *      Author: rusichr
 */

#include <iostream>
#include <vector>
#include "MyList.h"

using namespace std;

int main(){
  
  char c = 'a';
  MyList l1;
  
  // remove_zeros not part of assn1 specs
  l1.remove_zeroes();
  
  cout << "push_back z: " ;
  l1.push_back('z');
  l1.print();
  
  l1.pop_back();
  cout << "pop_back z: " ;
  l1.print();
  
  cout << "push_back 0 0 z 0 z: " ;
  l1.push_front('0');
  l1.push_front('0');
  l1.push_front('z');
  l1.push_front('0');
  l1.push_front('z');
  l1.print();
  
  int loc_size = l1.size();
  cout << "array style print: " ;
  for(int i = 0; i < loc_size; i++)
    cout << l1[i] << " ";
  cout << endl;
  
  cout << "insert_at_pos a 0 on left and right of middle z: " ;
  l1.insert_at_pos(2, '0');
  l1.insert_at_pos(5, '0');
  l1.print();
  
  cout << "push_back 10 zero chars: " ;
  for(int i = 0; i < 10; i++)
    l1.push_back('0');
  l1.print();
  
  cout << "push_back letters f-j: ";
  for(int i = 0; i < 10; i++)
    l1.push_back(c+i);
  l1.print();
  
  cout << "remove_zeros: ";
  l1.remove_zeroes();
  l1.print();
  
  cout << "pop_front z z: ";
  for(int i = 0; i < 2; i++)
    l1.pop_front();
  l1.print();
  
  cout << "pop_back f-j: ";
  for(int i = 0; i < 5; i++)
    l1.pop_back();
  l1.print();
  
  cout << "reverse odd sized list: ";
  l1.reverse();
  l1.print();
  
  cout << "push_front f: ";
  l1.push_front('f');
  l1.print();
  
  cout << "reverse even sized list: ";
  l1.reverse();
  l1.print();
  
  // make some copies for later use
  cout << "Construct new lists l2,l3,l4:\n";
  cout << "MyList l4(l1);\nMyList l3 = l4;\nMyList l2(l3);" << endl;
  MyList l4(l1);
  MyList l3 = l4;
  MyList l2(l3);
  
  // This section could be made into a function
  /**************************************************************************/
  cout << "pop_back entire list, l1: ";
  loc_size = l1.size();
  
  for(int i = 0; i < loc_size; i++)
    l1.pop_back();
  l1.print();

  cout << "reverse empty list, l1: ";
  l1.reverse();
  l1.print();
  /**************************************************************************/
  cout << "pop_back entire list but one item, l2: ";
  loc_size = l2.size();
  
  for(int i = 0; i < loc_size-1; i++)
    l2.pop_back();
  l2.print();;
  
  cout << "reverse one item list, l2: ";
  l2.reverse();
  l2.print();
  /**************************************************************************/
  
  /**************************************************************************/
  cout << "pop_back entire list but two items, l3: ";
  loc_size = l3.size();
  
  for(int i = 0; i < loc_size-2; i++)
    l3.pop_back();
  l3.print();
  
  cout << "reverse two item list, l3: ";
  l3.reverse();
  l3.print();
  /**************************************************************************/
  
  cout << "list l4: ";
  l4.print();
  
  cout << "list l4 + l3: ";
  l4 + l3; // do not have to do assignment
  l4.print();
  
  cout << "list l4 + l2: ";
  l4 + l2; // do not have to do assignment
  l4.print();
  
  cout << "list l4 + l1: ";
  l4 + l1; // do not have to do assignment
  l4.print();
  
  cout << "Good Bye!" << endl;
  return 0;
}
