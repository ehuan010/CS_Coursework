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
#ifndef MESSAGE_H
#define MESSAGE_H

//Needed includes
#include <string>
#include <vector>

using namespace std;

//Message class with only function declarations
class Message
{
  protected:
  //Declaration of private member data
    string author;
    string subject;
    string body;
    unsigned id;
    vector<Message*> child_list;

  public:
  //Declaration of public member functions
    //default constructor
    Message();

    //Constructor with parameters
    Message(const string& athr, const string& sbjct, const string& body,
            unsigned id);
            
    //print the Topic in the required format - 
    //see output specs (different from previos assignment!!)
    virtual void print() const = 0; // NOTE NAME CHANGE from previous assignment!

    // returns true if the object is reply.
    virtual bool is_reply() const = 0;


    //returns the subject string.
    string get_subject() const;
    
    //returns the id
    unsigned get_id() const;
    
    //formats the output
    virtual string to_formatted_string() const = 0;
    
    
    //Destructor: Delete the objects, not their pointers
    virtual ~Message();
    
    
    // Adds a pointer to the child to child_list. 
    void add_child(Message* child);
    
    //displays the message in the given format. See output specs.
    //virtual void display() const;
};

//end inc guards
#endif
