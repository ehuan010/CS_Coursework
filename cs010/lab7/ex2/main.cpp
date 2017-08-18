/* Exercise 2 of Lab 7
 *
 * Name: Edward Huang
 * Lab Section: 23
 * Date: 11/8/11
 *
 * Implement a randomNumber function that returns a random integer between
 *   two supplied parameters that represent a minimum and maximum of a 
 *   range of integer numbers.
 *
 * Set up the coordinate grid according to the lab spec.
 *
 * Use randomNumber to generate circles in an instinct window. These circles 
 *   should have a random radius and occur at a random location. The number 
 *   of circles to generate is also random and the range is in lab spec.
 *
 * DO NOT declare any other variables than what is provided. Although you
 *   may not use all the provided variables, you will use all constants.
 */

#include <iostream>
#include <cstdlib>
#include "instinct.h"

using namespace std;

// TODO: implement the random_number function
int random_number(int A, int B)
{
    return A + rand() % (B - A + 1);
}
    

int instinct_main()
{
    // TODO: Window Coordinate Constants
    const int XMIN = 0;// TODO
    const int XMAX = 100;// TODO
    const int YMIN = 0;// TODO
    const int YMAX = 100;// TODO

    // TODO: Constants for Circles and Creation
    const int MIN_CIRCLES = 40; // TODO
    const int MAX_CIRCLES = 60;// TODO
    const int MIN_RADIUS = 1; // TODO
    const int MAX_RADIUS = 5; // TODO

    // Number of circles
    int circle_count;

    // Properties of the circles
    Circle c;
    int x, y;
    double radius;

    // Seed the random number generator
    srand(time(NULL));

    // TODO: Set the window coordinate grid using proper instinct function
    win.coord(XMIN, YMIN, XMAX, YMAX);


    // TODO: Set the random number of circles to generate
    circle_count = random_number(MIN_CIRCLES, MAX_CIRCLES);


    // TODO: create a number of circles equal to circle_count
    //         setting the location and radius to random integers
    //         in the range specified in spec by calling your function
    // HINT: use a loop
    //         and don't forget to add each circle to the window buffer
    for(int i=YMIN;i<=circle_count;i++)
    {
        x = random_number(XMIN, XMAX);
        y = random_number(YMIN, YMAX);
        radius = random_number(MIN_RADIUS, MAX_RADIUS);
        c = Circle(Point(x,y), radius);
        win << c;
    }



    // TODO: output all buffered graphics objects to the window
    win.output_buffer();

    return 0;
}
