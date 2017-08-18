#include <iostream>
#include <cstdlib>
#include "intlist.h"
using namespace std;

void IntList::push_front(int data)
{
  IntNode *temp = new IntNode(data);
  temp->next = head;
  head = temp;
  size++;
}

void IntList::pop_front()
{
  if(!head)
  {
    return;
  }
  IntNode *temp = head;
  head = head->next;
  delete temp;
  size--;
}

void IntList::push_back( int data ) 
{
  if(head == NULL)
  {
    IntNode *temp = new IntNode(data);
    head = temp;
  }
  else
  {
    IntNode* it = head;
    while(it->next)
    {
      it = it->next;
    }
    IntNode* temp = new IntNode(data);
    it->next = temp;
  }
}

void IntList::insert( unsigned pos, int data)
{
  IntNode* it = head;
  unsigned num = pos;
  if(!head)
  {
    push_back(data);
  }
  for(unsigned i = 0; i < num; i++)
  {
    it = it->next;
  }
  IntNode* temp = new IntNode(data);
  temp->next = it->next;
  it->next = temp;
}


void IntList::erase( unsigned pos )
{
  IntNode * it = head;
  if(!head)
  {
    return;
  }
  if(head && pos == 0)
  {
    pop_front();
    return;
  }
  while(pos > 1)
  {
    it = it->next;
    pos--;
  }
  IntNode *temp = it->next->next;
  delete it->next;
  it->next = temp;
}

void IntList::print() const
{
  IntNode* it = head;
  while(it)
  {
    cout << it->data << '\n';
    it = it->next;
  }
}

IntList::~IntList()
{
}
