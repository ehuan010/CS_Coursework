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
// Assignment: Assignment 9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include "instinct.h"
using namespace std;

//General Screensaver constants
const int NUM_BLOCK_TYPES = 5;
const double BLOCK_SIZE = 1.0;
const int NUM_COLORS = 15;
const double WINDOW_SIZE = 10.0;
const int FRAME_PAUSE = 30;

//Bullseye constants
const int NUM_CIRCLES = 4;
const double SMALL_RADIUS = BLOCK_SIZE / (2 * NUM_CIRCLES + 1);
const double DELTA_RADIUS = BLOCK_SIZE / (2 * NUM_CIRCLES + 1);

//Log Cabin constants
const int NUM_FRAMES = 4;
const double FRAME_WIDTH = BLOCK_SIZE / (2 * NUM_FRAMES + 1);

//Triangle constants
const int NUM_LAYERS = 4;

//Blinking Quilt constants
const int QUILT_ROWS = 10;
const int QUILT_COLS = 10;

//Zooming Block constants
const double ZOOM_INCREMENT = WINDOW_SIZE / 100.0;

//Bouncing Block constants
const double DX_INIT = 0.05;
const double DY_INIT = 0.08;

//hybrid layers constant
const int HYBRID_LAYERS = 2;

//mydesign constant
const int NUM_SQUARES = 4;

//int2pic constants
const int cabins = 0;
const int triangles = 1;
const int bullseyes = 2;
const int hybrids = 3;

//options constants
const int OPT1 = 1;
const int OPT2 = 2;
const int OPT3 = 3;
const int OPT4 = 4;

//custom windows coordinates for options screen (XMIN, YMIN CAN BE REUSED)
const int XMIN = 0;
const int YMIN = 0;
const int XMAX = 10;
const int YMAX = 10;

//points for display of options in options menu
const Point P1 = Point(.25,8.7);
const Point P2 = Point(.25, 8.4);
const Point P3 = Point(.25, 8.1);

//get a random number
int rand_color_num(int a, int b)
{
  return a + rand() % (b - a + 1);
}

//function to create a random color
Color rand_color()
{
  int lower = 0;
  int upper = NUM_COLORS - 1;
  int white = static_cast<int>(WHITE);
  int rand_num = rand_color_num(lower, upper);
  while(rand_num == white)
  {
    rand_num = rand_color_num(lower, upper);
  }
  return static_cast<Color>(rand_num);
}

//random block for bouncing block
int random_block_num(int a, int b)
{
  return a + rand() % (b - a + 1);
}


//helper function for log cabin
void draw_frame(double x, double y, double size, Color c)
{
  //outline
  Rect left = Rect(Point(x, y+FRAME_WIDTH), FRAME_WIDTH, size-FRAME_WIDTH,c);
  Rect right = Rect(Point(x+size-FRAME_WIDTH, y), FRAME_WIDTH, 
  size-FRAME_WIDTH, c);
  Rect bot = Rect(Point(x, y), size-FRAME_WIDTH, FRAME_WIDTH, c);  
  Rect top = Rect(Point(x+FRAME_WIDTH, y + size-FRAME_WIDTH), 
  size-FRAME_WIDTH, FRAME_WIDTH, c);
  win << left << right << top << bot;
}

//makes log_cabin
void log_cabin(Point p, Color c)
{
  double x = p.get_x();
  double y = p.get_y();;
  double size = BLOCK_SIZE;
  for(int i = 1; i <= NUM_FRAMES; i++)
  {
    draw_frame(x, y, size, c);
    x += FRAME_WIDTH;
    y += FRAME_WIDTH;
    size = size - (2*FRAME_WIDTH);
  }
}

//helper function for bullseye
void bullseye_frame(double x, double y, double radius, Color a)
{
  //outline
  Rect frame = Rect(Point(x,y), BLOCK_SIZE, BLOCK_SIZE, a);
  Circle c = Circle(Point(x+(BLOCK_SIZE/2),y+(BLOCK_SIZE/2)), radius, a);
  win << frame << c;
}

//makes bullseye
void bullseye(Point p, Color a)
{
  double x = p.get_x();
  double y = p.get_y();
  double radius = SMALL_RADIUS;
  double radius_dx = DELTA_RADIUS;
  for(int i = 1; i <= NUM_CIRCLES; i++)
  {
    bullseye_frame(x, y, radius, a);
    radius = radius + radius_dx;
  }
}

//helper function for triangles
void triangle_frame(double x, double y, double size, Color c)
{
  //outline 
  Triangle bot_left = Triangle(Point(x,y), Point(x, y+(size/2)), 
                      Point(x+(size/2), y), c);
  Triangle top_left = Triangle(Point(x, y+(size/2)), 
                      Point(x+(size/2), y+size),
                      Point(x, y+size), c);
  Triangle bot_right = Triangle(Point(x+(size/2), y), 
                       Point(x+size, y+(size/2)),
                       Point(x+size, y), c);
  Triangle top_right = Triangle(Point(x+(size/2),y+size), 
                       Point(x+size,y+size),
                       Point(x+size, y+(size/2)), c);
  win << bot_left << top_right << top_left << bot_right;
}

//makes triangles
void triangle(Point p, int layers, double size, Color c)
{
  double x = p.get_x();
  double y = p.get_y();
  for(int i = 1; i <= layers; i++)
  {
    triangle_frame(x, y, size, c);
    x += size/4;
    y += size/4;
    size = size - (size/2);
  } 
}

//makes hybrid 
void hybrid(Point p, Color c)
{
  double x = p.get_x();
  double y = p.get_y();
  double size = BLOCK_SIZE;
  draw_frame(x, y, size, c);
  p.move(FRAME_WIDTH, FRAME_WIDTH);
  triangle(p, HYBRID_LAYERS, size-(2*FRAME_WIDTH), c);
}

//helper function for my own design
void mydesign(double x, double y, double size, Color c)
{  
  //outline
  Rect bot_left = Rect(Point(x,y), (size/2), (size/2), c);
  Rect top_left = Rect(Point(x, (y+(size/2))), (size/2), (size/2), c);
  Rect bot_right = Rect(Point((x+(size/2)), y), (size/2), (size/2), c);
  Rect top_right;
  top_right = Rect(Point((x+(size/2)), (y+(size/2))), (size/2), (size/2), c);
  win << bot_left << top_left << bot_right << top_right;
}

//makes squares
void square(Point p, Color c)
{
  double x = p.get_x();
  double y = p.get_y();
  double size = BLOCK_SIZE;
  for(int i = 1; i <= NUM_SQUARES; i++)
  {
    mydesign(x, y, size, c);
    x += size/4;
    y += size/4;
    size = size - (size/2);
  }
}

//outputs each picture block with color for blinking function
void int2pic(Point p, double size, int layers, int num, Color c)
{
  if(num == cabins)
  {
    c = rand_color();
    log_cabin(p, c);
  }
  else if(num == triangles)
  {
    c = rand_color();
    triangle(p, layers, size, c);
  }
  else if(num == bullseyes)
  {
    c = rand_color();
    bullseye(p, c);
  }
  else if(num == hybrids)
  {
    c = rand_color();
    hybrid(p, c);
  }
  else
  {
    c = rand_color();
    square(p, c);
  }
}

//non-colored int2pic's for bouncing option
void int2pic2(Point p, double size, int layers, int num, Color c)
{
  if(num == cabins)
  {
    log_cabin(p, c);
  }
  else if(num == triangles)
  {
    triangle(p, layers, size, c);
  }
  else if(num == bullseyes)
  {
    bullseye(p, c);
  }
  else if(num == hybrids)
  {
    hybrid(p, c);
  }
  else
  {
    square(p, c);
  }
}

//makes option screen
void options(int& screensaver)
{
  win.set_background_color(BLACK);
  //custom coordinates
  win.coord(XMIN, YMIN, XMAX, YMAX);
  //Options you can pick
  Message choice1 = Message(P1, "Enter 1 for Blinking Quilt",
  WHITE);
  Message choice2 = Message(P2, "Enter 2 for Bouncing Block",
  WHITE);
  Message choice3 = Message(P3, "Enter 4 to Quit", WHITE);
  win << choice1
      << choice2
      << choice3;
  win.output_buffer();;
  //ask to pick screensaver
  screensaver = win.get_int("Choose screensaver: ", WHITE);
  while(screensaver < OPT1 || screensaver > OPT4)
  {
    screensaver = win.get_int("Choose screensaver: ", WHITE);
  }
}

//makes blinking function
void blink(int screensaver)
{ 
  if(screensaver == OPT1)
  {
    win.clear_buffer();
    win.coord(XMIN, YMIN , WINDOW_SIZE, WINDOW_SIZE);
    win.set_background_color(WHITE);
    while(!win.left_mouse_down())
    {
      int block_types = NUM_BLOCK_TYPES;
      double size = BLOCK_SIZE;
      int layers = NUM_LAYERS;
      Color c;
      Point p;
      for(int i = 0; i < QUILT_ROWS; i++)
      {
        for(int j = 0; j < QUILT_COLS; j++)
        {
          int num = block_types%NUM_BLOCK_TYPES;
          p = Point(j*size, i*size);
          int2pic(p, size, layers, num, c);
          block_types++;
        }
        block_types = i + 1;
      }
      win.output_buffer();
      wait_for(FRAME_PAUSE);
      win.clear_buffer();
    }
  }
}

//makes bouncing block
void bouncing_block(int screensaver)
{
  double x_move = DX_INIT;
  double y_move = DY_INIT;
  int rand_low = 0; //lower interval for random colors
  if(screensaver == OPT2)
  {
    win.clear_buffer();
    win.coord(XMIN, YMIN, WINDOW_SIZE, WINDOW_SIZE);
    win.set_background_color(BLACK);
    int block_types = random_block_num(rand_low, NUM_BLOCK_TYPES);;
    double size = BLOCK_SIZE;
    int layers = NUM_LAYERS;
    Color c = rand_color();
    Point p;
    p = Point(WINDOW_SIZE/2 - BLOCK_SIZE/2 , WINDOW_SIZE/2 - BLOCK_SIZE/2);
    while(!win.left_mouse_down())
    {
      int num = block_types%NUM_BLOCK_TYPES;
      Rect r = Rect(p, BLOCK_SIZE, BLOCK_SIZE, 
      WHITE, true);
      win << r;
      int2pic2(p, size, layers, num, c);
      win.output_buffer();
      wait_for(FRAME_PAUSE);
      win.clear_buffer();
      p.move(x_move,y_move);
      //hits left and right edge
      if(p.get_x() + BLOCK_SIZE >= WINDOW_SIZE || 
      p.get_x()  <= XMIN)
      {
        x_move = -x_move;
        block_types += random_block_num(rand_low, NUM_BLOCK_TYPES);
        c = rand_color();
      }
      //hits top and bottom
      if(p.get_y() + BLOCK_SIZE >= WINDOW_SIZE ||
      p.get_y() <= YMIN)
      {
        y_move = -y_move;
        block_types += random_block_num(rand_low, NUM_BLOCK_TYPES);
        c = rand_color();
      }
    }
    win.clear_buffer();
  }
}

//makes the program quit by clearing buffer
void quit(int screensaver)
{
  if(screensaver == OPT4)
  {
    win.clear_buffer();
  }
}

int instinct_main()
{
  //seeds the random value once
  srand(time(NULL));
  
  //outputs every single option while screensaver is not 4(quit)
  int screensaver;
  do
  {
    options(screensaver);
    blink(screensaver);
    bouncing_block(screensaver);
    quit(screensaver);
  }while(screensaver != OPT4);
  win.set_background_color(BLACK);
}
