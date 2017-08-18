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

//inclusion guards
#ifndef MESSAGE_H
#define MESSAGE_H

//Needed includes
#include <string>

using namespace std;

//Message class with only function declarations
class Message
{
  private:
  //Declaration of private member data
    string author;
    string subject;
    string body;

  public:
  //Declaration of public member functions
    //default constructor
    Message();

    //Constructor with parameters
    Message(const string& athr, const string& sbjct, const string& body);


    //displays the message in the given format. See output specs.
    void display() const;
};

//end inc guards
#endif
