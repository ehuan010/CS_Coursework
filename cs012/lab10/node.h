#ifndef NULL
#define NULL 0
#endif

class IntNode
{
  private:
    int data;
    IntNode *next;
  
  public:
    IntNode() : data(0), next( NULL ) {}
    friend class IntList;
    IntNode(int data) : data( data ), next( NULL ) {}
    ~IntNode() {}
};
