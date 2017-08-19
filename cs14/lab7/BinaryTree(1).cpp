#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

template <typename Comparable> class BinaryTree {
public:
  BinaryTree(const Comparable& payload);
  ~BinaryTree();
  void   setLeft(BinaryTree<Comparable> *left);
  void   setRight(BinaryTree<Comparable> *right);
  Comparable* leastCommonAncestor(const Comparable& e1,const Comparable& e2) ;
  void   printTree() const;
private:
  Comparable payload;
  BinaryTree<Comparable> *ltree;
  BinaryTree<Comparable> *rtree;
};

template <typename Comparable>
BinaryTree<Comparable>::BinaryTree(const Comparable& payload) {
  this->payload = payload;
  this->ltree   = NULL;
  this->rtree   = NULL;
}

template <typename Comparable>
BinaryTree<Comparable>::~BinaryTree() {}

template <typename Comparable>
void BinaryTree<Comparable>::setLeft(BinaryTree<Comparable> *left) {
  ltree = left;
}

template <typename Comparable>
void BinaryTree<Comparable>::setRight(BinaryTree<Comparable> *right) {
  rtree = right;
}

template <typename Comparable>
Comparable* BinaryTree<Comparable>::leastCommonAncestor(const Comparable& e1,const Comparable& e2) {
  return NULL;
}


template <typename Comparable>
void BinaryTree<Comparable>::printTree() const {
  cout << payload << " (";
  if (ltree != NULL) ltree->printTree();
  if (rtree != NULL) rtree->printTree();
  cout << ")";
}

main() {
  
  
  BinaryTree<int> *b1 = new BinaryTree<int>(1);
  BinaryTree<int> *b2 = new BinaryTree<int>(2);
  BinaryTree<int> *b3 = new BinaryTree<int>(3);
  BinaryTree<int> *b4 = new BinaryTree<int>(4);
  BinaryTree<int> *b5 = new BinaryTree<int>(5);
  BinaryTree<int> *b6 = new BinaryTree<int>(6);
  BinaryTree<int> *b7 = new BinaryTree<int>(7);
  BinaryTree<int> *b8 = new BinaryTree<int>(8);
  BinaryTree<int> *b9 = new BinaryTree<int>(9);

  b7->setLeft(b9);
  b7->setRight(b8);
  b5->setLeft(b6);
  b5->setRight(b7);
  b3->setLeft(b5);
  b2->setLeft(b4);
  b1->setLeft(b2);
  b1->setRight(b3);

  b1->printTree();
  cout << endl;

  int* a1  = b1->leastCommonAncestor(8,9);
  //cout  << *a1 << endl;
  int* a2  = b1->leastCommonAncestor(6,8);
  //cout  << *a2 << endl;
  int* a3  = b1->leastCommonAncestor(4,6);
  //cout  << *a3 << endl;


}
