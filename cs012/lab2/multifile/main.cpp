//Put needed includes here
#include <iostream>
#include "rational.h"

//Tell program to use standard namespace
using namespace std;

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
  sum.print();
  sum1.print();
  subtract.print();
  divide.print();
  multiply.print();
  
	return 0;
}

