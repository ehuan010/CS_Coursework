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

#ifndef _M_SORTING_H_
#define _M_SORTING_H_

#include <vector>

using namespace std;

void selection_sort( vector<int> & v );

void bubble_sort( vector<int> & v );

void op_bubble_sort( vector<int> & v );

void insertion_sort( vector<int> & v );

// for assignment 8
void merge( vector<int> & v, vector<int> & a, unsigned beg, unsigned mid1, 
            unsigned mid2, unsigned end);
void merge_recurse(vector<int> & v, unsigned from, unsigned to);
void merge_sort( vector<int> & v);

// for assignment 8

int binary_search_recursive(const vector<int> &v, int target, 
                            unsigned start, unsigned end);
int binary_search(const vector<int> & v , int target);

void stl_sort( vector<int> &v );

#endif
