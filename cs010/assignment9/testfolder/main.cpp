//make option screen
void options()
{
  //Options you can pick
  Message choice1 = Message(Point(.25,8.7), "Enter 1 for Blinking Quilt",
  WHITE);
  Message choice2 = Message(Point(.25,8.4), "Enter 2 for Bouncing Block",
  WHITE);
  win << choice1
      << choice2;
  win.output_buffer();
  int screensaver;
  //ask to pick screensaver
  screensaver = win.get_int("Choose screensaver: ", WHITE);
  while(screensaver < 1 || screensaver > 4)
  {
    screensaver = win.get_int("Choose screensaver: ", WHITE);
  }
  if(screensaver == 1)
  {
    win.clear_buffer();
    //win.set_background_color(WHITE);
    while(!win.left_mouse_down())
    //{
    int block_types = NUM_BLOCK_TYPES;
    double size = BLOCK_SIZE;
    int layers = NUM_LAYERS;
    Color c = rand_color(1);
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
    //}
  }
}
