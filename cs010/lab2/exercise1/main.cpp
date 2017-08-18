// Course: CS 10 Fall 2011
//
// First Name: Edward
// Last Name: Huang
// Login id: ehuan010
// email address: ehuan010@student.ucr.edu
//
// Lecture Section: 003
// Lab Section: 023
// TA: Huy Hang
//
// Assignment: Lab 2 Exercise 1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include <iostream>
using namespace std;

int main()
{
	//set two integer types and name the variables
	int first_integer;
	int second_integer;
	
	//output a message to user to input an integer
	cout << "Enter the first integer: ";
	cin >> first_integer;
	cout << "Enter the second integer: ";
	cin >> second_integer;
	
	//output sum
	int sum = first_integer + second_integer;
	cout << first_integer 
	     << " + " 
	     << second_integer 
	     << " = " << sum 
	     << endl;
	
	//output product
	int product = first_integer * second_integer;
	cout << first_integer
	     << " * "
	     << second_integer
	     << " = " 
	     << product
	     << endl;
	
	//output integer quotient
	int integer_quotient = first_integer / second_integer;
	cout << first_integer
	     << " / "
	     << second_integer
	     << " = "
	     << integer_quotient
	     << endl;
	     
	return 0;
}
