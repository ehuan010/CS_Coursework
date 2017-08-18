#include "node.h"

class IntList
{
  private:
    IntNode *head;
    IntNode *tail;
    unsigned size;
  
  public:
    IntList() : head( NULL ), tail( NULL ), size( 0 )  {}
    void push_front(int data);
    void pop_front();
    void push_back( int data );
    void insert( unsigned pos, int data);
    void erase( unsigned pos );
    void print() const;
    ~IntList();
};

