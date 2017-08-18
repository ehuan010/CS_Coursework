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

//inclusion guards
#ifndef TOPIC_H
#define TOPIC_H
//includes
#include "message.h"

class Topic: public Message
{                            // no new member variables
  public:

    //default constructor
    Topic();

    //Constructor with parameters
    Topic(const string& athr, const string& sbjct, const string& body, 
          unsigned id);

    //print the reply in the given format. See output specs. 
    //Similar to previous assignment, but you now have to include the 
    //id in the output.
    virtual void print() const;

    virtual bool is_reply() const;
};

//end inc guards
#endif
