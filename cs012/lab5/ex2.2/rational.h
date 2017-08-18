//Put inclusion guard here
#ifndef RATIONAL_H
#define RATIONAL_H
//Put needed includes here
#include <iostream>

using namespace std;
//This is still outside the class
int gcd( int a, int b );

//Put Rational class here, containing only function *declarations*
class Rational
{
private:
	// Declare private variables.
  int numerator; 
  int denominator; 
public:

	// Declare three constructors here.
  Rational();
  Rational(int a, int b);
  Rational(int a);

	// Declare the aritmethic functions here.
  Rational add( const Rational & val ) const;
  Rational subtract( const Rational & val ) const;
  Rational multiply( const Rational & val ) const;
  Rational divide( const Rational & val ) const;
  
  //Declare mutators
  int get_num() const;
  int get_denom() const;
  
  // Declare the print function that outputs the Rational object to console.
  void print() const;
};

//end the inclusion guard
#endif
