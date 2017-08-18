//Shape implementation file

#include "jshape.h"
#include <iostream>
using namespace std;

JShape::JShape()
  : center( Point(0,0) ), color(BLACK)
{
	cout<<"JShape(): Constructor called"<<endl;

}

JShape::JShape(Point center)
: center( center ), color(BLACK)
{
	cout<<"JShape(Point): Constructor called"<<endl;
}

JShape::JShape(Point center, Color color)
: center( center ), color(color)
{
	cout<<"JShape(Point,Color): Constructor called"<<endl;
}


Point JShape::get_center() const
{
  return center;
}

void JShape::set_center(const Point& c)
{
  center=c;
}

JShape::~JShape()
{
	cout<<"JShape: Destructor called"<<endl;
}
