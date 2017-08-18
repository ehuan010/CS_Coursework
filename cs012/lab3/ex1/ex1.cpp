#include <iostream>

using namespace std;

int main()
{
  int num(12);
  
  int* i_ptr_a;
  //cout << *i_ptr_a << endl; SEGMENTATION FAULT
  //delete i_ptr_a;  cannot delete this pointer
  
  int* i_ptr_b = NULL;
  //cout << *i_ptr_b << endl; SEGMENTATION FAULT
  //delete i_ptr_b;  cannot delete this pointer
  
  int* i_ptr_c = &num;
  cout << *i_ptr_c << endl;
  //delete i_ptr_c; cannot delete this pointer
  
  int* i_ptr_d = i_ptr_c;
  cout << *i_ptr_d << endl;
  //delete i_ptr_d; cannot delete this pointer
  
  int* i_ptr_e = new int;
  *i_ptr_e = 10;
  cout << *i_ptr_e << endl;
  delete i_ptr_e;
  
  return 0;
}
