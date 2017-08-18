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

//MAKES TRIANGLE FRAME
void triangle_frame(double& x, double& y, double& size)
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

void triangle()
{
  double x = 0.0;
  double y = 0.0;
  double size = BLOCK_SIZE;
  for(int i = 1; i <= NUM_LAYERS; i++)
  {
    triangle_frame(x, y, size);
    x += size/4;
    y += size/4;
    size = size - (size/2);
  } 
}

int instinct_main()
{
  triangle();
  win.output_buffer();
}
