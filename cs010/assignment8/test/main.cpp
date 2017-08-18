// Course: CS 10 Fall 2011
//
// First Name: Anagaby
// Last Name: Toledo-Luna
// Login id: atole005
// email address: atole005@ucr.edu
//
// Lecture Section: 001
// Lab Section: 028
// TA: Adam Koehler
//
// Assignment: Assignment 8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include <iostream>
#include "instinct.h"

using namespace std;

//Quilt constants
const int QUILT_ROWS = 3;
const int QUILT_COLS = 5;
const int NUM_BLOCK_TYPES = 1;
const double BLOCK_SIZE = 1.25;

//Bullseye constants
const int NUM_CIRCLES = 4;
const double SMALL_RADIUS = BLOCK_SIZE / (2 * NUM_CIRCLES + 1);
const double DELTA_RADIUS = BLOCK_SIZE / (2 * NUM_CIRCLES + 1);

//Log Cabin constants
const int NUM_FRAMES = 4;
const double FRAME_WIDTH = BLOCK_SIZE / (2 * NUM_FRAMES + 1);

//Triangle constants
const int NUM_LAYERS = 4;

//Other constants
const int TWO = 2;

// helper for log cabin frame function
void helper(Point ll, double length)
{   
    //bottom frame
    Rect bottom_1 = Rect(ll, length - FRAME_WIDTH, FRAME_WIDTH);
    Rect bottom = Rect(ll, length - FRAME_WIDTH, FRAME_WIDTH, RED, true);
   
    //left frame
    ll.move(0, FRAME_WIDTH);
    Rect left_1 = Rect(ll, FRAME_WIDTH, length - FRAME_WIDTH);
    Rect left = Rect(ll, FRAME_WIDTH, length - FRAME_WIDTH, GREEN, true);
   
    // right frame
    ll.move(bottom.get_width(), - FRAME_WIDTH);
    Rect right_1 = Rect(ll, FRAME_WIDTH, length - FRAME_WIDTH);
    Rect right = Rect(ll, FRAME_WIDTH, length - FRAME_WIDTH, YELLOW, true);
   
    // top frame
    ll.move(TWO * FRAME_WIDTH - length, right.get_height());
    Rect top_1 = Rect(ll, length - FRAME_WIDTH, FRAME_WIDTH);
    Rect top = Rect(ll, length - FRAME_WIDTH, FRAME_WIDTH, BLUE, true);
   
    // output
    win << top_1 << right_1 << left_1 << bottom_1
        << top << right << left << bottom;
   
}

// output log cabin block
void log_cabin(Point ll, double size_2)
{
    helper(ll, size_2);
    double size_5;
    for (int i = TWO; i <= NUM_FRAMES + TWO; i= i + TWO)
    {
        ll.move(FRAME_WIDTH, FRAME_WIDTH);
        size_5 = size_2 - i* FRAME_WIDTH;
        helper(ll , size_5);
    }
}
   
// helper for first triangle layer
void tri_helper(Point p1, double tr_length)
{
    //lower left corner
    Point p2 = Point(p1.get_x(), p1.get_y() + tr_length / TWO);
    Point p3 = Point(p2.get_x() + tr_length / TWO, p1.get_y());
    Triangle br_1 = Triangle(p1, p2, p3);
    Triangle br = Triangle(p1, p2, p3, YELLOW, true);
       
    //upper left corner
    p1.move(0, tr_length / TWO);
    p2.move(0, tr_length / TWO);
    p3.move(0, tr_length);
    Triangle ul_1 = Triangle(p1, p2, p3);
    Triangle ul = Triangle(p1, p2, p3, RED, true);
   
    // upper right corner
    p1.move(tr_length, 0);
    p2.move(tr_length, 0);
    Triangle ur_1 = Triangle(p1, p2, p3);
    Triangle ur = Triangle(p1, p2, p3, GREEN, true);
   
    // lower right corner
    p2.move(0, -tr_length);
    p3.move(0, -tr_length);
    Triangle lr_1 = Triangle(p1, p2, p3);
    Triangle lr = Triangle(p1, p2, p3, BLUE, true);
   
    win << br_1 << ul_1 << ur_1 << lr_1
        << br << ul << ur << lr;
   
}

// corner triangle block
void corner_triangle(Point p1, double size_3, int num_layers)
{
    int k = TWO;
    double size_4;
    tri_helper(p1, size_3);
    for (int j = TWO; j <= num_layers; j = j + TWO)
    {
        p1.move(size_3 / (j * TWO), size_3 / (j * TWO));
        size_4 = size_3 / k;
        tri_helper(p1, size_4);
        k = k + TWO;
     }
}

// bullseye block
void bulls(Point center, double size_6, int num_circles)
{
    win << Rect(center, size_6, size_6);
    center.move(size_6 / TWO, size_6 / TWO);
    double sr = SMALL_RADIUS;
    for(int d = 1; d <= num_circles; d++)
    {
        win << Circle(center, sr, PURPLE);
        sr = sr + DELTA_RADIUS;
    }  
   
}

//hybrid block
void hybrid(Point hc, double size_7)
{
    helper(hc, size_7);
    hc.move(FRAME_WIDTH, FRAME_WIDTH);
    double size_8 = size_7 - TWO * FRAME_WIDTH;
    corner_triangle(hc, size_8, TWO);
}

// star block (mine)
void star(Point js, double size)
{
    Rect border2 = Rect(js, size, size, BLACK);
   
    Point ml = Point(js.get_x(), js.get_y() + .75 * size);
    Point lr = Point(js.get_x() + .75 * size, js.get_y());
    Line l1 = Line(ml, lr, YELLOW);
   
    Point bl = Point (js.get_x() + .25 * size, js.get_y());
    Point mr = Point(js.get_x() + size, js.get_y() + .75 * size);
    Line l2 = Line(bl, mr, YELLOW);
   
    Point tm = Point(js.get_x() + size / TWO, js.get_y() + size);
    Line l3 = Line(bl, tm, YELLOW);  
       
    Line l4 = Line(lr,tm, YELLOW);
        
    Line l5 = Line(ml, mr, YELLOW);
   
    win << l1 << l2 << l3 << l4 << l5 << border2 ;
}

// quilt blocks
void block(Point ll, double size, int block, int layers, int circles)
{
  if(block == 0)
  {
      log_cabin(ll, size);
  }
  else if(block == 1)
  {
      corner_triangle(ll, size, layers);
  }
  else if(block == 2)
  {
      bulls(ll, size, circles);
  }
  else if(block == 3)
  {
      hybrid(ll, size);
  }
  else
  {
      star(ll, size);
   }
}

int instinct_main()
{
    // set coord
    if(QUILT_ROWS > QUILT_COLS)
    {
        win.coord(0, 0, QUILT_ROWS * BLOCK_SIZE, QUILT_ROWS * BLOCK_SIZE );
    }
    else
    {
        win.coord(0, 0, QUILT_COLS * BLOCK_SIZE, QUILT_COLS * BLOCK_SIZE );
    }
   
    //QUILT
    int num_block = NUM_BLOCK_TYPES;
    Point ll;
      
    for(int l = 0; l <= QUILT_ROWS - 1; l++)
    {
        for(int m = 0; m <= QUILT_COLS - 1; m++)
        {
           ll = Point(m * BLOCK_SIZE, l * BLOCK_SIZE);
            block(ll, BLOCK_SIZE, num_block % NUM_BLOCK_TYPES,
                  NUM_LAYERS, NUM_CIRCLES);
            num_block++;
        }
        if(QUILT_ROWS % TWO != 0 && QUILT_COLS % TWO != 0)
        num_block--;
        if (QUILT_ROWS == QUILT_COLS)
        num_block--;
        if(QUILT_ROWS % TWO == 0 && QUILT_COLS % TWO == 0)
        num_block = num_block - 3;
        if(QUILT_ROWS % TWO != 0 && QUILT_COLS % TWO == 0)
        num_block = num_block - TWO;       
    }
   
   
   
    win.output_buffer();
   
   
    return 0;
}
