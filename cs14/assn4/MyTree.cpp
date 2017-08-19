#include "MyTree.h"

MyTree::MyTree() 
{
  this->root = NULL;
  //this->next = NULL;;
}

MyTree::~MyTree() {}

void MyTree::insert (int x ,string s) 
{
  //BinaryNode *newNode = new BinaryNode(s,x);
  //BinaryNode *curr = root;
  if(root == NULL)
  {
    root = new BinaryNode(s,x);
    //root = newNode;
    return;
  }
  BinaryNode *curr = root;
  while(curr != NULL)
  {
    if(curr->lchild == NULL)
    {
      cout << "test1" << endl;
      //curr->lchild = newNode;
      curr->lchild = new BinaryNode(s,x);
      cout << root->lchild->myString << endl;
      return;
    }
    //else
    //{
     // curr = root->lchild;
    //}
    
    if(curr->rchild == NULL)
    {
      cout << "test2" << endl;
      //root->rchild = newNode;
      //curr->rchild = newNode;
      curr->rchild = new BinaryNode(s,x);
      cout << root->rchild->myString << endl;
      cout << "test3" << endl;
      return;
    }
    //can insert up to 5, then my logic is messed up
    if(curr->lchild != NULL)
    {
      curr = curr->lchild;
    }
    else
    {
      curr = curr->rchild;
    }
    //else
    //{
      //curr = root->rchild;
    //}
  }
  //root = curr;
  //root->lchild = newNode;
}

void MyTree::preorder() const 
{
  if(root == NULL)
  {
    return;
  }
  cout << root->myString << " ";
  cout << root->lchild->myString << " ";
  cout << root->rchild->myString << " ";
  cout << root->lchild->lchild->myString << " ";
  cout << root->lchild->rchild->myString << " ";
  //cout << root->rchild->lchild->myString << " ";
  //if(root != NULL)
  //{
    //cout << root->myString << " ";
    //if(root->lchild != NULL)
    //{
      //root->lchild->preorder();
    //}
    //if(root->rchild != NULL)
    //{
      //root->rchild->preorder();
    //}
    //cout << endl;
  //}
}

BinaryNode* MyTree::findMax() const 
{ 
  return NULL; 
}

void MyTree::makeBST() 
{
}
