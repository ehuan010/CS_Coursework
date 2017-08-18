#include <iostream>

using namespace std;

void extend(string* &str_array, unsigned int &capacity)
{
  unsigned int new_capacity = capacity * 2;
  string* str_array2 = new string[new_capacity];
  for(unsigned int j = 0; j < capacity; j++)
  {
    str_array2[j] = str_array[j];
  }
  delete [] str_array;
  str_array = str_array2;
  capacity = new_capacity;
}

//capacity, current size, and starting address
void push_back(string &str, string* &str_array,unsigned int size, 
               unsigned int &capacity)
{
  if((size) == capacity)
  {
    extend(str_array, capacity);
  }
  str_array[size-1] = str;
}


double average_size(string* str_array, unsigned int size)
{
  double total = 0.0;
  for(unsigned int j = 0; j < size; ++j)
  {
    total = total + (str_array[j]).size(); 
  }
  total = total/size;
}

void print(string* str_array, unsigned int capacity)
{
  for(unsigned int j = 0; j < capacity; ++j)
  {
    cout << str_array[j] << " ";
  }
}

int main()
{
  unsigned int size = 0;
  unsigned int capacity = 3;
  string* test = new string[capacity];
  
  cout << "Enter string ('.' to quit)." << endl;
  string new_string;
  do
  {
    cin >> new_string;
    if(new_string != ".")
    {
      size++;
      push_back(new_string, test, size, capacity);
    }
  }while(new_string != ".");
  
  print(test,size);
  cout << "\nAverage size of strings in array: " 
       << average_size(test,size) << endl;
  
  return 0;
}
