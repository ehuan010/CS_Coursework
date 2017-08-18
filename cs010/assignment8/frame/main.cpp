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


void frame(Point& p, double& size)
{
  win << Rect(p, (size - FRAME_WIDTH), FRAME_WIDTH);
  p.move(0, FRAME_WIDTH);
  win << Rect(p, FRAME_WIDTH, (size - FRAME_WIDTH));
}

int instinct_main()
{
}
