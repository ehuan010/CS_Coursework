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


// CS12 Lab 9 Framework
// Author: Muzaffer Akbay
#include <iostream>
#include <vector>
#include <ctime> //required for timing
#include <cstdlib>
//#include <iomanip>

#include "sorting.h"
#include "utils.h"

using namespace std;



int main(){

	int data_size;
	cout << "Enter data set size between 10 and 100: ";
	cin >> data_size;


	int method;
	cout << "Enter \n1 for Selection sort, \n2 for Bubble sort, "
		<< "\n3 for Optimized Bubble Sort, \n4 for Insertion sort"
    << "\n5 for Merge sort :";
	cin >> method;
	while(method>5 || method<1){
		cout<<"INVALID SELECTION"<<endl;
		cout << "Enter \n1 for Selection sort, \n2 for Bubble sort, "
			<< "\n3 for Optimized Bubble Sort, \n4 for Insertion sort, "
      << "\n5 for Merge sort :";
		cin >> method;
	}
	vector<int> v, orig;
	generate_random_set(v, data_size);
	orig = v;

	cout << endl;
	cout << "Before Sorting: \n  "<<v<<endl;
	
	switch(method){
		case 1:
			selection_sort(v);
			break;
		case 2:
			bubble_sort(v);
			break;
		case 3:
			op_bubble_sort(v);
			break;
    case 4:
			insertion_sort(v);
			break;
		default:
			merge_sort(v);
	}
	cout<<endl;
	cout << "After Sorting: \n  "<<v<<endl<<endl;
	cout << "Comparing with STL sort... "<<endl;
	stl_sort(orig);
	if(orig == v) cout << "DONE!\n Your algorithm works correctly on this dataset."<<endl;
	else cout << "DONE!\n Your algorithm does NOT work correctly."<<endl;

  int num;
  string answer;
  cout << endl;
  cout << "Would you like to search for a number? (y/n)";
  cin >> answer;
  if(answer == "y")
  {
    cout << "Choose a number to search for: ";
    cin >> num;
    cout << "The number is at index: " << binary_search(v, num);
    cout << endl;
  }
	return -1;
}

