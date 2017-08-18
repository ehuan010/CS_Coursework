//Needed includes
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
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
  cout << "Message #" << id << ": " << subject << endl << "from" << author 
       << ": " << body << endl;
}

//Returns a the string of a subject
string Message::get_subject() const
{
  return subject;
}

string Message::to_formatted_string(unsigned child1, unsigned child2) const
{
  fstream data;
  data.open("data0.txt");
  
  ostringstream text;
  text << "<begin message>" << endl;
  text << "     :id: " << id << endl;
  text << "     :subject: " << subject << endl;
  text << "     :from: " << author << endl;
  text << "     :children: " << child1 << " " << child2 << endl;
  text << "     :body: " << body << endl;
  text << "<end>" << endl;
  
  string output = text.str();
  cout << output;
  
  return "";
}

//Destructor
Message::~Message()
{
}


