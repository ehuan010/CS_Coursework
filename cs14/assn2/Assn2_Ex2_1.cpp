#include <iostream>

using namespace std;


struct IntNode
{
   int data;//Holds the data of the node
   IntNode* next;//Pointer to the next node
   IntNode* prev;//pointer to previous node
   IntNode* tenth;//Pointer to the tenth node if there is one
   IntNode(int data) :data(data),next(NULL), prev(NULL), tenth(NULL){}
   IntNode() :data(0),next(NULL){}
};


class IntQueue
{
	private:
		IntNode* front;//Pointer to the front of the queue
		IntNode* back;//Pointer to the back of the queue
		int sz;//Size of the queue
		
	public:
		
		IntQueue();
		~IntQueue();
		void enqueue(int);
		int dequeue();
		void print();
		void tenths();
};

IntQueue::~IntQueue()
{ }

IntQueue::IntQueue()
:front(NULL), back(NULL), sz(0)
{ }

//Creates pointers to the tenth next node if size is proper
void IntQueue::tenths()
{
	int count = 0;
	if(sz > 10)
	{
		IntNode* tmp = back;
		IntNode* tmp2 = back;
		while(count < sz)
		{
			tmp2 = tmp2 -> next;
			++count;
			if(count > 9)
			{
				tmp -> tenth = tmp2;
				tmp = tmp -> next;
			}
		}
	}
}


//Adds another number to the queue, making sure that the list stays
//in ascending order. If the size of the list is above 10, then the 
//tenths function is called in order to create pointers to the tenths
//node of each node if they have one
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
		if(sz > 10)
		{
			tenths();
		}
		return;
	}
	if(add > back -> data)
	{
		nn1 -> next = back;
		back -> prev = nn1;
		back = nn1;
		++sz;
		if(sz > 10)
		{
			tenths();
		}
		return;
	}
	IntNode* tmp = back -> next;
	while(tmp)//while(tmp != NULL)
	{
		if(tmp -> tenth != NULL)
		{
			if(add <= tmp -> tenth -> data)
			{
				tmp = tmp -> tenth;
			}
		}
		
		if(add >= tmp -> data)
		{
			nn1 -> next = tmp;
			nn1 -> prev = tmp -> prev;
			tmp -> prev -> next = nn1;
			tmp -> prev = nn1;
			++sz;
			if(sz > 10)
			{
				tenths();
			}
			return;
		}
		tmp = tmp -> next;
	}
	cerr << "Size: " << sz << endl;
	if(sz >= 11)
	{
		tenths();
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
	if(sz > 10)
	{
		tenths();
	}
	cout << value << " has been removed from the list." << endl;
	return value;

}

//Prints out the que and their tenths pointers
void IntQueue::print()
{
	if(sz == 0)
	{
		cout << "Empty List!" << endl;
	}
	IntNode* tmp = back;
	cout << "Normal pointers" << endl;
	while(tmp)
	{
		cout << tmp -> data << " ";
		tmp = tmp -> next;
	}
	cout << endl;
	if(sz > 10)
	{
		IntNode* tmp2 = back;
		cout <<"Tenth pointers: " << endl;
		while(tmp2 -> tenth)
		{
			cout << tmp2 -> tenth -> data << " ";
			tmp2 = tmp2 -> next;
		}
		cout << endl;
	}
}

int main()
{
	IntQueue q;
	
	q.enqueue(23);
	q.enqueue(25);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.enqueue(19);
	q.enqueue(21);
	q.enqueue(17);
	q.enqueue(14);
	q.enqueue(15);
	q.enqueue(17);
	q.enqueue(14);
	q.enqueue(15);
	q.enqueue(17);
	q.enqueue(14);
	q.enqueue(15);
	q.enqueue(17);
	q.enqueue(14);
	q.enqueue(15);
	q.enqueue(13);
	q.enqueue(11);
	q.enqueue(9);
	q.enqueue(10);
	q.enqueue(8);
	q.enqueue(7);
	q.dequeue();
	
	q.print();
	return 0;
}
/**
 * 
 * b.Can the modification in (c) improve the cost (not asymptotic but just 
 * execution time) of enqueue? Does it improve the asymptotic cost?
 * 
 * The asymptotic cost is now n/10 which is still O(n), but checking to
 *  make sure the pointers are in the right position, causes the for 
 * loop to go into another for loop, making the worst case complexity 
 * O(n^2). The execution time to run the program with the extra pointers
 * does improve slightly for enqueue. But overall since there are so 
 * many more pointers to manage, I believe the costs increases.
 * 
 * c.Is 
 * there any disadvantage that modification (c) incurs? There are many 
 * disadvantages to the modification that (c) incurs. Foremost
 * amongst them is the fact there are now many more pointers to worry about
 * if the list gets really big. This also means more memory is taken up
 * as an addition pointer for every node beyond the 10th will have an extra
 * pointer. You also have to be careful not to access a NULL tenth pointer
 * or you might seg fault. The size of the list is now a concern where it 
 * wasn't one before. This is horribly inefficient. I don't know why anyone
 * would do it.
 **/
