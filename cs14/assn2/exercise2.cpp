/*Exercise 1
If the elements of a list are sorted, is an array-based or a 
linked-list-based implementation of the list more efficient for binary 
search? Explain.

Answer:
An array-based implementation of the list is more efficient for binary
search because you can randomly access elements in an array. By halving
a sorted array, you can find the element in O(logn) time for the worst
case. Whereas for a sorted linked-list you will have to access the
elements sequentially so the worst case would be O(n). 
*/

/**Exercise 2
 * a. Write C++ code to implement an integer queue class using linked-list, 
 * where the nodes are stored sorted by ascending value of the integer 
 * they store. We call this a priority queue. Specifically, implement 
 * enqueue and dequeue methods.
 * 
 * b. What is the average asymptotic cost per call to enqueue and to dequeue?
 * The average asymptotic cost per call to enqueue is O(n) and to 
 * dequeue is O(1)
 * 
 * See code below
 * 
 * c. What if for each node, in addition to a pointer to the next node, 
 * you add a pointer to the 10th next node. Modify your code to take 
 * advantage of this.
 * 
 * Had problems implementing this, so just left out the code.
 * 
 * d. Can the modification in (c) improve the cost (not asymptotic 
 * but just execution time) of enqueue? Does it improve the asymptotic cost?
 * 
 * I believe that the modification in (c) will improve the cost of enqueue
 * because you can access not just the next and previous elements, but also
 * an element 10 indices away. The asymptotic cost is not improved because
 * you still need to traverse the queue to sort it.
 * 
 * e. Is there any disadvantage that modification (c) incurs?
 * The disadvantage that modification (c) incurs is that you have to keep an
 * extra pointer to every 10th next node, which will take up extra memory.
 * The programmer also has to make sure that a 10th next node exists,
 * otherwise they will be pointing to a nonexistant node.
 */


#include <iostream>

using namespace std;

class Node {
public:
  Node();
  ~Node();
private:
  int data;
  Node *prev;
  Node *next;
  friend class QueueList;
};

//Node methods
Node::Node()
{}

Node::~Node()  
{}

class QueueList
{
  public:
  QueueList();
  ~QueueList();
  void enqueue(int elem);
  void sort(int length);
  void print();
  int dequeue();
  
  private:
  int size;
  Node* head;
  Node* tail;
};

QueueList::QueueList()
:size(0),head(NULL),tail(NULL)
{
}

QueueList::~QueueList()
{}

void QueueList::enqueue(int elem)
{
  Node* temp = new Node();
  temp->data = elem;
  temp->next = NULL;
  temp->prev = NULL;
  
  if(size == 0)
  {
    head = temp;
    tail = temp;
    size++;
  }
  else if(size == 1)
  {
    head->next = temp;
    temp->prev = head;
    temp->next = NULL;
    tail = temp;
    size++;
    sort(size);
  }
  else
  {
    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
    tail = temp;
    size++;
    sort(size);
  }
  //size++; //where to put this
  /*
  if(elem < head->data)
  {
    temp->next = head; //puts head in the beginning
    head->prev = temp;
    head = temp;
    size++;
  }
  
  if(elem
  */
}

void QueueList::sort(int length)
{
  Node* it = head;
  Node* temp = tail; //temporary is tail node
  Node* beforeIt; //beforeIt is it->prev node
  Node* beforeTail = tail->prev; //beforeTail is tail->prev node
  int tempdata;
  while(it->next != NULL)
  {
    //if data at iterator is smaller than data at tail move the pointer
    if(it->data < tail->data)
    {
      it = it->next;
    }
    //when size is 2 must do something diff.
    else if(size == 2)
    {
      //swap the data
      if(it->data > tail->data)
      {
        tempdata = head->data; //save head's data
        head->data = tail->data; //make head data tail's data
        tail->data = tempdata; //make tails data temps data
        it = it->next;
      }
      //otherwise just return and don't swap
      else
      {
        return;
      }
    }
    //it data will be = or > than tail's data
    else
    {
      
      beforeIt = it->prev;
      beforeIt->next = temp;
      temp->prev = beforeIt;
      temp->next = it;
      it->prev = temp;
      
      //cout << "test" << endl;
      tail = beforeTail;
      
      tail->next = NULL;
      
      //it = it->next;
      
    }
  }
}

void QueueList::print()
{
  Node* it = head;
  if(size != 0)
  {
    
  while(it->next != NULL)
  {
    
    cout << it->data << endl;
    it = it->next;
  }
    cout << it->data << endl;
  }
}

int QueueList::dequeue()
{
  int num; //the data I want to return
  if(size == 0)
  {
    cout << "Queue is Empty" << endl;
  }
  if(size == 1)
  {
    num = head->data;
    head = NULL;
    tail = NULL;
    size--;
    //cout << size << endl;
    return num;
  }
  else
  {
    num = head->data;
    //Node* temp = head;
    //delete head;
    head = head->next;
    //delete temp;
    size--;
    return num;
  }
  //Node* temp = head->next;
}

int main()
{
  QueueList test;
  cout << "Test enqueue" << endl;
  test.enqueue(2);
  test.enqueue(1);
  test.enqueue(4);
  test.enqueue(5);
  test.enqueue(3);
  test.print();
  cout << endl << "Test dequeue" << endl;
  test.dequeue();
  test.dequeue();
  test.print();
  //test.enqueue(3);
  //test.print();
  return 0;
}
