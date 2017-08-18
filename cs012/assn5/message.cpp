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
#include "message.h"

using namespace std;

//Public Member function implementation

//Default constructor with empty strings
Message::Message()
:author(""),subject(""),body("")
{
}

//Constructor with four parameters
Message::Message(const string& athr, const string& sbjct, const string& body,
                 unsigned id)
:author(athr),subject(sbjct),body(body),id(id)
{
}

//Returns a the string of a subject
string Message::get_subject() const
{
  return subject;
}

//Destructor
Message::~Message()
{
}


