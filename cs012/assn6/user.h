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

//inclusion guards
#ifndef USER_H
#define USER_H
//includes
#include <string>

using namespace std;

//User class with only function declarations
class User
{
  
  private:
  //Declaration of private member data
    string username;
    string password;
    
  public:
  //Declaration of public member functions
  
    //creates a user with empty name and password.
    User();

    // creates a user with given username and password.
    User(const string& uname, const string& pass);


    //returns the username
    string get_username() const;

    // returns true if the stored username/password matches with the 
    //parameters.
    // Otherwise returns false.
    // Note that, even though a User with emptyl name and password is 
    //actually a valid User object
    // (it is the default User), this function must still return false if 
    //given a empty uname string.
    bool check(const string& uname, const string& pass) const;

    // sets a new password. This function will not be used in the current 
    //assignment.
    void set_password(const string& newpass);
};

//end inc guards
#endif
