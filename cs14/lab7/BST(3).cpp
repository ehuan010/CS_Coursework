#include <cstdlib>
#include <iostream>
#include <cmath>
#include<vector>


using namespace std;

template <typename T> class BST;

//Define a node object
template <typename Comparable> class BSTNode {
public:
  BSTNode() {
    lchild = NULL;
    rchild = NULL;
  };
  
  ~BSTNode();
private:
  Comparable payload;
  BSTNode<Comparable> *lchild;
  BSTNode<Comparable> *rchild;
  friend class BST<Comparable>;
};


template <typename Comparable> class BST {
public:
  BST();
  ~BST();
  void   add(const Comparable& elem);
  bool   find(const Comparable& elem) const;
  vector<Comparable>* sortedElements();
private:
  void insert(BSTNode<Comparable> *node, BSTNode<Comparable> *newNode);
  void sortedElements_( BSTNode<Comparable> *node, vector<Comparable>* vector);
  BSTNode<Comparable> *root;
};

template <typename Comparable>
BST<Comparable>::BST() {
  this->root = NULL;
}

template <typename Comparable>
BST<Comparable>::~BST() {}


template <typename Comparable>
vector<Comparable>* BST<Comparable>::sortedElements() {
  vector<Comparable>* sorted = new vector<Comparable>();
  sortedElements_(root,sorted);
  return sorted;
}

template <typename Comparable>
void BST<Comparable>::sortedElements_(BSTNode<Comparable>* node, vector<Comparable>* vector) {
  if(node == NULL)
  {
    return;
  }
  if( node != NULL)
  {
    sortedElements_(node->lchild, vector);
    vector->push_back(node->payload);
    sortedElements_(node->rchild, vector);
  }
}



template <typename Comparable>
void BST<Comparable>::add(const Comparable& elem)  {
  BSTNode<Comparable> *newNode = new BSTNode<Comparable>();
  newNode->payload = elem;
  if (root == NULL) {
    root = newNode;
  } else {
    insert(root, newNode);
  }
}

template <typename Comparable>
void BST<Comparable>::insert(BSTNode<Comparable> *node, BSTNode<Comparable> *newNode) {
  if (node->payload == newNode->payload) return;
  if (node->payload > newNode->payload) {
    if (node->lchild == NULL) node->lchild = newNode;
    else insert(node->lchild, newNode);
  } else {
    if (node->rchild == NULL) node->rchild = newNode;
    else insert(node->rchild, newNode);
  }
}

main() {
  srand(1);
  int sz = 20;
  BST<int> bst;
  for (int i = 0; i < sz; i++) {
    int r = rand()%(1<<15);
    bst.add(r);
  }
  vector<int>* v = bst.sortedElements();
  vector<int>::iterator it;
  for (it = v->begin() ; it != v->end(); ++it) {
    cout << *it << endl;
  }

}
