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
// Assignment: Assignment 7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include <iostream>
#include "instinct.h"

using namespace std;

//CONSTANTS
//window coordinates
const int XMIN = 0;
const int XMAX = 400;
const int YMIN = 0;
const int YMAX = 400;

//size of image
const int IMAGESIZE = 100;

//reel images
const int REEL_MIN = 1;
const int REEL_MAX = 4;

//image location constants
const int LOWER_Y = 100;
const int MARGIN = 40;
const int GAP = 10;

//SENTINEL VALUE TO QUIT
const int SENTINEL = 0;

//location of messages displayed to the screen
const Point QUIT = Point(10, 340);
const Point BET_POINT = Point(10,325);
const Point MESS_CRED = Point(173,240);
const Point CRED_OUT = Point(190,220); 
const Point ERROR_POINT = Point(75,200);
const Point GAME_OVER = Point(173,220);
const Point WIN_POINT = Point(170,280);
const Point WIN_AMOUNT_POINT = Point(140, 260);

//min and max credits
const int MIN_CRED = 0;
const int MAX_CRED = 99;

//bet 1
const int BET_1 = 1;

//GAME OVER!
Message end_game = Message(GAME_OVER, "GAME OVER!", RED);

//winner
const int win_game = 5;


//function to generate a random integer within a range
int random_int(int low, int high)
{
  return low + rand() % (high - low + 1);
}



//function to check if a row of reel values is a win
bool winner(int reel1, int reel2, int reel3)
{
  if((reel1 == reel2) && (reel1 == reel3) && (reel2 == reel3))
  {
    return true;
  }
  else
  {
    return false;
  }
}



//function to match picture with a number
string int2pic(int a)
{
  int r1 = 1;
  int r2 = 2;
  int r3 = 3;
  if(a == r1)
  {
    return "./image0.jpg";
  }
  else if(a == r2)
  {
    return "./image1.jpg";
  }
  else if(a == r3)
  {
    return "./image2.jpg";
  }
  else
  {
    return "./image3.jpg";
  }
}
        

//function to construct a SINGLE reel image
Image slot(Point a, int b)
{
  string path = int2pic(b);
  return Image(a, IMAGESIZE, IMAGESIZE, path);
}

int instinct_main()
{
  //seeds the random value once
  srand(time(NULL));
    
  //set graphics window settings
  //win.set_window_size(XMAX, YMAX);
  win.coord(XMIN, YMIN, XMAX, YMAX);
  win.set_background_color(BLACK);
    
        
  //Start of program: Ask user to enter credits
  int credits;
  credits = win.get_int("Enter how many credits you want (1 - 99)", WHITE);
    
  
  //loop this while credits is not betwween 0 and 99
  while(credits < MIN_CRED || credits > MAX_CRED)
  {
    credits = win.get_int("Fail. Enter credits between(1 - 99)", RED);
  }
    
    
    //Options you can pick
    Message choice1 = Message(QUIT, "0 - quit", BLUE);
    Message choice2 = Message(BET_POINT, "1 - bet 1 credit", BLUE);
     
    //Display credits left
    Message credit_count, credits_left;
    credit_count = Message(MESS_CRED, "Credits", BLUE);
    credits_left = Message(CRED_OUT, credits, BLUE);
    
    //Winner display
    Message you_win = Message(WIN_POINT, "You win!", BLUE);
    Message win_amount;
    win_amount = Message(WIN_AMOUNT_POINT, "You win 5 credits!", BLUE);
    
    //Location of the slot images
    Point p1 = Point(MARGIN, LOWER_Y);
    Point p2 = Point(MARGIN + IMAGESIZE + GAP, LOWER_Y);
    Point p3 = Point(MARGIN + IMAGESIZE + GAP + IMAGESIZE + GAP, LOWER_Y);
    
    //random pictures
    int r1 = random_int(REEL_MIN, REEL_MAX);
    int r2 = random_int(REEL_MIN, REEL_MAX);
    int r3 = random_int(REEL_MIN, REEL_MAX);
    
    //output these things to the screen
    win << choice1
        << choice2
        << credit_count
        << credits_left
        << slot(p1, r1)
        << slot(p2, r2)
        << slot(p3, r3);
    win.output_buffer();
    
  
    
  //while loop: do this while there are credits
  while(credits > MIN_CRED)
  {
    //Enter choice
    int choice = win.get_int("Enter choice (0 or 1)", BLUE);
    if(choice == BET_1)
    {
      win.clear_buffer();
      r1 = random_int(REEL_MIN, REEL_MAX);
      r2 = random_int(REEL_MIN, REEL_MAX);
      r3 = random_int(REEL_MIN, REEL_MAX);
      if(winner(r1, r2, r3) == true)
      {
        
        credits += win_game;
        win << you_win
            << win_amount;
        win.output_buffer();
        
      }
      credits -= choice;
      credits_left = Message(CRED_OUT, credits, BLUE);
      win << choice1
          << choice2
          << credit_count
          << credits_left
          << slot(p1, r1)
          << slot(p2, r2)
          << slot(p3, r3);
      win.output_buffer();
    }
    else if(choice == SENTINEL)
    {
      credits = SENTINEL;
      win.clear_buffer();
    }
    else
    {
      win.clear_buffer();
      Message error = Message(ERROR_POINT, 
      "Please enter 0 or 1 as your choice!", RED);
      win << error;
      win.output_buffer();
      win.clear_buffer();
      wait_for(2000);
      win << choice1
          << choice2
          << credit_count
          << credits_left
          << slot(p1, r1)
          << slot(p2, r2)
          << slot(p3, r3);
      win.output_buffer();
    }
  }
  win.clear_buffer();
  win << end_game
      << slot(p1, r1)
      << slot(p2, r2)
      << slot(p3, r3);
  win.output_buffer();
  
  return 0;
}
