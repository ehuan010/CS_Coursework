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
#include "reply.h"

using namespace std;

//Default Constructor
Reply::Reply()
{
  author = "";
  subject = "";
  body = "";
  id = 0;
  parent_id = 0; 
}

//Constructor with four parameters
Reply::Reply(const string& athr, const string& sbjct, const string& body, 
             unsigned id, unsigned parent_id)
{
  author = athr;
  subject = "Re: " + sbjct;
  this->body = body;
  this->id = id;
  this->parent_id = parent_id;
}

//Prints the Replys
void Reply::print() const
{
  cout << "     Message #" << id << ": "<< subject << endl 
       << "     from " << author << ": " << body << endl;
}

//Reply is a reply so it returns bool value true 
bool Reply::is_reply() const
{
  return true;
}

//Accessor that returns the parent_id
unsigned Reply::get_parent_id() const
{
  return parent_id;
}
