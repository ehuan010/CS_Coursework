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

  public:
    vector<unsigned>child_list;

  public:
  //Declaration of public member functions
    //default constructor
    Message();

    //Constructor with parameters
    Message(const string& athr, const string& sbjct, const string& body,
            unsigned id);
            
    //print the Topic in the required format - 
    //see output specs (different from previos assignment!!)
    virtual void print() const; // NOTE NAME CHANGE from previous assignment!

    // returns true if the object is reply.
    //virtual bool is_reply() const = 0;


    //returns the subject string.
    string get_subject() const;
    
    virtual string to_formatted_string() const;
    
    virtual ~Message();

    //displays the message in the given format. See output specs.
    //virtual void display() const;
};

//end inc guards
#endif
