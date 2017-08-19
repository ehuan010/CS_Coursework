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
  bool   find(const Comparable& elem) const;
  int    height() const;
  int    nodes()  const;
  int    leafs()  const;
  double avg()    const;
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
bool   BinaryTree<Comparable>::find(const Comparable& elem) const {
  if(payload == elem)
  {
    return true;
  }
  else
  {
    if(rtree == NULL)
    {}
    else
    {
      rtree->find(elem);
    }
    if(ltree == NULL)
    {}
    else
    {
      ltree->find(elem);
    }
  }
  
  return false;
  
  return 0;
}


template <typename Comparable>
int BinaryTree<Comparable>::height() const {
  cout << payload << endl;
  if (ltree == NULL && rtree == NULL) return 1;
  if (ltree == NULL) return 1+(rtree->height());
  if (rtree == NULL) return 1+(ltree->height());

  int rh = rtree->height();
  int lh = ltree->height();
  return 1 + ((lh > rh)?lh:rh); 
}

template <typename Comparable>
double BinaryTree<Comparable>::avg() const {
  return 0.0;
}

template <typename Comparable>
int BinaryTree<Comparable>::leafs() const {
  if(ltree == NULL && rtree == NULL) return 1;
  if(ltree != NULL && rtree !=NULL) return ltree->leafs() + rtree->leafs();
  else if(rtree != NULL) return rtree->leafs();
  else if(ltree != NULL) return ltree->leafs();
  
  return 0;
}

template <typename Comparable>
int BinaryTree<Comparable>::nodes() const {
  if(ltree == NULL && rtree == NULL) return 1;
  if(ltree!= NULL && rtree != NULL) return 1 + ltree->nodes() + rtree->nodes();
  else if(rtree!= NULL) return 1 + rtree->nodes();
  else if(ltree!= NULL) return 1 + ltree->nodes();
  
  return 0;
}


template <typename Comparable>
void BinaryTree<Comparable>::printTree() const {
  cout << payload << " [";
  if (ltree != NULL) ltree->printTree();
  if (rtree != NULL) rtree->printTree();
  cout << "]";
}

main() {
  
  BinaryTree<int> *a1 = new BinaryTree<int>(1);
  BinaryTree<int> *a2 = new BinaryTree<int>(2);
  BinaryTree<int> *a3 = new BinaryTree<int>(3);
  BinaryTree<int> *a4 = new BinaryTree<int>(5);
  BinaryTree<int> *a5 = new BinaryTree<int>(1);


  cout << "height: " << a1->height() << endl;
  cout << "nodes:  " << a1->nodes() << endl;
  cout << "leafs:  " << a1->leafs() << endl;
  a1->printTree();
  cout << endl;
  a4->setLeft(a5);
  a3->setLeft(a4);
  a2->setLeft(a3);
  a1->setLeft(a2);

  cout << "height: " << a1->height() << endl;
  cout << "nodes:  " << a1->nodes() << endl;
  cout << "leafs:  " << a1->leafs() << endl;
  a1->printTree();
  cout << endl;
  
  BinaryTree<int> *b1 = new BinaryTree<int>(1);
  BinaryTree<int> *b2 = new BinaryTree<int>(2);
  BinaryTree<int> *b3 = new BinaryTree<int>(3);
  BinaryTree<int> *b4 = new BinaryTree<int>(4);
  BinaryTree<int> *b5 = new BinaryTree<int>(5);
  BinaryTree<int> *b6 = new BinaryTree<int>(6);
  BinaryTree<int> *b7 = new BinaryTree<int>(7);
  BinaryTree<int> *b8 = new BinaryTree<int>(8);

  b7->setRight(b8);
  b5->setLeft(b6);
  b5->setRight(b7);
  b3->setLeft(b5);
  b2->setLeft(b4);
  b1->setLeft(b2);
  b1->setRight(b3);

  cout << "height: " << b1->height() << endl;
  cout << "nodes:  " << b1->nodes() << endl;
  cout << "leafs:  " << b1->leafs() << endl;
  
  cout << "find(1)" << b1->find(1) << endl; 
  cout << "find(8)" << b1->find(8) << endl; 
  cout << "find(5)" << b1->find(5) << endl;
  cout << "find(9)" << b1->find(9) << endl; 
  b1->printTree();

  cout << endl;
}
