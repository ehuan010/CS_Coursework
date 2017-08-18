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
// Assignment: assn2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

//Start the inclusion Guard
#ifndef DATE_H
#define DATE_H

//Needed includes
#include <iostream>

using namespace std;

//Date class with only function declarations
class Date
{
private:
  //Declaration of private variables and member functions
  int day;
  int month;
  int year;
  string month_name;
  bool is_leap( int y ) const;
  int days_per_month( int m, int y ) const;
  string name( int m ) const;
  int number( const string &mn ) const;
  
public:
  //Declaration of three constructors
  Date( );
  Date( int m, int d, int y );
  Date( const string &mn, int d, int y );
  
  //Declaration of the print_numeric function that outputs the Date object to
  //the console in the format 3/1/2010 
  void print_numeric( ) const;
  
  //Declaration of the print_alpha function that outputs the Date object to
  //the console in the format March 1, 2010
  void print_alpha( ) const;
};

//End the inclusion guard
#endif
