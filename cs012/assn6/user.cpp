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

//Needed includes
#include <iostream>
#include "user.h"

using namespace std;

//Public Member function implementation

//Default constructor with empty strings
User::User()
:username(""),password("")
{
}

/* Constructor with two parameters
 * @param uname: Takes in a string and assigns it to username
 * @param pass: Takes in a string and assigns it to password;
 */
User::User(const string& uname, const string& pass)
:username(uname),password(pass)
{
}

//Member function that returns the string username
string User::get_username() const
{
  return username;
}

/* Member function that checks if a user exists or not
 * @param uname: Takes in a string uname and compares it to username
 * @param pass: Takes in a string pass and compares it to password
 * @return: Returns true of everything matches, otherwise returns false
 */
bool User::check(const string& uname, const string& pass) const
{
  if(username == uname && password == pass)
  {
    return true; 
  }
  else if(username == "")
  {
    return false;
  }
  else
  {
    return false;
  }
}
