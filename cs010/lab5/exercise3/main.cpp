#include <iostream>
#include "instinct.h"

int instinct_main()
{
    // Constants
    const string WINDOW_TITLE = "Lab 5: Coordinate Systems Exercise";
    const int WINDOW_HEIGHT = 500;
    const int WINDOW_WIDTH = 500;
    const int X_MIN = -7;           // X axis minimum                   
    const int X_MAX = 7;            // X axis maximum                   
    const int Y_MIN = -7;           // Y axis minimum                   
    const int Y_MAX = 7;            // Y axis maximum                   
    const double OFFSET = .1;       // Spacer for number line and axes  
    const int N = 10;               // Number of times to loop program  

    // Variable declarations 
    Point clicked;                  // Point for user input             
    Point axis_number;              // Point for axis number output     
    Line x_axis, y_axis;            // Line objects for axes            
    Message m;                      // Object for message output        
    double x_click, y_click;        // X,Y for storing click location   
    int i, x, y;                    // Looping variables                
    string quadrant = "";           // Quadrant string for click point  
    
    // My code Exercise 3 Part 1 + 2
    win.set_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
    win.coord(X_MIN, Y_MIN, X_MAX, Y_MAX);
    win.set_title("XY Coordinate Plane");
    y_axis = Line(Point(0, Y_MAX), Point(0, Y_MIN));
    x_axis = Line(Point(X_MIN, 0), Point(X_MAX, 0));
    win << x_axis << y_axis;
    win.output_buffer();
    
    clicked = win.get_click("Click on a Quadrant");
    x_click = clicked.get_x();
    y_click = clicked.get_y();
    if(x_click >= 0 && y_click >=0)
    {
         quadrant = "Quadrant I";
         m = Message(clicked, quadrant);
    }
    else if(x_click <= 0 && y_click >= 0)
    {
         quadrant = "Quadrant II";
         m = Message(clicked, quadrant);
    }
    else if(x_click <= 0 && y_click <= 0)
    {
         quadrant = "Quadrant III";
         m = Message(clicked, quadrant);
    }
    else
    {
         quadrant = "Quadrant IV";
         m = Message(clicked, quadrant);
    }
     win << m;
     win.output_buffer();

    return(0);
}
