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

//MAKES LOG_CABINS
void draw_frame(double x, double y, double size)
{
  Rect left = Rect(Point(x, y+FRAME_WIDTH), FRAME_WIDTH, size-FRAME_WIDTH);
  Rect right = Rect(Point(x+size-FRAME_WIDTH, y), FRAME_WIDTH, 
  size-FRAME_WIDTH);
  Rect bot = Rect(Point(x, y), size-FRAME_WIDTH, FRAME_WIDTH);  
  Rect top = Rect(Point(x+FRAME_WIDTH, y + size-FRAME_WIDTH), 
  size-FRAME_WIDTH, FRAME_WIDTH);
  win << left << right << top << bot;
}

void log_cabin()
{
  double x = 0;
  double y = 0;
  double size = BLOCK_SIZE;
  for(int i = 1; i <= NUM_FRAMES; i++)
  {
    draw_frame(x, y, size);
    x += FRAME_WIDTH;
    y += FRAME_WIDTH;
    size = size - (2*FRAME_WIDTH);
  }
}

void draw_triangle(double& x, double& y, double& size)
{
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

void triangle_frame()
{
  double x = FRAME_WIDTH;
  double y = FRAME_WIDTH;
  double size = BLOCK_SIZE;
  size = size-(2*FRAME_WIDTH);
  for(int i = 1; i <= 2; i++)
  {
    draw_triangle(x, y, size);
    x += size/4;
    y += size/4;
    size = size - (size/2);
  } 
}

void hybrid()
{
  double x = 0.0;
  double y = 0.0;
  double size = BLOCK_SIZE;
  draw_frame(x, y,size);
  triangle_frame();
}

void bitch(int a)
{
  if( a == 1)
  {
    triangle_frame();
  }
  else if(a == 2)
  {
    hybrid();
  }
}

int instinct_main()
{
  bitch(2);
  win.output_buffer();
}


