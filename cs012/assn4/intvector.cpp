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

#include <iostream>
#include <cstdlib>
#include "intvector.h"

using namespace std;

//Private member functions


//Function that doubles the capacity of the vector. 
//It reallocates memory for the dynamically allocated array 
//and updates the value of capacity. 
void IntVector::expand()
{
  unsigned int new_capacity = vcapacity * 2; //doubles original capacity
  int* data2 = new int [new_capacity]; //makes a new pointer to an int
  for(unsigned int i = 0; i < vsize; ++i)
  {
    data2[i] = data[i]; //makes data2 point to the values that data points to
  }
  delete [] data; //remove data from the heap
  data = data2; //reallocates memory
  vcapacity = new_capacity; //updates vcapacity
}

/* Function that expands the capacity of the vector by amount
 * It reallocates memory for the dynamically allocated array 
 * and updates the value of capacity. 
 * @param amount: An unsigned int passed in that expands the vectors capacity
 */
void IntVector::expand( unsigned int amount )
{
  unsigned int new_capacity = vcapacity + amount; //adds amount to vcapacity
  int * data2 = new int [new_capacity]; //makes new pointer to an int
  if(vcapacity != 0)
  {
    for(unsigned int i = 0; i < vsize; ++i)
    {
      //makes data2 point to the values that data points to
      data2[i] = data[i]; 
    }
  }
  delete [] data; //remove data from the heap
  data = data2; //reallocates memory
  vcapacity = new_capacity; //updates vcapacity
}

//---------------------------------------------------------------------------

//Public member functions

//Constructors and Destructor


//Default constructor
//make vsize and vcapacity to 0 and data to non-dangling pointer
IntVector::IntVector( )
:vsize(0),vcapacity(0),data(NULL)
{
}

/* Constructor with one parameter
 * @param size: Pass in an unsigned int that sets the vsize, vcapacity and 
 * the size of the array
 */
IntVector::IntVector( unsigned int size )
:vsize(size),vcapacity(size),data(new int[size])
{
  for(unsigned int i = 0; i < size; ++i)
  {
    data[i] = 0;
  }
}

/* Constructor with two parameters
 * @param size: Pass in an unsigned int that sets the vsize, vcapacity and
 * the size of the array
 * @param value: Initializes all elements of the array to the int value
 */
IntVector::IntVector( unsigned int size, int value )
:vsize(size),vcapacity(size),data(new int[size])
{
  for(unsigned int i = 0; i < size; ++i)
  {
    data[i] = value;
  }
}

//Destructor that deallocates all remaining dynamically allocated memory
IntVector::~IntVector( )
{
  delete [] data;
}


//Accessors


//Returns the current size of the IntVector object
unsigned int IntVector::size( ) const
{
  return vsize;
}

//Returns the current capacity of the IntVector object
unsigned int IntVector::capacity( ) const
{
  return vcapacity;
}

//Returns whether the vector is empty
bool IntVector::empty( ) const
{
  if(vsize == 0) //empty when vsize is 0
  {
    return true;
  }
  else
  {
    return false;
  }
}

/* Returns the value stored at the index that is passed in if and only if
 * the index is not greater than or equal to the size passed in. Otherwise,
 * the program exits.
 * @param index: Pass in an unsigned int index that tells us the index of the
 * vector
 */
const int  &IntVector::at( unsigned int index ) const
{
  if(index >= vsize)
  {
    exit(0);
  }
  else
  {
    return data[index];
  }
}


/* Overloads subscript operator and returns the value at the index passed in.
 * It does NOT check if index is valid or not.
 * @param index: Pass in an unsigned int index that tells us the index of the
 * vector
 */
const int &IntVector::operator[]( unsigned int index )const
{
  return data[index];
}


//Returns the element stored at the first index by value
const int &IntVector::front( ) const
{
  return data[0];
}

//Returns the element stored at the last index by value
const int &IntVector::back( ) const
{
  return data[vsize - 1];
}


//Mutators


/* Inserts data at location index
 * @param index: Pass in an unsigned in that is the index of insertion
 * @param data: Pass in an int that is the data which is inserted at index
 */
void IntVector::insert( unsigned int index, int data )
{
  if(index > vsize) //if index is larger than vsize just exit 
  {
      exit(0);
  }
  int* data2 = new int[vsize]; //makes a new data2 pointer
  for(unsigned int i = 0; i < vsize; ++i)
  {
    data2[i] = this->data[i]; //add the values in data to data2
  }
  if(vcapacity == 0) //when the capacity is 0
  {
      expand(1); //expand the array by one
  }
  else if(vsize == vcapacity) //otherwise when vsize == vcapacity
  {
    expand(); //double the capacity
  }
  this->data[index] = data; //insert data at this index
  if(index == 0) //when index is 0
  {
    for(unsigned int i = 0; i < vsize; i++)
    {
      this->data[i+1] = data2[i]; //add data2 to data1 for it's next index
    }
  }
  else //otherwise
  {
    for (unsigned int i = index; i <= (vsize- index); i++)
    {
      this->data[i+1] = data2[i] ; //add data2 to data1 for it's next index
    }
  }
  vsize += 1; //increment vsize by one
  delete[] data2; //deallocate memory of data2
}

/* Erases data at location index
 * @param index: Pass in an unsigned int index that is the index of removal
 */
void IntVector::erase( unsigned int index )
{
  if(index >= vsize) //when the index is >= to vsize exit the program
  {
    exit(0);
  }
  else //otherwise person the deletion
  {
    //loops from index to one less than vsize
    for(unsigned int i = index; i < vsize; ++i)
    {
      //assigns the index and those greater than index with the value after
      this->data[i] = this->data[i+1];
    }
    vsize--; //decrease vsize by one since removing a value from IntVector
  }
}



/* This function inserts a value at the back end of the array
 * @param data: Pass in an int data that is inserted into back end of array
 */
void IntVector::push_back( int data )
{
  vsize++; //increase the size by one since adding a value to IntVector
  if(vcapacity == 0) //when the capacity is 0
  {
    expand(1); //expands vector by 1 and gives it vcapity of 1
    //vsize already set to 1 via above vsize++
  }
  if(vsize > vcapacity) //when vsize is larger than the vcapacity
  {
    expand(); //doubles vcapacity
  }
  this->data[vsize-1] = data; //inserts data at index vsize - 1 with data
}



//This function decreases vsize by one or exits if the vector is empty
void IntVector::pop_back()
{
  if(vcapacity == 0)
  {
    exit(0);
  }
  else
  {
    vsize--;
  }
}

//This function reduces the size of the vector to 0
void IntVector::clear()
{
  vsize = 0;
}

/* This function resizes the vector to contain sz elements
 * @param sz: Pass in an unsigned int sz that is the new size of the vector
 */
void IntVector::resize( unsigned int sz )
{
  if(sz < vsize) //when sz is smaller than vsize
  {
    vsize = sz; //makes vsize = sz
  }
  else //otherwise
  {
    unsigned int difference = sz - vsize; //diff b/t sz and vsize
    vsize += difference; //makes vsize the same as sz
    if(vsize > vcapacity) //when vsize is larger than vcapacity
    {
      if(sz < vcapacity * 2) //when sz is less than vcapicty * 2
      {
        expand(); //double the capacity
      }
      else //otherwise
      {
        expand(sz - vcapacity); //expand it by sz - vcapacity
      }
    }
    //loop to place 0's into every extra index
    for(unsigned int i = vsize - difference; i < vsize; ++i)
    {
      data[i] = 0;
    }
  }
}

/* This function resizes the vector to contain sz elements
 * @param sz: Pass in an unsigned int sz that is the new size of the vector
 * @param value: Pass in an int value into every additional index
 */
void IntVector::resize( unsigned int sz, int value )
{
  if(sz < vsize) //when sz is smaller than vsize
  {
    vsize = sz; //makes vsize = sz
  }
  else //otherwise //will an else work for sz = vsize??????
  {
    unsigned int difference = sz - vsize; //diff b/t sz and vsize
    vsize += difference; //makes vsize the same as sz
    if(vsize > vcapacity) //when vsize is larger than vcapacity
    {
      if(sz < vcapacity * 2) //when sz is less than vcapicty * 2
      {
        expand(); //double the capacity
      }
      else //otherwise
      {
        expand(sz - vcapacity); //expand it by sz - vcapacity
      }
    }
    //loop to place 0's into every extra index
    for(unsigned int i = vsize - difference; i < vsize; ++i)
    {
      data[i] = value;
    }
  }
}

/* This function requests that the capacity 
 * (the size of the dynamically allocated array) be set to n at minimum.
 * @param n: Pass in an unsigned int n that is the minimum for the capacity
 */
void IntVector::reserve( unsigned int n )
{
  //n is minimum for vcapacity, so when n > vcapacity do this
  if(n > vcapacity) 
  {
    //when n is less than vcapicty * 2
    if(n < vcapacity * 2) 
    {
      expand(); //double the capacity
    }
    else //otherwise
    {
      expand(n - vcapacity); //expand it by n - vcapacity
    }
  }
}


/* Assigns new content to the vector object, dropping all the elements 
 * contained in the vector before the call and replacing them by those 
 * specified by the parameters. 
 * @param n: Pass in unsigned int n that is the new value of vsize
 * @param value: Pass in an int value that is the new value at every index
 */
void IntVector::assign( unsigned int n, int value )
{
  vsize = n;
  //when vsize is larger than vcapacity
  if(vsize > vcapacity) 
  {
    //when vcapacity + (n - vcapacity) > vcapacity * 2
    if((vcapacity + (n - vcapacity)) > vcapacity * 2 )
    {
      expand(vsize - vcapacity); //expand by vsize - vcapcity
    }
    else //otherwise
    {
      expand(); //double the capacity
    }
  }
  for(unsigned int i = 0; i < vsize; ++i)
  {
    data[i] = value;
  }
}

/* Returns the reference to the value stored at the index that is passed in 
 * if and only if the index is not greater than or equal to the size passed 
 * in. Otherwise, the program exits.
 * @param index: Pass in an unsigned int index that tells us the index of the
 * vector
 */
int &IntVector::at( unsigned int index )
{
  if(index >= vsize)
  {
    exit(0);
  }
  else
  {
    return data[index];
  }
}

/* Overloads subscript operator and returns the reference to the value at the
 * index passed in. It does NOT check if index is valid or not.
 * @param index: Pass in an unsigned int index that tells us the index of the
 * vector
 */
int &IntVector::operator[]( unsigned int index )
{
  return data[index];
}

//Returns the element stored at the first index by reference
int &IntVector::front( )
{
  return data[0];
}

//Returns the element stored at the last index by reference
int &IntVector::back( )
{
  return data[vsize - 1];
}
