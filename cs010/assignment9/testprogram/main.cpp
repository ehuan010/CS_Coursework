#include <iostream>
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

//Other constants
const int TWO = 2;

// generate random color
Color rad_color(int max, int min)
{
    int cl = min + rand() % (max - min + 1);
    int no = static_cast<int>(WHITE);    
    while(cl == no)
    {
        cl = min + rand() % (max - min + 1);
    }
    Color rc = static_cast<Color>(cl);
    return rc;
} 

// helper for log cabin frame function 
void helper(Point ll, double length, Color c)
{    
    //bottom frame
    Rect bottom = Rect(ll, length - FRAME_WIDTH, FRAME_WIDTH, c);
    
    //left frame
    ll.move(0, FRAME_WIDTH); 
    Rect left = Rect(ll, FRAME_WIDTH, length - FRAME_WIDTH, c);
    
    // right frame
    ll.move(bottom.get_width(), - FRAME_WIDTH);
    Rect right = Rect(ll, FRAME_WIDTH, length - FRAME_WIDTH, c);
    
    // top frame 
    ll.move(TWO * FRAME_WIDTH - length, right.get_height());
    Rect top = Rect(ll, length - FRAME_WIDTH, FRAME_WIDTH, c);
    
    // output
    win << top << right << left << bottom;
    
}

// output log cabin block
void log_cabin(Point ll, double size_2, Color c)
{
    helper(ll, size_2, c);
    double size_5;
    for (int i = TWO; i <= NUM_FRAMES + TWO; i= i + TWO)
    {
        ll.move(FRAME_WIDTH, FRAME_WIDTH);
        size_5 = size_2 - i* FRAME_WIDTH;
        helper(ll , size_5, c);
    } 
}
    
// helper for first triangle layer
void tri_helper(Point p1, double tr_length, Color c)
{
    //lower left corner
    Point p2 = Point(p1.get_x(), p1.get_y() + tr_length / TWO); 
    Point p3 = Point(p2.get_x() + tr_length / TWO, p1.get_y()); 
    Triangle br = Triangle(p1, p2, p3, c); 
        
    //upper left corner
    p1.move(0, tr_length / TWO);
    p2.move(0, tr_length / TWO);
    p3.move(0, tr_length);
    Triangle ul = Triangle(p1, p2, p3, c); 
    
    // upper right corner
    p1.move(tr_length, 0);
    p2.move(tr_length, 0);
    Triangle ur = Triangle(p1, p2, p3, c);
    
    // lower right corner
    p2.move(0, -tr_length);
    p3.move(0, -tr_length);
    Triangle lr = Triangle(p1, p2, p3, c);
    
    win << br << ul << ur << lr;
    
}

// corner triangle block
void corner_triangle(Point p1, double size_3, int num_layers, Color c)
{
    int k = TWO;
    double size_4;
    tri_helper(p1, size_3, c);
    for (int j = TWO; j <= num_layers; j = j + TWO)
    {
        p1.move(size_3 / (j * TWO), size_3 / (j * TWO));
        size_4 = size_3 / k;
        tri_helper(p1, size_4, c);
        k = k + TWO;
     }
}

// bullseye block
void bulls(Point center, double size_6, int num_circles, Color c)
{
    win << Rect(center, size_6, size_6, c);
    center.move(size_6 / TWO, size_6 / TWO);
    double sr = SMALL_RADIUS;
    for(int d = 1; d <= num_circles; d++)
    {
        win << Circle(center, sr, c); 
        sr = sr + DELTA_RADIUS;
    }   
    
}

//hybrid block
void hybrid(Point hc, double size_7, Color c)
{
    helper(hc, size_7, c);
    hc.move(FRAME_WIDTH, FRAME_WIDTH);
    double size_8 = size_7 - TWO * FRAME_WIDTH;
    corner_triangle(hc, size_8, TWO, c);
}

// star block (mine)
void star(Point js, double size, Color c)
{
    Rect border2 = Rect(js, size, size, c);
    
    Point ml = Point(js.get_x(), js.get_y() + .75 * size);
    Point lr = Point(js.get_x() + .75 * size, js.get_y());
    Line l1 = Line(ml, lr, c);
    
    Point bl = Point (js.get_x() + .25 * size, js.get_y()); 
    Point mr = Point(js.get_x() + size, js.get_y() + .75 * size);
    Line l2 = Line(bl, mr, c);
    
    Point tm = Point(js.get_x() + size / TWO, js.get_y() + size);
    Line l3 = Line(bl, tm, c);   
        
    Line l4 = Line(lr, tm, c);
         
    Line l5 = Line(ml, mr, c);
    
    win << l1 << l2 << l3 << l4 << l5 << border2 ;
}

// changing color quilt blocks
void c_block(Point ll, double size, int block, int layers, int circles, Color c)
{
  if(block == 0)
  {
      c = rad_color(NUM_COLORS, 0);
      log_cabin(ll, size, c);
  }
  else if(block == 1)
  {
      c = rad_color(NUM_COLORS, 0);
      corner_triangle(ll, size, layers, c); 
  }
  else if(block == 2)
  {
      c = rad_color(NUM_COLORS, 0);
      bulls(ll, size, circles, c);
  } 
  else if(block == 3)
  { 
      c = rad_color(NUM_COLORS, 0);
      hybrid(ll, size, c);
  }
  else
  {
      c = rad_color(NUM_COLORS, 0);
      star(ll, size, c);
   }
}

// same color quilt blocks
void s_block(Point ll, double size, int block, int layers, int circles, Color c)
{
    if(block == 0)
    {
        log_cabin(ll, size, c);
    }
    else if(block == 1)
    {
        corner_triangle(ll, size, layers, c); 
    }
    else if(block == 2)
    {
        bulls(ll, size, circles, c);
    }     
    else if(block == 3)
    { 
        hybrid(ll, size, c);
    }
    else
    {
        star(ll, size, c);
    }
}

// wind coord
void coord(double x, double y, double size)
{
    if(y > x)
    {
        win.coord(0, 0, y * size, y * size );
    }
    else
    {
        win.coord(0, 0, x * size, x * size );
    }
}

// quilt output
void quilt(Point ll, int num_block, int rows, int cols, double bs, Color c)
{
    for(int l = 0; l <= rows - 1; l++)
    {
        for(int m = 0; m <= cols - 1; m++)
        {
            ll = Point(m * bs, l * bs);
            c_block(ll, bs, num_block % NUM_BLOCK_TYPES,
                  NUM_LAYERS, NUM_CIRCLES, c);
            num_block++;
        }
        if(rows % TWO != 0 && cols % TWO != 0)
        num_block--;
        if (rows == cols)
        num_block--;
        if(rows % TWO == 0 && cols % TWO == 0)
        num_block = num_block - 3;
        if(rows % TWO != 0 && cols % TWO == 0)
        num_block = num_block - TWO;        
    }
}
// bouncing block
void bounce()
{
    Point ll = Point (5,5);
    Color c = rad_color(NUM_COLORS, 0);
        
    int num_block = NUM_BLOCK_TYPES;
    double bs = BLOCK_SIZE;
    Rect back =  Rect(ll, bs, bs, WHITE, true);

    double x = DX_INIT;
    double y = DY_INIT;
    
    do
    {
        win << back;        
        s_block(ll, bs, num_block % NUM_BLOCK_TYPES,
                  NUM_LAYERS, NUM_CIRCLES, c);
        win.output_buffer(); 
        wait_for(FRAME_PAUSE);
        
        ll.move(x,y);
        back.move(x,y);
        
        if(ll.get_y() + BLOCK_SIZE >= 10 || 
           back.get_lower_left().get_y() + BLOCK_SIZE >=10)
        {
            y = -y;
            num_block++;
            c = rad_color(NUM_COLORS, 0);
        }
        if(ll.get_x() + BLOCK_SIZE >= 10 || 
           back.get_lower_left().get_x() + BLOCK_SIZE >=10)
        {
            x = -x;
            num_block++;
            c = rad_color(NUM_COLORS, 0);
        }
        if(ll.get_x() <= 0 ||
           back.get_lower_left().get_x() <=0)
        {
            x = -x;
            num_block++;
            c = rad_color(NUM_COLORS, 0);
        }
        if(ll.get_y() <= 0 || 
           back.get_lower_left().get_y() <=0)
        {
            y = -y;
            num_block++;
            c = rad_color(NUM_COLORS, 0);
        }         
       
        win.clear_buffer();
        win << back;
        s_block(ll, bs, num_block % NUM_BLOCK_TYPES,
                  NUM_LAYERS, NUM_CIRCLES, c);
        win.output_buffer(); 

    }while(win.left_mouse_down() != true); 
    win.clear_buffer();
}

// blinking quilt
void b_quilt()
{
    win.set_background_color(WHITE);
    Point ll;
    Color c;
    do
    {
        quilt(ll, NUM_BLOCK_TYPES, QUILT_ROWS, QUILT_COLS, 
              BLOCK_SIZE, c);
        win.output_buffer();
        wait_for(FRAME_PAUSE);
        win.clear_buffer();
        quilt(ll, NUM_BLOCK_TYPES, QUILT_ROWS, QUILT_COLS, 
              BLOCK_SIZE, c);
        win.output_buffer();
    }while(win.left_mouse_down() != true);
    win.clear_buffer();
    win.set_background_color(BLACK);
}
void choices(int opt)
{
    if(opt == 1)
    {
        // Blinking quilt
        b_quilt();
    }
    if(opt == 2)
    {
        // Bouncing Block
        bounce();
    }
}
        
int instinct_main()
{
    //seeds the random value once
    srand(time(NULL));

    // set coord
    coord(QUILT_COLS, QUILT_ROWS, BLOCK_SIZE);
    
    // background color
    win.set_background_color(BLACK);
    
     // program
    int option;
    do
    {        
        option = win.get_int("Choose Screensaver:\n\n\n\n"
                             " Enter 1 for Blinking Quilt \n"
                             " Enter 2 for Bouncing Block \n"
                             " Enter 3 to Quit", WHITE);
        choices(option);        
    }while(option != 3);
    
    // output buffer
    win.output_buffer();
    
    return 0;
}
