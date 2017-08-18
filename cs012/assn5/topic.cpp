// Course: CS 12 Winter 2012
//
// First Name: Edward
// Last Name: Huang
// Course username: ehuan010
// email address: ehuan010@student.ucr.edu
//
// Lecture Section: 002
// Lab Section: 022
// TA: Wojchiek Karas
//
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

//Needed includes
#include <iostream>
#include <cstdlib>
#include "topic.h"

using namespace std;

//default constructor
Topic::Topic()
{
  author = "";
  subject = "";
  body = "";
  id = 0;
}

//Constructor with parameters
Topic::Topic(const string& athr, const string& sbjct, const string& body, 
             unsigned id)
{
  author = athr;
  subject = sbjct;
  this->body = body;
  this->id = id;
}

//print the reply in the given format. See output specs. 
//Similar to previous assignment, but you now have to include the 
//id in the output.
void Topic::print() const
{
  cout << "-------------------------------------------------" << endl;
  cout << "Message #" << id << ": " << subject << endl << "from " << author 
       << ": " << body << endl;
}

//Topic is not a reply so returns bool value false
bool Topic::is_reply() const
{
  return false;
}
