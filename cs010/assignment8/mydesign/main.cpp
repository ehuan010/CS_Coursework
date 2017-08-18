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

//mydesign constants
const int NUM_SQUARES = 4;


//MAKES MY OWN DESIGN FRAMES
void mydesign(double& x, double& y, double& size)
{
  Rect bot_left = Rect(Point(x,y), (size/2), (size/2));
  Rect top_left = Rect(Point(x, (y+(size/2))), (size/2), (size/2));
  Rect bot_right = Rect(Point((x+(size/2)), y), (size/2), (size/2));
  Rect top_right = Rect(Point((x+(size/2)), (y+(size/2))), (size/2), (size/2));
  win << bot_left << top_left << bot_right << top_right;
}

void baller()
{
  double x = 0.0;
  double y = 0.0;
  double size = BLOCK_SIZE;
  for(int i = 1; i <= NUM_SQUARES; i++)
  {
    mydesign(x, y, size);
    x += size/4;
    y += size/4;
    size = size - (size/2);
  }
}

int instinct_main()
{
  baller();
  win.output_buffer();
}
