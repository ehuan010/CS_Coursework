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

//Needed includes
#include <iostream>
#include <cstdlib>
#include "bboard.h"
#include "reply.h"

using namespace std;

//Private member functions

/* Helper function that adds a user to the user list via push back
 * @param name: Takes in a string name 
 * @param pass: Takes in a string pass
 */
void Bboard::add_user(const string& name, const string& pass)
{
  User user_pass(name,pass); //use name and pass to create a User type
  user_list.push_back(user_pass); //push back user_pass into user_list
}

/* Helper function that checks whether or not a user exists in user_list
 * @param name: Takes in a string name
 * @param pass: Takes in a string pass
 * @return: Returns true if user exists otherwise return false
 */
bool Bboard::user_exists(const string& name, const string& pass) const
{
  for(unsigned int i = 0; i < user_list.size(); i++)
  {
    //Goes through user_list and compares it with the param name and pass
    if(user_list[i].check(name,pass)) 
    {                              
      return true;
    }
  }
  return false;
}


//Helper function that displays the Messages stored in message_list
void Bboard::display() const
{
  cout << endl;
  //loops to print out everything in message_list
  for(unsigned int i = 0; i < message_list.size(); i++)
  {
    //Can't write reply if there is no message so first object stored 
    //should be a Topic. Invokes is_reply from Topic which returns false
    //so !false is true
    if(!message_list[i]->is_reply())
    {
      message_list[i]->print(); //output the Topics
      
      //loops to check for the Replys to print out
      for(unsigned j = 0; j < message_list.size(); j++)
      {
        //If it's a Topic it will invoke is_reply and return false, but if it
        //is a Reply it will invoke is_reply and return true.
        if(message_list[j]->is_reply())
        {
          if(dynamic_cast<Reply*>(message_list[j])->get_parent_id() == (i+1))
          {
            cout << endl;
            message_list[j]->print(); //output the Replys
          }
        }
      }
    }
  }
  cout << "-------------------------------------------------" << endl;
}

//Helper function that adds a topic to the message_list
void Bboard::add_topic()
{
  string remainder;       //  Used
  getline(cin, remainder); // to get remainder of what is stored in buffer
  
  cout << "\nEnter Subject: ";
  string sbjct;
  getline(cin, sbjct); //gets whole input of sbjct
  cout << "Enter Body: "; 
  string bdy;
  getline(cin, bdy); //gets whole input of bdy
  cout << "Message Recorded!" << endl;
  
  //The message number is the index + 1
  unsigned message_num = message_list.size() + 1;
  //dynamically allocate memory for a Topic
  Topic* new_topic = new Topic(current_user.get_username(), sbjct, bdy, 
                               message_num);
  //push it back into message list
  message_list.push_back(new_topic); 
}


//Helper function that adds a reply to the message_list
void Bboard::add_reply()
{
  //The message number is the index + 1
  unsigned message_num = message_list.size() + 1;
  //Create variable to take in input
  int parent_id;
  
  while(parent_id == 0 || (unsigned)parent_id > message_list.size()
        || message_list[parent_id-1]->is_reply())
  {
    //take in input
    cout << "\nEnter Topic ID (-1 for Menu): ";
    cin >> parent_id;
    
    //goes back to the menu (Order matters here. Double if)
    if(parent_id == -1)
    {
      return;
    }
    //invalid if it meets these conditions
    if(parent_id == 0 || (unsigned)parent_id > message_list.size() 
       || message_list[parent_id-1]->is_reply())
    {
      cout << "Invalid Topic ID!!\n";
    }
    
  }
  
  //clear the buffer
  string remainder;
  getline(cin, remainder);
  
  //get the original subject from message_list
  string sbjct = message_list[parent_id - 1]->get_subject();
  //prompt to cin body of reply
  cout << "Enter Body: ";
  string body;
  getline(cin, body);
  //dynamically allocate memory for a new reply
  Reply* new_reply = new Reply(current_user.get_username(), sbjct, body,
                               message_num, parent_id);
  //push it back into message list
  message_list.push_back(new_reply);
  cout << "Message Recorded!" << endl;
}
//end of Private members

//---------------------------------------------------------------------------

//Public member functions

//Default constructor
Bboard::Bboard( )
:title("Title not set"),user_list(),current_user(),message_list()
{
}

/* Constructor with one parameter
 * @param ttl: Takes in a string for the title
 */
Bboard::Bboard( const string &ttl)
:title(ttl),user_list(),current_user(),message_list()
{
}

//Destructor: Deallocates all Messages pointed to by message_list
Bboard::~Bboard( )
{
  for(unsigned i = 0; i < message_list.size(); i++)
  {
    delete message_list[i];
  }
}

//Member function that creates a list of usernames and their respective
//passwords
void Bboard::setup( )
{
  string username;
  string password;
  //reads in from file and terminates when username is terminated by "end" 
  while(username != "end")  
  {
      cin >> username; 
      if(username != "end")
      {
        cin >> password;
        add_user(username,password);
      }
  }
}

//member function that prompts the user to login to bboard
void Bboard::login( ) 
{
  cout << endl;
  cout << title << endl; //outputs the title that is set in the main function
  cout << "Enter your username (\"Q\" or \"q\" to quit): ";
  string user;
  cin >> user;
  if(user == "Q" || user == "q") //if the username is Q/q the program quits
  {
    cout << "Bye!" << endl;
    exit(0); //terminates program
  }
  else
  {
    cout << "Enter your password: ";
    string pass;
    cin >> pass;
    if(user_exists(user,pass)) //checks if the user/pass match in user_list
    {
      current_user = User(user,pass); //set the current user
      cout << endl;
      cout << "Welcome back " << current_user.get_username() << "!" << endl;
    }
    else
    {
      while(user_exists(user,pass) == false) //if user does not exist
      {
        cout << "Invalid Username or Password!\n" << endl;
        cout << "Enter your username (\"Q\" or \"q\" to quit): ";
        cin >> user;
        if(user == "Q" || user == "q")
        {
          cout << "Bye!" << endl;
          exit(0);
        }
        else
        {
          cout << "Enter your password: ";
          cin >> pass;
        }
      }
      current_user = User(user,pass);
      cout << endl;
      cout << "Welcome back " << current_user.get_username() << "!" << endl;
    }
  }
}

//Member function that is the main loop of bboard
void Bboard::run( ) 
{
  login();
  string action; //declaration of action
  do
  {
    cout << endl;
    cout << "Menu" << endl << "  - Display Messages ('D' or 'd')" << endl
         << "  - Add New Topic ('N' or 'n')" << endl
         << "  - Add Reply to a Topic ('R' or 'r')" << endl
         << "  - Quit ('Q' or 'q')" << endl
         << "Choose an action: ";
    cin >> action;
    //while action doesn't match an option ask user to choose again
    while(action != "d" && action != "D" && action != "N" && action != "n"
          && action != "Q" && action != "q" && action != "R" 
          && action != "r") 
    {                                           
      cout << "Choose an action: ";
      cin >> action;
    }
    if(action == "d" || action == "D") //if action is d/D
    {
      if(!message_list.empty()) //if it is not empty
      {
        display(); //display the messages
      }
      else //if it is empty
      {
        cout << "\nNothing to Display.\n" << endl; //display this
      }
    }
    else if(action == "N" || action == "n") //if action is N/n
    {
      add_topic(); //adds a topic to message_list
    }
    else if(action == "R" || action == "r") //if action is R/r
    {
      add_reply(); //adds a reply to message_list
    }
    else //if action is not d/D or n/N then
    {
      cout << "Bye!" << endl;
      exit(0);
    }
  }while(action != "Q" || action != "q");
}
