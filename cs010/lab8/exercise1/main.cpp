#include <iostream>
#include "instinct.h"
using namespace std;

//Lab 8 constants
const double BLOCK_SIZE = 1.25;   
const int NUM_FRAMES = 4;
const double FRAME_WIDTH = BLOCK_SIZE / (2 * NUM_FRAMES + 1);


void draw_frame(double x, double y, double size)
{
  Rect left = Rect(Point(x, y+FRAME_WIDTH), FRAME_WIDTH, size-FRAME_WIDTH);
  Rect right = Rect(Point(x+size-FRAME_WIDTH, y), FRAME_WIDTH, 
  size-FRAME_WIDTH);
  Rect bot = Rect(Point(x, y), size-FRAME_WIDTH, FRAME_WIDTH);  
  Rect top = Rect(Point(x+FRAME_WIDTH, y + size-FRAME_WIDTH), 
  size-FRAME_WIDTH, FRAME_WIDTH);
  win << left << right << top << bot;
  win.output_buffer();
}

int instinct_main()
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
  return 0;
}
