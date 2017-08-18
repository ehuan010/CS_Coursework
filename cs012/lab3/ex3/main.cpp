#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
  Rational frac1(3,10);
  Rational frac2(7,1);
  Rational* rp3 = new Rational;
  *rp3 = Rational(5,3);
  Rational* rp4 = new Rational;
  *rp4 = Rational(6,1);
  
  frac1.print();
  frac2.print();
  (*rp3).print();
  (*rp4).print();
  
  cout << endl;
  
  Rational i = frac1.add(frac2);
  i.print();
  
  Rational ii = frac2.subtract(*rp3);
  ii.print();
  
  Rational iii = (*rp4).multiply(frac1);
  iii.print();
  
  Rational iv = (*rp3).divide(*rp4);
  iv.print();
  
  delete rp3;
  delete rp4;
	return 0;
}

