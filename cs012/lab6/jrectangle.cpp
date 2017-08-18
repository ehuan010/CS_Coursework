//rectangle implementation file

#include "jrectangle.h"
#include "instinct.h"
#include <iostream>
using namespace std;

JRectangle::JRectangle()
	: JShape()
{
	cout<<"JRectangle(): Constructor called"<<endl;
  height = 0;
  width = 0;
}

JRectangle::JRectangle(Point c)
  : JShape(c), height(0.75), width(1.5)
{
	cout<<"JRectangle(Point): Constructor called"<<endl;
}

JRectangle::JRectangle(Point center, Color color)
  : JShape(center,color), height(0.75), width(1.5)
{
	cout<<"JRectangle(Point,Color): Constructor called"<<endl;
}



//calls Shape constructor to set center Point
JRectangle::JRectangle(Point center, double h, double w)
  : JShape(center), height(h), width(w)
{
	cout<<"JRectangle(Point,double,double): Constructor called"<<endl;
}

JRectangle::JRectangle(Point center, double h, double w, Color color)
  : JShape(center,color), height(h), width(w)
{
	cout<<"JRectangle(Point,double,double,Color): Constructor called"<<endl;
}


double JRectangle::area() const
{
  return height * width;
}

void JRectangle::plot() const
{
  //corners are 1/2 width and 1/2 height from center
  double horiz_displacement = width / 2.0;
  double vert_displacement = height / 2.0;

	Rect r = Rect(Point(0,0),width,height,color);
	Point c = get_center();
	r.move(c.get_x()-horiz_displacement ,c.get_y()-vert_displacement);

	r.set_filled_in(true);
	win<<r;

	r.set_color(BLACK);
	r.set_filled_in(false);
	win<<r;

}

JRectangle::~JRectangle()
{
	cout<<"JRectangle: Destructor called"<<endl;
}
