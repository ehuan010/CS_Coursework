/*
Exercise 1 
a. Create (write C++ code) PointerHeap class, which implements a Heap using 
pointers instead of using an array. Implement functions DeleteMin(…) and 
Insert(….). Use templates for type of object and Comparator to define 
comparison between two objects. Show an example of how you would use your 
class for an object of class IntCell (a class with just one integer member 
variable; hint: you need to implement Comparator for IntCell).
b. What is the big-Oh complexity of DeleteMin(…) and Insert(….)?
*/

#include <cstdlib>
#include <ioistream>

using namespace std;

//Define a node object
class Node {
public:
  Node();
  ~Node();
private:
  //int data; //how can I make it store any data?
  Node *left;
  Node *right;
  Node *parent; //might not need this since I have root node
  friend class PointerHeap;
};

//Node methods
Node::Node()  {}
Node::~Node()  {}

template <typename Comparator> class PointerHeap
{
  public:
  PointerHeap(int initialSize); //do i need initialsize?
  ~PointerHeap;
  
  // Get the minimum element on the heap 
  // Rebuilt the array to keep the heap property 
  const Comparator DeleteMin();
  
  // Insert an element on the heap. 
  void Insert(const Comparator &elem)
  
  private:
  int sz;
  int reserved;
  Comparable* data; //is this the root?
  
}

template <typename Comparator>
PointerHeap<Comparator>::PointerHeap(int initialSize=2) {
  Node* topOfHeap = NULL; //data = new Comparable[initialSize];
  reserved = initialSize;
  sz = 1;
}
