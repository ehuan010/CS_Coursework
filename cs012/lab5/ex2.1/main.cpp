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
  Rational sum = b+c;
  Rational sum1 = a+c;
  Rational subtract = b-c;
  Rational divide = b/c;
  Rational multiply = b*c;
  Rational negative = -b;
  sum.print();
  sum1.print();
  subtract.print();
  divide.print();
  multiply.print();
  negative.print();
  Rational X(3,4);
  Rational Y = X + 5;
  Y.print();
  //Rational Z = 2+X;
  //Z.print(); 
  
	return 0;
}

