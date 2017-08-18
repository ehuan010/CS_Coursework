//Put needed includes here
#include <iostream>
#include "rational.h"

//Tell program to use standard namespace
using namespace std;

//Global functions

Rational operator+( const Rational & lhs, const Rational & val )
{
  int top = ((lhs.get_num() * val.get_denom()) + 
            (lhs.get_denom() * val.get_num()));
  int bottom = lhs.get_denom() * val.get_denom();
  return Rational(top, bottom);
}

Rational operator-( const Rational & lhs, const Rational & val )
{
  int top = ((lhs.get_num() * val.get_denom()) - 
            (lhs.get_denom() * val.get_num()));
  int bottom = lhs.get_denom() * val.get_denom();
  return Rational(top, bottom);
}

Rational operator*( const Rational & lhs, const Rational & val )
{
  int top = (lhs.get_num() * val.get_num());
  int bottom = lhs.get_denom() * val.get_denom();
  return Rational(top, bottom);
}

Rational operator/( const Rational & lhs, const Rational & val )
{
  int top = (lhs.get_num() * val.get_denom());
  int bottom = lhs.get_denom() * val.get_num();
  return Rational(top, bottom);
}

Rational operator-( const Rational & op )
{
  return Rational((-1*op.get_num()), op.get_denom());
}

//changing << operator
ostream& operator<<(ostream& out, const Rational& val) 
{
  out << val.get_num() << "/" << val.get_denom();
  return out;
}



//Copy your main from all_in_one.cpp and put it here
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
  Rational negative = -c;

  cout << sum << endl << sum1 << endl << subtract 
       << endl << divide << endl << multiply << endl << negative << endl;
  cout << b << " + " << c << " = " << b+c << endl;
  
  Rational X(3,4);
  Rational Y = X + 5;
  Y.print();
  Rational Z = 2+X;
  Z.print(); 
	
  return 0;
}

