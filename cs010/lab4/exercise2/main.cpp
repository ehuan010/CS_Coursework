#include "instinct.h"

int instinct_main()
{
     //first
     Circle c = Circle(Point(2, 6), 1);
     c.set_color(BLUE);
     win << c;
     win.output_buffer();
     
     //second
     c.move(1.2, -1);
     c.set_color(YELLOW);
     win << c;
     win.output_buffer();
     
     //third
     c.move(1.2, 1);
     c.set_color(BLACK);
     win << c;
     win.output_buffer();
     
     //fourth
     c.move(1.2, -1);
     c.set_color(GREEN);
     win << c;
     win.output_buffer();
     
     //fifth
     c.move(1.2, 1);
     c.set_color(RED);
     win << c;
     win.output_buffer();
     
     return(0);
}

