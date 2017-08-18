#include "instinct.h"

int instinct_main()
{
     //background and cool title
     win.set_background_color(BLACK);
     win.set_title("Awesome House");
     win.output_buffer();
     
     //base of house
     Point llb = win.get_click("Click where you want a square", WHITE);
     Rect r = Rect(llb, 5, 5, RED, true);

     win << r;
     win.output_buffer();
     
     //triangle
     Point one = win.get_click("Click where you want a triangle", WHITE);
     double x = one.get_x();
     double y = one.get_y();
     Point two = Point(x+4, y+3);
     Point three = Point(x+8, y);
     
     Triangle t = Triangle(one, two, three, BROWN, true);
     win << t;
     win.output_buffer();
     
     //window
     Point four = win.get_click("Click for square window", WHITE);
     Rect window = Rect(four, 1, 1);
     window.set_color(GREEN);
     double x1 = four.get_x();
     double y1 = four.get_y();
     Line up_down = Line(Point(x1+.5, y1+1), Point(x1+.5, y1));
     Line left_right = Line(Point(x1, y1+.5), Point(x1+1, y1+.5));
     up_down.set_color(GREEN);
     left_right.set_color(GREEN);
     win << window << up_down << left_right;
     win.output_buffer();
     
     //door
     Point six = win.get_click("Click for door", WHITE);
     six.set_color(WHITE);
     Rect door = Rect(six, 2, 2.5, BLUE, true);
     win << door;
     win.output_buffer();
     
     //Message
     string fname = win.get_string("Enter your first name", WHITE);
     string lname = win.get_string("Enter your last name", WHITE);
     string fname_lname = fname + " " + lname + "'s House";
     Point five = win.get_click("Click name display location", WHITE);
     Message m = Message(five, fname_lname);
     win << m;
     win.output_buffer();
     
     return(0);
}

