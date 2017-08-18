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

//void merge_sort( vector<int> & v )
//{

//}

//int binary_search( vector<int> & v, int target )
//{

//}
