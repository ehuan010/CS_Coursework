// Put needed includes here
#include <iostream>

// Tell the program to use the standard namespace
using namespace std;

// Greatest common denominator function
// Returns  the gcd of a and b as an int.
// You can use this to reduce your fractions.
// make this a global function (i.e. *separate* from the class)
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

//Put Rational class here
class Rational
{
private:
// Declare private members here
int numerator; 
int denominator; 

public:

	// Put all three constructors here (both declaration and implementation).
  //default constructor:
	Rational()
  {
    numerator = 0;
    denominator = 1;
		//Put implementation here
  }

	//constructors with two parameters:
  Rational(int a, int b)
  {
    numerator = a;
    denominator = b;
  }

	//constructors with one parameter:
  Rational(int a)
  {
    numerator = a;
    denominator = 1;
  }
  
	// Put aritmetic functions here (both declaration and implementation).
  
	//addition:
	Rational add( const Rational & val ) const
	{
    int top = (numerator * val.denominator) + (denominator * val.numerator);
    int bottom = denominator * val.denominator;
    return Rational(top, bottom);
	}

	//subtraction
  Rational subtract( const Rational & val ) const
	{
    int top = (numerator * val.denominator) - (denominator * val.numerator);
    int bottom = denominator * val.denominator;
    return Rational(top, bottom);
	}
  
	//multiplication
  Rational multiply( const Rational & val ) const
	{
    int top = (numerator * val.numerator);
    int bottom = denominator * val.denominator;
    return Rational(top, bottom);
	}
  
	//division
  Rational divide( const Rational & val ) const
	{
    int top = (numerator * val.denominator);
    int bottom = denominator * val.numerator;
    return Rational(top, bottom);
	}


	// Put the print function here (both declaration and implementation).
  void print() const
  {
     cout << numerator << "/" << denominator << endl;
  }

//close class definition
};



//Write a simple main to test your class here.

int main()
{
  Rational a;
  Rational b(2);
  Rational c(1, 4);
  Rational sum = b.add(c);
  Rational sum1 = a.add(c);
  Rational subtract = b.subtract(c);
  Rational divide = b.divide(c);
  Rational multiply = b.multiply(c);
  sum.print();
  sum1.print();
  subtract.print();
  divide.print();
  multiply.print();
  
	return 0;
}
