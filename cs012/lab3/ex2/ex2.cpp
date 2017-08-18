#include <iostream>

using namespace std;

int main()
{
  int val(42);
  int* int_ptr = new int;
  *int_ptr = 21;
  int* val_ptr1 = &val;
  int* val_ptr2 = &val;
  *val_ptr2 = *val_ptr2 + 100;
  
  cout << val << endl;
  cout << int_ptr << " " << *int_ptr << endl;
  cout << val_ptr1 << " " << *val_ptr1 << endl;
  cout << val_ptr2 << " " << *val_ptr2 << endl;
  
  cout << endl;
  
  val_ptr1 = int_ptr;
  cout << val << endl;
  cout << int_ptr << " " << *int_ptr << endl;
  cout << val_ptr1 << " " << *val_ptr1 << endl;
  cout << val_ptr2 << " " << *val_ptr2 << endl;
  delete int_ptr;
  return 0;
}
