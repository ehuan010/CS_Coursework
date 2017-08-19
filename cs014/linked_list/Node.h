/**
 * UCR CS&E
 * CS014 Eclipse Tutorial
 * Part 2 - Linked List
 * Node.h
 */

#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
	Node();
	Node(int value);
	~Node();
	Node* get_next()const;
	Node* get_prev()const;
	int get_value()const;
	void set_next(Node*);
	void set_prev(Node*);
	void set_value(int value);
	
private:
	Node* next;
	Node* prev;
	int value;
	friend class List;
	friend class Iterator;
};

#endif /*NODE_H_*/
