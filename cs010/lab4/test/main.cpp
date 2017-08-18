#include "instinct.h"

int instinct_main()
{
     Circle first_c = Circle(Point(2,6),.5);
     first_c.set_color(BLUE);
     win.output_buffer();
     return(0);
}
