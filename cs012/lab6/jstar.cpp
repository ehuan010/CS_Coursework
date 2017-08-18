


#include <cmath>
#include "jshape.h"
#include "jstar.h"
#include "instinct.h"

//#define M_PI 3.1415926536897932384626433832


JStar::JStar()
    : JShape()
{

	radius = 0.5;
}
JStar::JStar(Point ll)
    : JShape(ll)
{

	radius = 0.5;
}

JStar::JStar(Point ll,Color c)
    : JShape(ll,c)
{

	radius = 0.5;
}

JStar::JStar(Point l_l, double r)
        : JShape(l_l)
{
    //p = l_l;
    radius = r;
}

JStar::JStar(Point l_l, double r,Color c)
        : JShape(l_l,c)
{
    //p = l_l;
    radius = r;
}

  double JStar:: area() const
{

  return 5*sin(M_PI/5.0)*radius*radius;
}

void JStar:: plot() const
{

  //move lines and output right vertical and upper horizontal lines
  /*vert.move(base, 0);
  horiz.move(-height, 0);
  win << horiz;
*/
//	win<<Circle(get_center(),radius);

	float in = -90*M_PI/180;
	float out = -54*M_PI/180;
	float inc = 72*M_PI/180;

	float R = radius;
	float r = R/2;

	Point c = get_center();

	Point p1,p2,p3=	Point(cos(in)*r,sin(in)*r);

	for(int i=0;i<5;i++){
		p1=p3;
		p2=Point(cos(out)*R,sin(out)*R);
		in+=inc;
		p3=Point(cos(in)*r,sin(in)*r);

		Line l1(p1,p2);
	 	l1.move(c.get_x(),c.get_y());
		Line l2(p2,p3); 
		l2.move(c.get_x(),c.get_y());
		Triangle t1(p1,p2,p3,color); 
		t1.set_filled_in(true);
		t1.move(c.get_x(),c.get_y());
		Triangle t2(p1,Point(0,0),p3,color); 
		t2.move(c.get_x(),c.get_y());
		t2.set_filled_in(true);
		win<<t1<<t2;
		win<<l1<<l2;

		out+=inc;


	
	}
		
  win.output_buffer();


}
