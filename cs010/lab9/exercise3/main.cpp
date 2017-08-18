#include "instinct.h"

const double X = 5;
const double Y = 5;
const double X_MOVE = .10;
const double Y_MOVE = .15;
const double RADIUS = .5;
int instinct_main()
{
  double x_move = X_MOVE;
  double y_move = Y_MOVE;
  win.coord(0, 0, 10, 10);
  Circle c = Circle(Point(X,Y), RADIUS, BLUE, true);
  win << c;
  //win.output_buffer();
  //win.clear_buffer();

  while(!win.left_mouse_down())
  {
    wait_for(30);
    c.move(x_move, y_move);
    win.clear_buffer();
    win << c;
    win.output_buffer();
    
    
    if(c.get_center().get_x() + RADIUS >= 10 || 
    c.get_center().get_x() - RADIUS <= 0)
    {
      x_move = -x_move;
    }
    
    if(c.get_center().get_y() + RADIUS >= 10 ||
    c.get_center().get_y() - RADIUS <= 0)
    {
      y_move = -y_move;
    }
  }
}
