//Include rational.h
#include <iostream>
#include "rational.h"

// Not a member of the Rational class, just a global function we decided to
//  implement alongside the class
// It could go here, or in main.cpp,
//  but since it will always be needed by the Rational class
//  it makes a lot more sense to keep it here

int gcd( int a, int b )
{
    int c = a % b;
    while( c != 0 )
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}


// Put the implementation of the rational class functions here.
// Do not forget to put the scope of the class before function names
Rational::Rational()
{
  numerator = 0;
  denominator = 1;
  //Put implementation here
}

//constructors with two parameters:
Rational::Rational(int a, int b)
{
  numerator = a;
  denominator = b;
}

//constructors with one parameter:
Rational::Rational(int a)
{
  numerator = a;
  denominator = 1;
}

//Put aritmetic functions here (both declaration and implementation).

//addition:
Rational Rational::operator+( const Rational & val ) const
{
  int top = (numerator * val.denominator) + (denominator * val.numerator);
  int bottom = denominator * val.denominator;
  return Rational(top, bottom);
}

//subtraction
Rational Rational::operator-( const Rational & val ) const
{
  int top = (numerator * val.denominator) - (denominator * val.numerator);
  int bottom = denominator * val.denominator;
  return Rational(top, bottom);
}

//multiplication
Rational Rational::operator*( const Rational & val ) const
{
  int top = (numerator * val.numerator);
  int bottom = denominator * val.denominator;
  return Rational(top, bottom);
}

//division
Rational Rational::operator/( const Rational & val ) const
{
  int top = (numerator * val.denominator);
  int bottom = denominator * val.numerator;
  return Rational(top, bottom);
}

//negation/additive inverse
Rational Rational::operator-() const
{
  return Rational((-1*numerator),denominator);
}
// Put the print function here (both declaration and implementation).
void Rational::print() const
{
   cout << numerator << "/" << denominator << endl;
}

