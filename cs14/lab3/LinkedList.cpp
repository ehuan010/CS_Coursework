#include <cstdlib>
#include <iostream>

using namespace std;
 //reverse, find, makeset, append

//Define a node object
class Node {
public:
  Node();
  ~Node();
private:
  string payload;
  Node *next;
  friend class LinkedList;
};

//Node methods
Node::Node()  {}
Node::~Node()  {}

//Define the LinkedList
class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  //Return the element at index i
  string operator[](int i) const;
  //Add a new element to the end of the ArrayList
  void add(string elem);
  //Return the index of the first ocurrence, -1 if not found
  int  find(string elem);
  //Number of elements on the list
  int  size();
  //Returns true if the list is empty, false if not
  bool isEmpty();
  //Reverse the list
  void reverse();
  //Append a second list to the end of the list, in the same order
  void append(LinkedList& v);
  //Returns a new vector that remove the duplicates
  LinkedList* makeSet();
  //Print the Linked List
  void print();
private:
  Node* head;
  //You can add the tail if it makes things easier
  //Node *tail 
  //You can keep the size also
  //int sz
};


LinkedList::LinkedList() {
  head = NULL;
}

LinkedList::~LinkedList() {}

int LinkedList::size() {
  int sz = 0;
  Node *curr = head;
  while (curr != NULL) {
    curr = curr->next;
    sz++;
  }
  return sz;
}

bool LinkedList::isEmpty() {
  return head == NULL;
}

void LinkedList::add(string elem) {
  int i = 0;

  Node *node = new Node();
  node->payload = elem;
  node->next = NULL;
  
  Node* it = head;
  if (head == NULL) {
    head = node;
  } else {
    while(it->next != NULL)
    {
      it = it->next;
    }
    it->next = node;
  }
}

void LinkedList::append(LinkedList&  l) {
  //Add your code
  //copy the elements from the second list

  //O(n^2)
  Node* temp = new Node();
  temp = l.head;
  while(temp->next != NULL)
  {
    add(temp->payload);
  }
  //temp->payload = l.payload;
  //temp->next = NULL;
  
  /**
  Node* temp = new Node;
  l -> head = temp;
  while(temp != NULL)
  {
    this -> add( temp -> payload);
  }
  this -> tail = temp -> tail;
  */
}



int LinkedList::find(string elem) {
  //Add your code
  Node* it = head;
  if(it == NULL) 
  {
    return -1;
  }
  int location = 0;
  while(it != NULL)
  {
    if(it->payload == elem)
    {
      return location;
    }
    location++;
    it = it->next;
  }
  
  return -1;
}


void LinkedList::reverse() {
}


LinkedList* LinkedList::makeSet() {
  LinkedList *l = new LinkedList();
  if(head == NULL)
  {
    return l;
  }
  Node* it = head;
  while(it->next != NULL)
  {
    if(l->find(it->payload) == -1)
    {
      l->add(it->payload);
    }
    it = it->next;
  }
  
  //has duplicates if it->payload = it->next's payload 
  return l;
}

void LinkedList::print() {
  Node *curr = head;
  while (curr != NULL) {
    cout << curr->payload << " "; 
    curr = curr->next;
  }
  cout << endl;
}


int main() {
  
  LinkedList l;
  cout << "Testing Empty List:" << endl;
  cout << "*******************" << endl;
  cout << "is empty:" << (l.isEmpty()==true) << endl;
  cout << "size:" << (l.size() == 0) << endl;
  cout << "find a" << (l.find("a") == -1) << endl;
  l.reverse();
  l.makeSet();
  cout << "reverse and makeset: 1" << endl;


  l.add("a");
  l.add("b");
  l.add("c");
  l.add("d");
  l.add("e");

  cout << "Testing List:" << endl;
  cout << "*******************" << endl;
  cout << "is empty:" << (l.isEmpty()==false) << endl;
  cout << "size:" <<  (l.size()    == 5) << endl;
  cout << "find a" << (l.find("a") == 0) << endl;
  cout << "find b" << (l.find("b") == 1) << endl;
  cout << "find e" << (l.find("e") == 4) << endl;
  cout << "find f" << (l.find("f") == -1) << endl;

  l.print();
  
  cout << "Testing Append:" << endl;
  LinkedList l2;
  l2.add("a");
  l2.add("e");
  l2.add("a");
  l.append(l2);
  cout << "size:" <<  (l.size()    == 8) << endl;
  l.print();
  
  
  LinkedList& l3 = *l.makeSet();
  cout << "size:" <<  (l3.size()  == 5) << endl;
  l.print();
  

  LinkedList l4;
  l4.append(l2);
  l3 = *l4.makeSet();
  cout << "size:" <<  (l3.size() == 2) << endl;
  l.print();


}
