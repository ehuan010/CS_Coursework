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
#ifndef REPLY_H
#define REPLY_H
//includes
#include "message.h"

class Reply: public Message
{
  private:
    unsigned parent_id;

  public:

    //default constructor
    Reply();

    /*  Constructor with parameters.
        similar to Message's constructor except:
        The subject should be initialized to "Re: <sbjct>" not <sbjct>.
        The parent_id should be initialized.
    */

    Reply(const string& athr, const string& sbjct, const string& body, 
          unsigned id, unsigned parent_id);

    //print the reply in the given format - see output specs for details
    virtual void print() const;

    virtual bool is_reply() const;
    
    //accessor for the topic's id     
    unsigned get_parent_id() const;
};

//end inc guards
#endif
