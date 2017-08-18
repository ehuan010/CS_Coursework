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
// Assignment: Assignment 4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include "instinct.h"

int instinct_main()
{
     //favorite modern family character votes
     double phil;
     double gloria;
     double alex;
     double luke;
     double other;
     
     //max bar length
     const double MAX_BAR_LENGTH = 7.5;
     
     //ask for votes and get the total
     phil = win.get_double("Votes for Phil");
     gloria = win.get_double("Votes for Gloria");
     alex = win.get_double("Votes for Alex");
     luke = win.get_double("Votes for Luke");
     other = win.get_double("Votes for Other");
     double total_votes = phil + gloria + alex + luke + other;
     
     //percentage of votes
     double votes_phil = phil/total_votes;
     double votes_gloria = gloria/total_votes;
     double votes_alex = alex/total_votes;
     double votes_luke = luke/total_votes;
     double votes_other = other/total_votes;
     
     
     //percents as a ratio of the MAX bar length(vote % * MAX)
     double phil_w = votes_phil * MAX_BAR_LENGTH;
     double gloria_w = votes_gloria * MAX_BAR_LENGTH;
     double alex_w = votes_alex * MAX_BAR_LENGTH;
     double luke_w = votes_luke * MAX_BAR_LENGTH;
     double other_w = votes_other * MAX_BAR_LENGTH;
          
     //height constant
     double height = 4 * LETTER_HEIGHT;
     double n_height = 1.5 * LETTER_HEIGHT;
     
     //make rectangles for their percents
     Rect phil_bar = Rect(Point(1,9), phil_w, height, BLUE, true);
     Rect gloria_bar = Rect(Point(1,8), gloria_w, height, RED, true);
     Rect alex_bar = Rect(Point(1,7), alex_w, height, ORANGE, true);
     Rect luke_bar = Rect(Point(1,6), luke_w, height, GREEN, true);
     Rect other_bar = Rect(Point(1,5), other_w, height, BLACK, true);
     
     //Messages for names: declare variable then initialize it
     Message phil_m;
     Message glor_m;
     Message alex_m;
     Message luke_m;
     Message other_m;
     phil_m = Message(Point(1+phil_w+LETTER_WIDTH, 9+n_height), "Phil");
     glor_m = Message(Point(1+gloria_w+LETTER_WIDTH, 8+n_height), "Gloria");
     alex_m = Message(Point(1+alex_w+LETTER_WIDTH, 7+n_height), "Alex");
     luke_m = Message(Point(1+luke_w+LETTER_WIDTH, 6+n_height), "Luke");
     other_m = Message(Point(1+other_w+LETTER_WIDTH, 5+n_height), "Other");
     
     win << phil_bar 
         << gloria_bar
         << alex_bar
         << luke_bar
         << other_bar
         << phil_m
         << glor_m
         << alex_m
         << luke_m
         << other_m;
     win.output_buffer();
     
     return(0);
}
     
