// Course: CS 10 Fall 2011
//
// First Name: Edward
// Last Name: Huang
// Login id: ehuan010
// email address: ehuan010@student.ucr.edu
//
// Lecture Section: 003
// Lab Section: 023
// TA: Huy Hang
//
// Assignment: Assignment 5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include "instinct.h"
#include <cmath>

int instinct_main()
{
    //inputs from user in this order
    //xmin
    //xmax
    //ymin
    //ymax
    //Coefficient of 4th degree term
    //Coefficient of 3rd degree term
    //Coefficient of 2nd degree term
    //Coefficient of 1st degree term
    //Constant (coefficient of 0th degree term)
    int xmin = win.get_int("Enter minimum x coordinate");
    int xmax = win.get_int("Enter maximum x coordinate");
    int ymin = win.get_int("Enter minimum y coordinate");
    int ymax = win.get_int("Enter maximum y coordinate");
    double coef_fourth;
    coef_fourth = win.get_double("Enter coefficient of 4th degree term");
    double coef_third;
    coef_third = win.get_double("Enter coefficient of 3rd degree term");
    double coef_second;
    coef_second = win.get_double("Enter coefficient of 2nd degree term");
    double coef_first;
    coef_first = win.get_double("Enter coefficient of 1st degree term");
    double constant;
    constant = win.get_double("Enter coefficient of 0th degree term");
    
    //output windows coordinate using user input
    win.coord(xmin, ymin, xmax, ymax);
        
    //making 1000 little line segments
    const double A = (xmax-xmin)/1000.0;
    
    //variables to loop x values
    double x;
    
    //Create curve
    for(x = xmin; x <= xmax; x += A)
    {
        //Constant exponent terms
        const double EXP_4 = 4;
        const double EXP_3 = 3;
        const double EXP_2 = 2;
        //getting f(x) for different values of x and x_2
        double x_2 = (x+A);
        double y = (coef_fourth*pow(x,EXP_4)) + (coef_third*pow(x,EXP_3)) + 
        (coef_second*pow(x,EXP_2)) + (coef_first*x) + constant;
        double y_2 = (coef_fourth*pow(x_2,EXP_4)) + 
        (coef_third*pow(x_2,EXP_3)) + (coef_second*pow(x_2,EXP_2)) + 
        (coef_first*(x_2)) + constant;
        
        //Lines with Point (x,f(x)) and ((x+d), f(x+d))
        Line curve = Line(Point(x,y), Point(x_2, y_2));
        
        //colored lines
        if(y_2 < y)
        {
            curve.set_color(RED);
        }
        else
        {
            curve.set_color(BLUE);
        }

        win << curve;
        win.output_buffer();
    }
    return 0;
}
