//Exercise 3
/*Write a C++ class that implement two stacks using a single C++ array. 
 * That is, it should have functions popFirst(…), popSecond(…), 
 * pushFirst(…), pushSecond(…),… When out of space, double the size of 
 * the array (similarly to what vector is doing).
 */

#include <iostream>

using namespace std;

//Two stacks on ONE array

//A stack of integers
class Stack
{
  private:
  int size;
  int capacity;
  int topOfStackFirst;
  int topOfStackSecond;
  int* theArray;
  
  public:
  Stack();
  Stack(int a);
  ~Stack();
  void pushFirst(int dataOne);
  void pushSecond(int dataTwo);
  void popFirst();
  void popSecond();
  void print();
  int expand(); //double size
};

/*
//Default Constructor are the int pointers NULL or -1?
Stack::Stack()
:size(0), sizeSecond(0), capacityFirst(0), capacitySecond(0), 
topOfStackFirst(-1), topOfStackSecond(-1), theArrayFirst(NULL), 
theArraySecond(NULL)
{
}
*/
  
/* Constructor with two parameters
 * @param sizeOne: Pass in size of first stack
 * @param sizeTwo: Pass in size of second stack
 */
Stack::Stack(int a)
:size(0),capacity(a), topOfStackFirst(-1),
topOfStackSecond(a), theArray(new int[a])
{
}

Stack::~Stack()
{
  delete [] theArray;
}
  
void Stack::pushFirst(int dataOne)
{
  if(size == capacity)
  {
    expand();
  }
  if(topOfStackFirst < topOfStackSecond - 1)
  {
    topOfStackFirst++;
    theArray[topOfStackFirst] = dataOne;
    size++;
  }
}
  
void Stack::pushSecond(int dataTwo)
{
  if(size == capacity)
  {
    expand();
  }
  if(topOfStackFirst < topOfStackSecond - 1)
  {
    topOfStackSecond--;
    theArray[topOfStackSecond] = dataTwo;
    size++;
  }
}
  
//these two delete the element at the top 
void Stack::popFirst()
{
  if(topOfStackFirst >= 0)
  {
    int temp = theArray[topOfStackFirst];
    topOfStackFirst--;
    size--;
  }
}
  
void Stack::popSecond()
{
  if(topOfStackSecond < capacity)
  {
    int temp = theArray[topOfStackSecond];
    topOfStackSecond++;
    size--;
  }
}

void Stack::print()
{
  for(int i = 0; i < capacity; i++)
  {
    cout << theArray[i] << endl;
  }
}

//DOUBLES the size if the stack is full
int Stack::expand()
{
  int newCapacity = capacity * 2;
  int* newArray = new int[newCapacity];
  for(int i = 0; i <= topOfStackFirst; i++)
  {
    newArray[i] = theArray[i];
  }
  
  for(int j = capacity - 1; j >= topOfStackSecond; j--)
  {
    newArray[newCapacity - 1] = theArray[j];
    newCapacity--;
  }
  capacity = capacity * 2;
  delete [] theArray;
  theArray = new int[capacity];
  for(int k = 0; k < capacity; k++)
  {
    theArray[k] = newArray[k];
  }
  delete [] newArray;
  topOfStackSecond = capacity - topOfStackSecond;
}

int main()
{
  int size = 10;
  Stack a(size);
  a.pushFirst(4);
  a.pushSecond(2);
  a.popFirst(); //pop does not remove the element, it simply moves pointer
  a.pushFirst(3);
  //a.print();
  
  cout << endl;
  
  int size2 = 4;
  Stack b(size2);
  b.pushFirst(3);
  b.pushFirst(2);
  b.pushSecond(1);
  b.pushSecond(5);
  b.pushFirst(10);
  b.pushSecond(6);
  b.pushSecond(7);
  b.pushFirst(13);
  b.pushSecond(100);
  
  b.popSecond();
  b.pushSecond(14);
  b.print();
  return 0;
}
