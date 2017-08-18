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
// Assignment: assn3
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

/* Constructor with three parameters
 * @param athr: Takes in string athr and assigns it to author
 * @param sbjct: Takes in string sbjct and assigns it to subject
 * @param body: Takes in string body and assigns it to body
 */
Message::Message(const string& athr, const string& sbjct, const string& body)
:author(athr),subject(sbjct),body(body)
{
}

//Member function that displays the subject author and body
void Message::display() const
{
  cout << subject << endl << "from " << author << ": "
       << body << endl;
}
