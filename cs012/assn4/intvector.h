// Course: CS 12 Winter 2012
//
// First Name: Edward
// Last Name: Huang
// Course username: ehuan010
// email address: ehuan010@student.ucr.edu
//
// Lecture Section: 002
// Lab Section: 022
// TA: Wojchiek Karas
//
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#ifndef INTVECTOR_H
#define INTVECTOR_H

using namespace std;

class IntVector
{
  private:
  //Data members
  unsigned int vsize;
  unsigned int vcapacity;
  int* data;
  
  //Private members
  void expand();
  void expand( unsigned int amount );
  
  public:
  //Public members
  
  //Constructors
  IntVector( );
  IntVector( unsigned int size );
  IntVector( unsigned int size, int value );
  ~IntVector( ); //destructor
  
  //Accessors
  unsigned int size( ) const;
  unsigned int capacity( ) const;
  bool empty( ) const;
  const int &at( unsigned int index ) const;
  const int &operator[]( unsigned int index )const;
  const int &front( ) const;
  const int &back( ) const;
  
  //Mutators
  void insert( unsigned int index, int data );
  void erase( unsigned int index );
  void push_back( int data );
  void pop_back();
  void clear();
  void resize( unsigned int sz );
  void resize( unsigned int sz, int value );
  void reserve( unsigned int n );
  void assign( unsigned int n, int value );
  int &at( unsigned int index );
  int &operator[]( unsigned int index );
  int &front( );
  int &back( );
  
};

#endif
