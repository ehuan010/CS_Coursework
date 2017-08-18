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
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

//Needed includes
#include <iostream>
#include <cstdlib>
#include "bboard.h"

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
  int msg_num = 1; //counter to keep track of how many msgs there are
  for(unsigned int i = 0; i < message_list.size(); i++)
  {
    cout << "-------------------------------------------------" << endl;
    cout << "Message #" << msg_num << ": ";
    message_list[i].display();
    msg_num++; //increments the counter by one for every new msg
  }
  cout << "-------------------------------------------------" << endl
       << endl;
}

//Helper function that adds a message to the message_list
void Bboard::add_message()
{
  string remainder;       //  Used
  getline(cin, remainder); // to get remainder of what is stored in buffer
  cout << "\nEnter Subject: ";
  string sbjct;
  getline(cin, sbjct); //gets whole input of sbjct
  cout << "Enter Body: "; 
  string bdy;
  getline(cin, bdy); //gets whole input of bdy
  cout << "Message Recorded!" << endl << endl; 
  //Create a variable called add of type Message that will be pushed back
  //into the message_list
  Message add(current_user.get_username(), sbjct, bdy);
  message_list.push_back(add);
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
      cout << "Welcome back " << current_user.get_username() << "!" << endl 
           << endl;
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
      cout << "Welcome back " << current_user.get_username() << "!" << endl
           << endl;
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
    cout << "Menu" << endl << "   - Display Messages ('D' or 'd')" << endl
         << "   - Add New Message ('N' or 'n')" << endl
         << "   - Quit ('Q' or 'q')" << endl
         << "Choose an action: ";
    cin >> action;
    //while action doesn't match an option ask user to choose again
    while(action != "d" && action != "D" && action != "N" && action != "n"
          && action != "Q" && action != "q") 
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
      add_message(); //adds a message to message_list
    }
    else //if action is not d/D or n/N then
    {
      cout << "Bye!" << endl;
      exit(0);
    }
  }while(action != "Q" || action != "q");
}
