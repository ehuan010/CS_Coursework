#include <cmath>
#include "instinct.h"

// global consts:
const double PI = 3.14159265;
const int LINES_PER_FLAKE = 4;

//Give the user the choice of the length, how many times they want to redraw 
//the pattern, and at one point they want to be
void snowflake(double length, int pats, Point p) ;

int instinct_main()
{
    win.coord(-50,-50,50,50); 
    double length = 30.0 ; //Length of each line
    int pats = 6 ; //How many times it redraws the snowflake 
    Point p = Point(0,0) ; //Middle of the screen 
    
    //Calling function to make it
    snowflake(length,pats,p) ; 
    
    //Outputting the snowflake
    win.output_buffer() ;

  return 0;
}
 


 void snowflake(double length, int pats, Point p)
{
    //First Base Case
    if(pats < 1) 
    {
        return ; 
    }

    //designating the amount of patterns that need to be drawn 
    double pats_limit = 25.0/pow(3.0,pats - 1.0) ; 
    
    //Second Base Case 
    if(length < pats_limit) 
    {
        return ; 
    } 
    
    int i = 0;
    while (i < LINES_PER_FLAKE)
    {
        //Drawing the initial line 
        Line l(p,Point(p.get_x() + (length * cos(i * PI/3)), p.get_y() + 
        (length * sin(i * PI/3)))) ; 
        
        //Declaring the output       
        win << l ; 
        
        //Redrawing snowflake with new angles 
        snowflake(length/3, pats, Point(p.get_x() + 
        (length * cos(i * PI/3)), p.get_y() + (length * sin(i * PI/3))));
        
        //Using a counter to change the angle afterwards 
        i++;
    }   
}
