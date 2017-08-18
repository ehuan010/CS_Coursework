
#include <iostream>
#include "intvector.h"

using namespace std;

// START : PRIVATE MEMBER FUNCTIONS
//  This function will double the capacity of the vector.
//  This function should reallocate memory for the dynamically
//  allocated array and update the value of capacity.
//  Make sure you don't create a memory leak here.
void IntVector:: expand()
{
    unsigned int cap = vcapacity * 2;
    int * a1 = new int [cap];
    for(unsigned int i = 0; i < vsize; i++)
    {
        a1[i] = data[i];
    }
   
    delete [] data;
   
    data = a1;
    vcapacity = cap;

}
   
//  This function will expand the capacity of the vector by amount
//  passed in. This function should reallocate memory for the
//  dynamically allocated array and update the value of capacity.
//  Make sure you don't create a memory leak here
void IntVector:: expand( unsigned int amount )
{
    unsigned int cap = vcapacity + amount;
    int * a2 = new int [cap];
    for(unsigned int i = 0; i < vcapacity; i++)
    {
        a2[i] = data[i];
    }
   
    delete [] data;
   
    data = a2;
    vcapacity = cap;

}
// END : PRIVATE MEMBER FUNCTIONS

// START: CONSTRUCTORS & DESCTRUCTORS
       
// default constructor
//  set both the size and capacity to 0 and wll not allocate any memory
//      to store integrers
IntVector:: IntVector()
:vsize(0), vcapacity(0), data(NULL)
{
}

       
// constructor
//  sets both size and capacity to the value of the parameters passed in
//      and dynamically allocates an array of size as well
// @param size, size of vector
IntVector:: IntVector( unsigned int size)
:vsize(size), vcapacity(size), data(new int[size])
{
}
       
// sets both the size and capacity to the value of the parameter passed
//  in anddynamically allocates an array of that size as well.
//   the function intializes all elements of the array to the value of
//   of the 2nd parameter
// @ param size, size of vector
// @ param value,
IntVector:: IntVector( unsigned int size, int value)
:vsize(size), vcapacity(size), data(new int[size])
{
    for(unsigned int i = 0; i < size; i++) data[i]=value; 
}
       
// destructor
//  the function should deallocate all remaining dynamically allocated
//      memory
IntVector:: ~IntVector()
{
    delete []data;
}
       
// END: CONSTRUCTORS & DESCTRUCTORS
// START: ACCESSORS
       
// this function returns the current size ofthe IntVector object,
//  which is stored in the size data field
unsigned int IntVector:: size() const
{
    return vsize;   
}
       
// this function retrns the current capacity of the IntVector object,
// which is stored in the capacity data field
unsigned int IntVector:: capacity() const
{
    return vcapacity;   
}
       
// Returns whether the vector is empty (the size field is 0).
bool IntVector:: empty( ) const
{
    if (vsize == 0) return true;
    else return false;   
}

//  The program will exit if the index is greater than or equal to the size
//      pass in by the user.    
//  @ param index, index value, never negative
//  @ return the value stored at the element at the passed in index position.
const int & IntVector:: at( unsigned int index ) const
{
    if(index >= vsize) exit(0);
    else return data[index];
}


// This function overloads the subscript operator and returns the
//  value stored at the element at the passed in index position.
//  Unlike at function, it does NOT check if index is valid or not.
const int & IntVector:: operator[]( unsigned int index )const
{
    return data[index];   
}

      
// This function will return the element stored at the first index by value.
const int & IntVector:: front( ) const
{
    return data[0];   
}

// This function will return the element stored at the last index
//  by value.
const int & IntVector:: back( ) const
{
    return data[vsize - 1];   
}
       
// END: ACCESSORS
// START: MUTATORS
       
//  Function inserts data at location index.
//  To do this, all values currently at position index and greater are
//      shifted to the right by 1 (i.e. each element takes the place of the
//      element right after its current position).
//      size is increased by 1: If size becomes larger than capacity,
//      this function needs to double the capacity.
//  In other words, if capacity and size are both 20 when this
//      function is called, capacity will become 40 and size will be set
//      to 21.
//  Since other functions will also potentially need to expand (double)
//      the capacity, implement the private helper function named
//      expand (see above) to do this for you. This function should
//      call exit(0) if an index value greater than size is passed in.
void IntVector:: insert( unsigned int index, int val )
{
    if(empty()) expand(1);

    vsize++;
   
    if(vsize > vcapacity) expand();

    for(unsigned int k = vsize - 1; k > index; --k)
    {
        data[k] = data[k-1];
    }
    data[index] = val;
}
       
//  The value of position index and shifts all values greater than one to the
//  the left. Size is decreased by one.
//  If the index value passed in is greater than size function exists
void IntVector:: erase( unsigned int index )
{
    if(index >= vsize) exit(0);
   
    vsize--;
   
    for(unsigned u = vsize; u > index; u--)
    {
        data[u] = data[u - 1];
    }
   
}
       
//  This function inserts a value at the back end of the array.
//  Size is increased by 1: If size becomes larger than capacity,
//      this function needs to double the capacity.
//  In other words, if capacity and size are both 20 when this function
//      is called, capacity will become 40 and size will be set to 21.
//  Special case: If the capacity is 0, expand the vector so that it
//      has allocated space of length 1 and set vcapacity to 1.
//      (You can use expand(int))
//  Since other functions will also potentially need to expand (double)
//      the capacity, implement the private helper function named
//      expand (see above) to do this for you.
void IntVector:: push_back( int val2 )
{
    vsize++; 
    if(vcapacity == 0)
    {
        expand(1);
    }
     
    if(vsize > vcapacity)
    {
        expand();
    }
    data[vsize - 1] = val2;
   
}

//  This function just needs to decrease size by 1.
//  This function should call exit(0) if pop_back is called on an
//      empty vector.
void IntVector:: pop_back()
{
    if(vcapacity == 0) exit(0);
   
    vsize--;
   
}
   
//  This function reduces the size of the vector to 0.
void IntVector:: clear()
{
    vsize = 0;
}

//  This function resizes the vector to contain sz elements.
//  If sz is smaller than the current size, this function just reduces
//      the value of size to sz.
//  If sz is greater than the current size, then the appropriate number
//      of elements are inserted at the end of the vector, giving all
//      of the new elements a value of 0.
//  If the new value of size will be larger than capacity,
//      then the capacity should be expanded by either doubling
//      (expand()) or by increasing the capacity by a specific amount
//      (expand( sz - capacity )), whichever results in the
//      largest capacity.
void IntVector:: resize( unsigned int sz )
{
    if(sz < vsize)
    {
        vsize = sz;
    }
    else if(sz > vsize)
    {
        unsigned int difference = vsize -sz;
        vsize = vsize + difference;
        for(unsigned int u = vsize - difference; u < vsize; u++)
        {
            data[u] = 0;
        }
    }
    else
    {
        if((vcapacity* 2) > (sz - vcapacity)) expand();
        else expand((sz -vcapacity));
    }
}

//  This function resizes the vector to containt sz elements.
//  If sz is smaller than the current size, this function just reduces
//      the value of size to sz.
//  If sz is greater than the current size, then the appropriate number
//      of elements are inserted at the end of the vector, giving all
//      of the new elements the value passed in through the 2nd
//      parameter (value).
//  If the new value of size will be larger than capacity, then the
//      capacity should be expanded by either doubling (expand()) or
//      by increasing the capacity by a specific amount
//      (expand( sz - capacity )), whichever results in the
//      largest capacity.
void IntVector:: resize( unsigned int sz, int value )
{
     if(sz < vsize)
    {
        vsize = sz;
    }
    while(sz > vcapacity)
    {
        if((vcapacity* 2) > (sz - vcapacity)) expand();
        else expand((sz -vcapacity));
    }
   
    if(sz > vsize)
    {
        for(unsigned int u = vsize; u < sz; u++)
        {
            data[u] = value;
        }
    }
    vsize = sz;

}
       
//  This function requests that the capacity (the size of the 
//      dynamically allocated array) be set to n at minimum.
//  This informs the vector of a planned increase in size, although
//      notice that the parameter n informs of a minimum,
//      so the resulting capacity may be any capacity equal or
//      larger than this.
//  This function should NOT ever reduce the size of the vector.
//  If n is larger than the current capacity then the capacity
//      should be expanded by either doubling (expand()) or by
//      increasing the capacity by a specific amount
//      (expand( n - capacity )), whichever results in the
//      largest capacity.
//  In any case, a call to this function never affects the
//      elements contained in the vector, nor the vector size.
void IntVector:: reserve( unsigned int n )
{

    if(n > vcapacity)
    {
        if( (vcapacity * 2) > (n - vcapacity))
        {
            expand();
        }
        else
        {
            expand((n - vcapacity));
        }
    }
       
}

//  Assigns new content to the vector object, dropping all the elements
//      contained in the vector before the call and replacing them by
//      those specified by the parameters. The new value of size will
//      be n and all values stored in the vector will have the value
//      of the 2nd parameter.
//  If the new value of size will be larger than capacity,
//      then the capacity should be expanded by either doubling
//      (expand()) or by increasing the capacity by a specific amount
//      (expand( size - capacity )), whichever results in the
//      largest capacity.
void IntVector:: assign( unsigned int n, int value )
{
    for(unsigned int a = 0; a < vsize; a++)
{
erase(a);
}

vsize = n;
if(vsize > vcapacity)
{
expand(vsize - vcapacity);
}

for(unsigned int a = 0; a < vsize; a++)
{
data[a] = value;
}

}
 
//  This function will return a reference to the value stored at the
//      element at the passed in index position. Your function should
//      cause the program to exit if an index greater than or equal to
//      the size is passed in. Because the index is an unsigned int
//      (rather than just int) the compiler will not allow for a
//      negative value to be passed in.
int & IntVector::  at( unsigned int index )
{
    if(index >= vsize)
    {
        exit(0);
    }
    return data[index];
}
       
//  This function overloads the subscript operator and returns a
//      reference to the value stored at the element at the passed in
//      index position. Unlike at function, it does NOT check if
//      index is valid or not.
int & IntVector:: operator[]( unsigned int index )
{
    return data[index];
}
       
//  This function will return the element stored at the first index by
//      reference.
int & IntVector:: front( )
{
    return data[0];

}
       
//  This function will return the element stored at the last
//      index by reference.
int & IntVector:: back( )
{
    return data[vsize - 1]; 
}
