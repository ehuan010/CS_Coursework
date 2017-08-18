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
// Assignment: assn6
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
    User get_user(const string& name) const; // NO CHANGE
    void display() const; //MAJOR CHANGE
    void add_topic(); //SLIGHTLY CHANGED
    void add_reply(); //MAJOR CHANGE

  public:
  //Declaration of public member constructors and functions
    Bboard( );
    Bboard( const string &ttl);
    ~Bboard( );
    // GONE void setup( );
    bool load_users(const string& userfile); //NEW
    bool load_messages(const string& datafile); // NEW
    bool save_messages(const string& datafile); //NEW
    void login( );
    void run( );
};

//End the inclusion guard
#endif
