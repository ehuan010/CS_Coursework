//Needed includes
#include <iostream>
#include <vector>
#include <sstream>
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

//outputs stuff
void Message::print() const
{
  //should display children information
  cout << "Message #" << id << ": " << subject << endl << "from " << author 
       << ": " << body;
}

//Returns a the string of a subject
string Message::get_subject() const
{
  return subject;
}

string Message::to_formatted_string() const
{
  return "";
}

//Destructor
Message::~Message()
{
}


