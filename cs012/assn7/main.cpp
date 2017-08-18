// Course: CS 12 Winter 2012
//
// First Name: Edward
// Last Name: Huang
// Course username: ehuan010
// email address: ehuan010@student.ucr.edu
//
// Lecture Section: 002
// Lab Section: 022
// TA: Wojchiek Karas
//
// Assignment: assn7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <cmath>
#include "instinct.h"

// global consts:
const double PI = 3.14159265;
const int LINES = 6; //The amount of lines drawn for each flake

// declare recursive function
void snowflake(Point start, int levels, double length);

int instinct_main()
{
  // test harness for recursive function
  win.coord(0,0,100,100); //Set the window coordinate
  Point start = Point(50,50); //starting point
  int levels = 4; //How many levels of snowflakes you want
  double length = 25.0; //The length you want your line to start out as
  
  //calls the snowflake function
  snowflake(start,levels,length);
  //outputs everything stored in the buffer
  win.output_buffer();
  
  return 0;
}


// define recursive function
void snowflake(Point start, int levels, double length)
{
  //Declare the boundary to make sure the length doesn't get too small
  double boundary = 25.0/(pow(3.0,levels - 1.0));
  //Base case: If the level is less than 1 the program should not do anything
  if(levels < 1)
  {
    return;
  }
  //Base case: If the length is larger than the boundary, stop the recursion
  if(length < boundary)
  {
    return;
  }
  
  //Loop to draw the individual specified lines for a snowflake
  for(int i = 0; i < LINES; i++) 
  {
    //Draws the lines
    Line l = Line(start,Point(start.get_x() + (length * cos(i * (PI / 3))), 
                  start.get_y() + (length * sin(i * (PI / 3)))));
    //Places the lines into the buffer
    win << l;
    //recursive call to snowflake changing the starting point and length
    snowflake(Point(start.get_x() + (length * cos(i * (PI / 3))), 
              start.get_y() + (length * sin(i * (PI / 3)))), levels,
              length/3);
  }
}
