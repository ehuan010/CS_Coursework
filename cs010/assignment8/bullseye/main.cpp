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
const int NUM_LAYERS = 2;

//MAKES BULLSEYE FRAME
void bullseye(double x, double y, double radius)
{
  Rect frame = Rect(Point(x,y), BLOCK_SIZE, BLOCK_SIZE);
  Circle c = Circle(Point(x+(BLOCK_SIZE/2),y+(BLOCK_SIZE/2)), radius);
  win << frame << c;
  win.output_buffer();
}

int instinct_main()
{
  double x = 0.0;
  double y = 0.0;
  double radius = SMALL_RADIUS;
  double radius_dx = DELTA_RADIUS;
  for(int i = 1; i <= NUM_CIRCLES; i++)
  {
    bullseye(x, y, radius);
    radius = radius + radius_dx;
  }
}
