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
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "reply.h"

using namespace std;

//Default Constructor
Reply::Reply()
{
  author = "";
  subject = "";
  body = "";
  id = 0;
}

//Constructor with four parameters
Reply::Reply(const string& athr, const string& sbjct, const string& body, 
             unsigned id)
{
  author = athr;
  subject = sbjct;
  this->body = body;
  this->id = id;
}

//Prints the Replys
//void Reply::print() const
//{
  //cout << "Message #" << id << ": "<< subject << endl 
       //<< "from " << author << ": " << body << endl;
//}

//print the reply in the given format - see output specs for details
/* This function is responsible for printing the Reply and all of its subtree recursively
 * After printing the Reply with the given indentation and format (see output details).
 * it calls the print_subtree function of all of the Replies in its child_list(see message)
 * with incremented indentation value. 
 *
 * Note: Each indentation value represent 2 spaces. e.g. if indentation=1 the reply should be indented
 * 2 spaces, if it's 2, indent by 4 spaces. 
 */ 
 
/* print the reply to screen in the given format - see output specs for details
 * Then it invokes print_subtree(n) on each of the messages in child_list 
 * (we leave it to you to figure out what n is!)
 */
void Reply::print() const
{
  //cout << "  Message #" << id << ": "<< subject << endl 
       //<< "  from " << author << ": " << body << endl;
  
  //unsigned n = 1;
  //for(unsigned i = 0; i < child_list.size(); i++)
  //{
    //dynamic_cast<Reply*>(child_list[i])->print_subtree(n);
  //}
}

/* This function is responsible for printing the selected Reply and all of its subtree recursively
 * After printing the Reply with the given indentation and format (see output details).
 * it calls the print_subtree function of all of the Replies in its child_list(see message)
 * with incremented indentation value. 
 *
 * Note: Each indentation value represent 2 spaces. e.g. if indentation=1 the reply should be indented
 * 2 spaces, if it's 2, indent by 4 spaces. 
 */       
void Reply::print_subtree(unsigned indentation) const
{
    unsigned indent = indentation * 2;
    string spacing;
    string bdy;
    istringstream ibody(body);
    
    for(unsigned int i= 0; i < indent; ++i)
    {
        spacing += " ";
    }
    cout << endl << spacing << "Message #" << id << ":" << subject << endl;
    cout << spacing << "from " << author << ":";
   
    getline(ibody,bdy);
    cout << bdy << endl;
    while(getline(ibody,bdy))
    {
        bdy = spacing + bdy;
        cout << bdy << endl;
    }
   
    for(unsigned int i = 0; i < child_list.size() ; ++i)
    {
        dynamic_cast<Reply*>(child_list[i]) -> print_subtree(indentation +1);
    }
}


//Reply is a reply so it returns bool value true 
bool Reply::is_reply() const
{
  return true;
}

//Formats the output to text file
string Reply::to_formatted_string() const
{
  ostringstream content;
  
  content << "<begin_reply>" << endl;
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



