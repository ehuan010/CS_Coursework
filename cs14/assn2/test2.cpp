Ex 3
//UCR - CS 14
//Assignment 2
//Johnny Do
//SID 861003761

//Exercise 3
/**
* Write a C++ class that implement two stacks using a single C++ array. 
* That is, it should have functions popFirst(…), popSecond(…), pushFirst(…), 
* pushSecond(…),… When out of space, double the size of the array 
* (similarly to what vector is doing).
//Answer:
**/

#include <iostream>
#include <cstdlib>
using namespace std;

class Stack
{
private:
int sizeOne;
int sizeTwo;
int arrSize;
int oneBot;
int oneTop;
int twoBot;
int twoTop;
int* arr; 


public:

Stack() {}

Stack(int one, int two, int size)
:sizeOne(0), sizeTwo(0), arrSize(0)
{}

void popFirst(int n) {}

void popSecond(int n){}

void pushFirst(int n){}

void pushSecond(int n){}

void expand()
{
if(arrSize == 0) {return;}
int newSize = 2*arrSize;
Stack newStack(sizeOne, sizeTwo, newSize);
for(int i = 0; i < oneTop; i++)
{
newStack[i] = self[i];
}

for(int i = newSize - 1; i > twoTop; i--)
{
newStack[i] = self[i - arrSize];
} 
}

void print()
{

if(arrSize == 0)
{
cout << endl << "Stack is empty" << endl;
return;
}
else
{
cout << endl;
for(int i = 0; i < arrSize; i++)
{
cout << self[i] << " ";
}
cout << endl;
}
}
};

int main()
{


return 0;
}
