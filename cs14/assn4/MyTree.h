#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class MyTree;

class BinaryNode {
public:
  BinaryNode(string s, int m):myString(s),myInt(m){};
  ~BinaryNode() {};
  int getInt() const {return myInt;};
  string getString() const {return myString;};
private:
  string myString;
  int    myInt;
  //BinaryNode *next;
  BinaryNode *lchild;
  BinaryNode *rchild;
  friend class MyTree;
};


class MyTree {
public:
  MyTree();
  ~MyTree();

  // Insert new node into first available position (to keep the tree almost complete).
  void insert (int x ,string s);

  //Output all strings in pre-order 
  //all the strings will be print in one line separated by spaces
  void preorder() const;

  //Returns a pointer to the node with maximum myInt
  BinaryNode *findMax() const;

  // Converts the binary tree into a binary search tree (BST) with respect to myInt. 
  // That is, move around node values (myString and myInt) to satisfy the BST property.
  void makeBST();


private:
  BinaryNode *root;
  //add a key?
};

