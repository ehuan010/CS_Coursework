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

void merge( vector<int> & v, vector<int> & a, unsigned beg, unsigned mid1, 
            unsigned mid2, unsigned end)
{
  if(beg > mid1 && mid2 > end)
  {
    return;
  }
  
  if(beg <= mid1 && mid2 <= end)
  {
    if(v[beg] < v[mid2])
    {
      a.push_back(v[beg]);
      merge(v, a, beg + 1, mid1, mid2, end);
    }
    else
    {
      a.push_back(v[mid2]);
      merge(v, a, beg, mid1, mid2 + 1, end);
    }
  }
  else if(beg <= mid1)
  {
    a.push_back(v[beg]);
    merge(v, a, beg + 1, mid1, mid2, end);
  }
  else if(mid2 <= end)
  {
    a.push_back(v[mid2]);
    merge(v, a, beg, mid1, mid2 + 1, end);
  }
}

void merge_recurse(vector<int> & v, unsigned from, unsigned to)
{
  vector<int>a;
  if(from == to)
  {
    return;
  }
  int mid = (from + to) / 2;
  merge_recurse(v, from, mid);
  merge_recurse(v, mid + 1, to);
  merge(v, a, from, mid, mid+1, to);
  for(unsigned j = 0; j < a.size(); j++)
  {
    v[from + j] = a[j];
  }
}



void merge_sort( vector<int> & v)
{
  merge_recurse(v, 0, v.size()-1);
}

int binary_search_recursive(const vector<int> &v, int target, 
                            unsigned start, unsigned end)
{
  unsigned mid = (start + end) / 2;
  if(start <= end)
  {
    if(target == v[mid])
    {
      return mid;
    }
    else if(target < v[mid])
    {
      return binary_search_recursive(v, target, start, mid - 1);
    }
    else
    {
      return binary_search_recursive(v, target, mid + 1, end);
    }
  }
  return -1;
}

//Finally, build a recursive binary search function, which:
//1) locates the target in the specified container, and returns the 
//index at which it is located; or
//2) returns -1 to indicate that the target is not present in the container

int binary_search(const vector<int> & v, int target )
{
  return binary_search_recursive(v, target, 0, v.size()-1);
}
