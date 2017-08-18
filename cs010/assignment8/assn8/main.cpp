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
// Assignment: Assignment 8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include "instinct.h"
using namespace std;

//Quilt constants
const int QUILT_ROWS = 5;
const int QUILT_COLS = 7;
const int NUM_BLOCK_TYPES = 5;
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

//hybrid layers
const int HYBRID_LAYERS = 2;

//mydesign constants
const int NUM_SQUARES = 4;


//int2pic
const int cabins = 0;
const int triangles = 1;
const int bullseyes = 2;
const int hybrids = 3;


//helper function for log cabin
void draw_frame(double x, double y, double size)
{
  //color
  Rect left1 = Rect(Point(x, y+FRAME_WIDTH), FRAME_WIDTH, size-FRAME_WIDTH,
  GREEN, true);
  Rect right1 = Rect(Point(x+size-FRAME_WIDTH, y), FRAME_WIDTH, 
  size-FRAME_WIDTH, YELLOW, true);
  Rect bot1 = Rect(Point(x, y), size-FRAME_WIDTH, FRAME_WIDTH, RED, true);  
  Rect top1 = Rect(Point(x+FRAME_WIDTH, y + size-FRAME_WIDTH), 
  size-FRAME_WIDTH, FRAME_WIDTH, BLUE, true);
  win << left1 << right1 << top1 << bot1;
  
  //outline
  Rect left = Rect(Point(x, y+FRAME_WIDTH), FRAME_WIDTH, size-FRAME_WIDTH);
  Rect right = Rect(Point(x+size-FRAME_WIDTH, y), FRAME_WIDTH, 
  size-FRAME_WIDTH);
  Rect bot = Rect(Point(x, y), size-FRAME_WIDTH, FRAME_WIDTH);  
  Rect top = Rect(Point(x+FRAME_WIDTH, y + size-FRAME_WIDTH), 
  size-FRAME_WIDTH, FRAME_WIDTH);
  win << left << right << top << bot;
}

//makes log_cabin
void log_cabin(Point p)
{
  double x = p.get_x();
  double y = p.get_y();;
  double size = BLOCK_SIZE;
  for(int i = 1; i <= NUM_FRAMES; i++)
  {
    draw_frame(x, y, size);
    x += FRAME_WIDTH;
    y += FRAME_WIDTH;
    size = size - (2*FRAME_WIDTH);
  }
}

//helper function for bullseye
void bullseye_frame(double x, double y, double radius)
{
  //color + outline
  Rect frame = Rect(Point(x,y), BLOCK_SIZE, BLOCK_SIZE);
  Circle c = Circle(Point(x+(BLOCK_SIZE/2),y+(BLOCK_SIZE/2)), radius, BLUE);
  win << frame << c;
}

//makes bullseye
void bullseye(Point p)
{
  double x = p.get_x();
  double y = p.get_y();
  double radius = SMALL_RADIUS;
  double radius_dx = DELTA_RADIUS;
  for(int i = 1; i <= NUM_CIRCLES; i++)
  {
    bullseye_frame(x, y, radius);
    radius = radius + radius_dx;
  }
}

//helper function for triangles
void triangle_frame(double x, double y, double size)
{
  //color
  Triangle bot_left1 = Triangle(Point(x,y), Point(x, y+(size/2)), 
                      Point(x+(size/2), y), YELLOW, true);
  Triangle top_left1 = Triangle(Point(x, y+(size/2)), 
                      Point(x+(size/2), y+size),
                      Point(x, y+size), RED, true);
  Triangle bot_right1 = Triangle(Point(x+(size/2), y), 
                       Point(x+size, y+(size/2)),
                       Point(x+size, y), BLUE, true);
  Triangle top_right1 = Triangle(Point(x+(size/2),y+size), 
                       Point(x+size,y+size),
                       Point(x+size, y+(size/2)),GREEN, true);
  win << bot_left1 << top_right1 << top_left1 << bot_right1;
  
  //outline 
  Triangle bot_left = Triangle(Point(x,y), Point(x, y+(size/2)), 
                      Point(x+(size/2), y));
  Triangle top_left = Triangle(Point(x, y+(size/2)), 
                      Point(x+(size/2), y+size),
                      Point(x, y+size));
  Triangle bot_right = Triangle(Point(x+(size/2), y), 
                       Point(x+size, y+(size/2)),
                       Point(x+size, y));
  Triangle top_right = Triangle(Point(x+(size/2),y+size), 
                       Point(x+size,y+size),
                       Point(x+size, y+(size/2)));
  win << bot_left << top_right << top_left << bot_right;
}

//makes triangles
void triangle(Point p, int layers, double size)
{
  double x = p.get_x();
  double y = p.get_y();
  for(int i = 1; i <= layers; i++)
  {
    triangle_frame(x, y, size);
    x += size/4;
    y += size/4;
    size = size - (size/2);
  } 
}

//makes hybrid 
void hybrid(Point p)
{
  double x = p.get_x();
  double y = p.get_y();
  double size = BLOCK_SIZE;
  draw_frame(x, y, size);
  p.move(FRAME_WIDTH, FRAME_WIDTH);
  triangle(p, HYBRID_LAYERS, size-(2*FRAME_WIDTH));
}

//helper function for my own design
void mydesign(double x, double y, double size)
{
  //color
  Rect bot_left1 = Rect(Point(x,y), (size/2), (size/2), BLUE, true);
  Rect top_left1;
  top_left1 = Rect(Point(x, (y+(size/2))), (size/2), (size/2), RED, true);
  Rect bot_right1 = Rect(Point((x+(size/2)), y), (size/2), (size/2), 
  GREEN, true);
  Rect top_right1 = Rect(Point((x+(size/2)), (y+(size/2))), (size/2),
  (size/2), YELLOW, true);
  win << bot_left1 << top_left1 << bot_right1 << top_right1;
  
  //outline
  Rect bot_left = Rect(Point(x,y), (size/2), (size/2));
  Rect top_left = Rect(Point(x, (y+(size/2))), (size/2), (size/2));
  Rect bot_right = Rect(Point((x+(size/2)), y), (size/2), (size/2));
  Rect top_right;
  top_right = Rect(Point((x+(size/2)), (y+(size/2))), (size/2), (size/2));
  win << bot_left << top_left << bot_right << top_right;
}

//makes squares
void square(Point p)
{
  double x = p.get_x();
  double y = p.get_y();
  double size = BLOCK_SIZE;
  for(int i = 1; i <= NUM_SQUARES; i++)
  {
    mydesign(x, y, size);
    x += size/4;
    y += size/4;
    size = size - (size/2);
  }
}

//makes the pictures display based on their number
void int2pic(Point p, double size, int layers, int num)
{
  if(num == cabins)
  {
    log_cabin(p);
  }
  else if(num == triangles)
  {
    triangle(p, layers, size);
  }
  else if(num == bullseyes)
  {
    bullseye(p);
  }
  else if(num == hybrids)
  {
    hybrid(p);
  }
  else
  {
    square(p);
  }
}
  

int instinct_main()
{
  //windows coordinates
  if(QUILT_COLS > QUILT_ROWS)
  {
    win.coord(0, 0, QUILT_COLS * BLOCK_SIZE, 10);
  }    
  else if( QUILT_ROWS > QUILT_COLS)
  {
    win.coord(0 ,0, 10, QUILT_ROWS * BLOCK_SIZE);
  }
  
  //quilt and ouputs
  int block_types = NUM_BLOCK_TYPES;
  double size = BLOCK_SIZE;
  int layers = NUM_LAYERS;
  Point p;
  for(int i = 0; i < QUILT_ROWS; i++)
  {
    for(int j = 0; j < QUILT_COLS; j++)
    {
      int num = block_types%NUM_BLOCK_TYPES;
      p = Point(j*size, i*size);
      int2pic(p, size, layers, num);
      block_types++;
    }
    block_types = i + 1;
  }
  win.output_buffer();
}
