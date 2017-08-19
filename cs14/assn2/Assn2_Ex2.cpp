#include <iostream>

using namespace std;

//Struct to create nodes that hold integers
struct IntNode
{
   int data;//value of the node
   IntNode* next;//pointer to next node
   IntNode* prev;//pointer to previous node
   IntNode(int data) :data(data),next(NULL), prev(NULL){}
   IntNode() :data(0),next(NULL){}
};


class IntQueue
{
	private:
		IntNode* front;//Pointer to the front of the queue
		IntNode* back;//Pointer to the back of the queue
		int sz;//size of the queue
		
	public:
		
		IntQueue();//constructor
		~IntQueue();//destructor
		void enqueue(int);//Adds a number to the queue
		int dequeue();//Removes the number at the front of the queue
		void print();//Prints out the function
};

IntQueue::~IntQueue()
{ }

IntQueue::IntQueue()
:front(NULL), back(NULL), sz(0)
{ }

//Adds a number to the queue, making sure that the queue stays in 
//ascending order
void IntQueue::enqueue(int add)
{
	IntNode* nn1 = new IntNode(add);
	if( sz == 0)
	{
		front = nn1;
		back = nn1;
		++sz;
		return;
	}
	if(add < front -> data)
	{
		front -> next = nn1;
		nn1 -> prev = front;
		front = nn1;
		++sz;
		return;
	}
	if(add > back -> data)
	{
		nn1 -> next = back;
		back -> prev = nn1;
		back = nn1;
		++sz;
		return;
	}
	IntNode* tmp = back -> next;
	while(tmp)
	{
		if(add >= tmp -> data)
		{
			nn1 -> next = tmp;
			nn1 -> prev = tmp -> prev;
			tmp -> prev -> next = nn1;
			tmp -> prev = nn1;
			++sz;
			return;
		}
		tmp = tmp -> next;
	}
	return;
}

//Removes the number from the front of the list
int IntQueue::dequeue()
{
	int value;
	if(front == NULL)
	{
		cout << "Error: Nothing in the list!" << endl;
		return -1;
	}
	if(sz == 1)
	{
		IntNode* tmp = front;
		value = front -> data;
		front = NULL;
		back = NULL;
		delete tmp;
		--sz;
		cout << value << " has been removed from the list." << endl;
		return value;
	}
	value = front -> data;
	IntNode* tmp = front -> prev;
	front -> prev = NULL;
	delete front;
	front = tmp;
	front -> next = NULL;
	--sz;
	cout << value << " has been removed from the list." << endl;
	return value;

}

void IntQueue::print()
{
	if(sz == 0)
	{
		cout << "Empty List!" << endl;
	}
	IntNode* tmp = back;
	while(tmp)
	{
		cout << tmp -> data << " ";
		tmp = tmp -> next;
	}
	cout << endl;
}

int main()
{
	IntQueue que;
		
	que.dequeue();
	que.dequeue();
	que.enqueue(1);
	que.enqueue(2);
	que.enqueue(2);
	que.enqueue(3);
	que.print();
	que.enqueue(2);
	que.print();
	que.dequeue();
	que.print();
	que.enqueue(2);
	que.enqueue(2);
	que.enqueue(2);
	que.dequeue();
	que.enqueue(2);
	que.enqueue(1);
	que.enqueue(1);
	que.enqueue(9);
	que.enqueue(8);
	que.enqueue(9);
	que.enqueue(7);
	que.enqueue(7);
	que.enqueue(8);
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	
	que.print();
	return 0;
}

/**
 * What is the average asymptotic cost per call to enqueue and to dequeue?
 * 
 * The average asymptotic cost per call to enqueue is O(n) since at worst
 * the function will have to look at each element one time. The average
 * cost per call for dequeue is O(1) since the function only looks at the
 * front of the queue
**/
