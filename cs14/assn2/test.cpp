Ex 2
//UCR - CS 14
//Assignment 2
//Johnny Do
//SID 861003761

#include <iostream>
using namespace std;

/**
* Exercise 2
a.Write C++ code to implement an integer queue class using linked-list, 
where the nodes are stored sorted by ascending value of the integer they store. 
We call this a priority queue. 
Specifically, implement enqueue and dequeue methods.
b.What is the average asymptotic cost per call to enqueue and to dequeue?
c.What if for each node, in addition to a pointer to the next node, 
you add a pointer to the 10th next node. 
Modify your code to take advantage of this.
d.Can the modification in 
(c) improve the cost (not asymptotic but just execution time) of enqueue? 
Does it improve the asymptotic cost?
e.Is there any disadvantage that modification (c) incurs?
Answers:
**/

//Define a node object
class Node 
{
private:
int data;
Node* next;
Node* tenth;
friend class Queue;

public:
Node() {};
~Node() {};

};

class Queue
{
private:
Node* front;
Node* back;
int size;

public:
Queue()
:front(NULL), back(NULL), size(0)
{}

Node* NewNode(int var)
{
Node* toInsert = new Node();
toInsert->data = var;
toInsert->next = NULL; 
return toInsert;
}

void enqueue(int var)
{
Node* insert = new Node();
insert->data = var;
Node* forwardIt = back;
Node* forwardIt2 = back;

//New Node insertion
if(front == NULL && back == NULL)
{
back = insert;
front = insert;
}

//If size = 1 and current data is less than the other node's data
else if(size == 1 && front->data >= var)
{
back = front;
front = insert;
back->next = front;
}

//If size = 1 and current data is larger than the other node's data
else if(size == 1 && front->data <= var)
{
back = insert;
back->next = front;
}

//If the inserting data is larger or equal to than the back's data
else if(var >= back->data)
{
insert->next = forwardIt;
back = insert;
}

//If the front is equal to the data or greater than data insert in front
else if(var <= front->data)
{
front->next = insert;
}

//In the middle
else
{
forwardIt2 = forwardIt2->next;
while(forwardIt2 != NULL)
{
if(forwardIt2->next->data <= var)
{
insert->next = forwardIt->next;
forwardIt->next = insert;
break;
}
else
{
forwardIt2 = forwardIt2->next;
}
}
}

size++; 
}

void dequeue(int var)
{

}

void print()
{
Node* it = back;
while(it != NULL)
{
cout << it->data << " ";
it = it->next;
}
}
};


int main()
{
Queue fish_taco;

fish_taco.enqueue(69);
fish_taco.enqueue(69);
fish_taco.enqueue(7);

fish_taco.enqueue(3);
fish_taco.enqueue(3);

fish_taco.enqueue(6);
fish_taco.enqueue(2);
fish_taco.enqueue(2);

fish_taco.enqueue(1);
fish_taco.enqueue(1);



cout << endl;
fish_taco.print();
cout<< endl;

return 0;
}


























