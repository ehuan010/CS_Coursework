//square implementation file

#include "jsquare.h"
#include "instinct.h"
#include <iostream>
using namespace std;

JSquare::JSquare()
	: JRectangle()
{
	cout<<"JSquare(): Constructor called"<<endl;
  side = 0.0;
}

JSquare::JSquare(Point c)
  : JRectangle(c), side(1.0)
{
	cout<<"JSquare(Point): Constructor called"<<endl;
}

JSquare::JSquare(Point center, Color color)
  : JRectangle(center,color), side(1.0)
{
	cout<<"JSquare(Point,Color): Constructor called"<<endl;
}



//calls Shape constructor to set center Point
JSquare::JSquare(Point center, double side)
  : JRectangle(center), side(side)
{
	cout<<"JSquare(Point,double): Constructor called"<<endl;
}

JSquare::JSquare(Point center, double side, Color color)
  : JRectangle(center,color), side(side)
{
	cout<<"JSquare(Point,double,Color): Constructor called"<<endl;
}


double JSquare::area() const
{
  return side * side;
}

void JSquare::plot() const
{
  //corners are 1/2 width and 1/2 height from center
  double horiz_displacement = side / 2.0;
  double vert_displacement = side / 2.0;

	Rect r = Rect(Point(0,0),side,side,color);
	Point c = get_center();
	r.move(c.get_x()-horiz_displacement ,c.get_y()-vert_displacement);

	r.set_filled_in(true);
	win<<r;

	r.set_color(BLACK);
	r.set_filled_in(false);
	win<<r;

}

JSquare::~JSquare()
{
	cout<<"JSquare: Destructor called"<<endl;
}
