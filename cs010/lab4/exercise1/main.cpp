#include "instinct.h"

int instinct_main()
{
     Point p = win.get_click("Click on a point");
     double side = win.get_double("Input a lenghth for side of a square");
     Rect r = Rect(p, side, side);
     
     double radius = (side/2.0);
     double x = p.get_x()+radius;
     double y = p.get_y()+radius;
     
     Circle c = Circle(Point(x,y), radius);
     
     Message m = Message(Point(x,y), radius);
          
     win << r << c << m;
     
     win.output_buffer();
     return(0);
}
