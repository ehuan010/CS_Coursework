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
// Assignment: assn8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <vector>

#include "sorting.h"

using namespace std;

//EXERCISE 1: Implement STL Sort Function.
//See sorting.h for function signature
void stl_sort( vector<int> &v )
{
  sort( v.begin(), v.end() );
}

int find_min(unsigned s, vector<int> v)
{
  int start_index = v[s];
  int min;
  for(unsigned i = s; i < v.size(); i++)
  {
    if(start_index > v[i])
    {
      min = i;
      start_index = v[i];
    }
  }
  return min;
}

void swap(int & a, int & b)
{
  int temp = a;
  a = b;
  b = temp;
}

void selection_sort( vector<int> & v )
{
	//EXERCISE 2: Implement Selection Sort
  for(unsigned i = 0; i < v.size(); i++)
  {
    int min = find_min(i, v);
    swap(v[min], v[i]);
  }
}


void insertion_sort( vector<int> & v )
{
	//EXERCISE 3: Implement Insertion Sort
  int current;
  int index;
  for(unsigned i = 1; i < v.size(); i++)
  {
    current = v[i];
    index = i - 1;
    while(v[index] > current && index >= 0)
    {
      v[index+1] = v[index];
      index -= 1;
    }
    v[index+1] = current;
  }
}


void bubble_sort( vector<int> & v )
{
	//EXERCISE 4: Implement Bubble Sort
  for(unsigned i = 0; i < v.size(); i++)
  {
    for(unsigned j = 0; j < i; j++)
    {
      if(v[i] < v[j])
      {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }
}

void op_bubble_sort( vector<int> & v )
{
	//EXERCISE 5: Optimize the Bubble Sort Function
  for(unsigned i = 0; i < v.size(); i++)
  {
    for( unsigned j = (v.size() - 1); j > i; j--)
    {
      if(v[j] < v[j-1])
      {
        swap(v[j], v[j-1]);
      }
    }
  }
}

/* Merges two vectors together and sorts it
 * @param v: Original vector passed in
 * @param a: Temp vector to order the original vector
 * @param beg: First index of the first vector
 * @param mid1: Index of the end of the first vector
 * @param mid2: First index of the second vector
 * @param end: End of the second vector
 */
void merge( vector<int> & v, vector<int> & a, unsigned beg, unsigned mid1, 
            unsigned mid2, unsigned end)
{
  //if the index of the beginning of either vector is larger than the end
  //then return without doing anything. Base case.
  if(beg > mid1 && mid2 > end)
  {
    return;
  }
  
  //if the beginning of both vectors is less than or equal to their end
  //perform the creation of the merged vector and do the recursion
  if(beg <= mid1 && mid2 <= end)
  {
    //when the number at first index of first vector is smaller than 
    //first index of second vector
    if(v[beg] < v[mid2])
    {
      a.push_back(v[beg]); //pushback into temporary vector
      //update the first index of first vector and recurse
      merge(v, a, beg + 1, mid1, mid2, end); 
    }
    else //otherwise
    {
      a.push_back(v[mid2]); //pushback the first index of second vector
      //update the first index of second vector and recurse
      merge(v, a, beg, mid1, mid2 + 1, end); 
    }
  }
  else if(beg <= mid1) //otherwise when first index is <= the end of first
  {
    //pushback the index at beg
    a.push_back(v[beg]);
    //shift the index by 1 and recurse
    merge(v, a, beg + 1, mid1, mid2, end);
  }
  else if(mid2 <= end) //otherwise when second index <= the end of second
  {
    //pushback the index at mid2
    a.push_back(v[mid2]);
    //shift the index by 1 and recurse
    merge(v, a, beg, mid1, mid2 + 1, end);
  }
}

/* Sorts and pushes back temp vector into original vector
 * @param v: Original vector passed in
 * @param from: First index of the vector
 * @param to: Last index of the vector
 */
void merge_recurse(vector<int> & v, unsigned from, unsigned to)
{
  //create a temp vector
  vector<int>a;
  //Base case to stop recursion
  if(from == to)
  {
    return;
  }
  //middle of the vector
  int mid = (from + to) / 2;
  //perform recursion
  merge_recurse(v, from, mid);
  merge_recurse(v, mid + 1, to);
  merge(v, a, from, mid, mid+1, to);
  //copy the temp vector into the original vector
  for(unsigned j = 0; j < a.size(); j++)
  {
    v[from + j] = a[j];
  }
}


/* Merge sort
 * @param v: Original vector passed in
 */
void merge_sort( vector<int> & v)
{
  //call merge_recurse with initial conditions
  merge_recurse(v, 0, v.size()-1);
}

/* Recursively looks for a number in a sorted vector
 * @param v: Original vector passed in
 * @param target: Number that you are searching for
 * @param start: First index of the vector
 * @param end: Last index of the vector
 */
int binary_search_recursive(const vector<int> &v, int target, 
                            unsigned start, unsigned end)
{
  //middle of the vector
  unsigned mid = (start + end) / 2;
  //when start is less than end continue the recursion
  if(start <= end)
  {
    //if the target is at index mid
    if(target == v[mid])
    {
      //return index mid
      return mid;
    }
    //otherwise when target is less than number at index mid
    else if(target < v[mid])
    {
      //recurse the function and decrease end by mid - 1
      return binary_search_recursive(v, target, start, mid - 1);
    }
    //otherwise when target is greater than number at index mid
    else
    {
      //recurse the function and increase start by mid + 1
      return binary_search_recursive(v, target, mid + 1, end);
    }
  }
  //if it is not found just return -1
  return -1;
}

//Finally, build a recursive binary search function, which:
//1) locates the target in the specified container, and returns the 
//index at which it is located; or
//2) returns -1 to indicate that the target is not present in the container
/* Binary Search
 * @param v: Original vector passed in
 * @param target: Number that you are searching for
 */
int binary_search(const vector<int> & v, int target )
{
  //call binary_search_recursive with initial conditions
  return binary_search_recursive(v, target, 0, v.size()-1);
}
