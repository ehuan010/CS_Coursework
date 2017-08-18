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

//Start the inclusion Guard
#ifndef BBOARD_H
#define BBOARD_H

//Needed includes
#include <vector>
#include <string>
#include "user.h"
#include "message.h"
#include "topic.h"
#include "reply.h"

using namespace std;

////Bboard class with only function declarations
class Bboard
{
  private:
  //Declaration of private member data and functions
    string title;
    vector<User>user_list;
    User current_user;
    vector<Message*>message_list;
    void add_user(const string& name, const string& pass);
    bool user_exists(const string& name, const string& pass) const;
    void display() const;
    void add_topic();
    void add_reply();

  public:
  //Declaration of public member constructors and functions
    Bboard( );
    Bboard( const string &ttl);
    ~Bboard( );
    void setup( );
    void login( );
    void run( );
};

//End the inclusion guard
#endif
