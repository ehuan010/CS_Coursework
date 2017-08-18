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
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "topic.h"
#include "reply.h"

using namespace std;

//default constructor
Topic::Topic()
{
  author = "";
  subject = "";
  body = "";
  id = 0;
}

//Constructor with parameters
Topic::Topic(const string& athr, const string& sbjct, const string& body, 
             unsigned id)
{
  author = athr;
  subject = sbjct;
  this->body = body;
  this->id = id;
}

//print the reply in the given format. See output specs. 
//Similar to previous assignment, but you now have to include the 
//id in the output.
void Topic::print() const
{
  cout << "-------------------------------------------------" << endl;
  cout << "Message #" << id << ":" << subject << endl << "from " << author 
       << ":" << body;
  for(unsigned i = 0; i < child_list.size(); i++)
  {
    dynamic_cast<Reply*>(child_list[i])->print_subtree(1);
  }
}

/* this writes the contents of the Topic to a string in the following format:
  <begin_topic>
  :id: 4
  :subject: single line
  :from: author
  :children: 5 6 [this line should not be printed if there are no children.]
  :body: multiple lines - line 1
  line 2
  line 3
  <end>
 * line starting with :children: has the id's of all children (See file specs. for details)
 */
string Topic::to_formatted_string() const
{
  //fstream data("data1.txt");
  ostringstream content;
  
  content << "<begin_topic>" << endl;
  content << ":id: " << id << endl;
  content << ":subject:" << subject << endl;
  content << ":from: " << author << endl;
  if(!child_list.empty())
  {
    content << ":children: ";
    for(unsigned i = 0; i < child_list.size(); i++)
    {
      content << child_list[i]->get_id() << " ";
    }
    content << endl;
  }
  content << ":body:" << body;
  content << "<end>" << endl;
  
  string output = content.str();
  
  return output;
}

//Topic is not a reply so returns bool value false
bool Topic::is_reply() const
{
  return false;
}
