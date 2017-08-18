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
#include <fstream>
#include <sstream>
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

//This function gets the user
User Bboard::get_user(const string& name) const
{
  for(unsigned i = 0; i < user_list.size(); i++)
  {
    if(user_list[i].get_username() == name)
    {
      return user_list[i];
    }
  }
  return User();
}


//Helper function that displays the Messages stored in message_list
void Bboard::display() const
{
  cout << endl;
  for(unsigned i = 0; i < message_list.size(); i++)
  {
    if(!message_list[i]->is_reply())
    {
      message_list[i]->print();
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
  string whole_sbjct = " " + sbjct;
  cout << "Enter Body: "; 
  string temp;
  getline(cin, temp); //gets whole input of bdy
  string bdy;
  while(!temp.empty())
  {
    bdy += temp + "\n";
    getline(cin, temp);
  }
  string whole_bdy = " " + bdy;
  //The message number is the index + 1
  unsigned message_num = message_list.size() + 1;
  
  if(message_list.empty())
  {
    //dynamically allocate memory for a Topic
    Topic* new_topic = new Topic(current_user.get_username(), whole_sbjct,
                                 whole_bdy,1);
    //push it back into message list
    message_list.push_back(new_topic);
  }
  else
  {
    //dynamically allocate memory for a Topic
    Topic* new_topic1 = new Topic(current_user.get_username(), whole_sbjct, 
                                  whole_bdy, message_num);
    //push it back into message list
    message_list.push_back(new_topic1);
  }
  cout << "Message Recorded!" << endl; //another endl?
}


//Helper function that adds a reply to the message_list
void Bboard::add_reply()
{
  //Create variable to take in input
  int parent_id;
  
  while(parent_id == 0 || (unsigned)parent_id > message_list.size() )
        || cin.fail())
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
       || cin.fail())
    {
      cout << "Invalid Topic ID!!\n";
      while(cin.fail())
      {
        cin.clear();
        cin.ignore();
      }
    }
  }
  
  //prompt to cin body of reply
  cout << "Enter Body: ";
  cin.ignore();
  string temp;
  string body;
  getline(cin, temp);
  while(!temp.empty())
  {
    body += temp + "\n";
    getline(cin, temp);
  }
  string body1 = " " + body;
  //get the original subject from message_list
  string sbjct = " Re:" + message_list[parent_id - 1]->get_subject();
  
  //The message number is the index + 1
  unsigned message_num = message_list.size() + 1;
  
  //dynamically allocate memory for a new reply
  Reply* new_reply = new Reply(current_user.get_username(), sbjct, body1,
                               message_num);
  //push it back into message list
  message_list.push_back(new_reply);
  cout << "Message Recorded!" << endl;
  unsigned reply_id = new_reply->get_id();
  message_list[parent_id-1]->add_child(message_list[reply_id-1]);
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

/* Member function that loads users
 * @param userfile: Reads users text from a file
 */
bool Bboard::load_users(const string& userfile)
{
  //open file
  ifstream user_file(userfile.c_str());
  string username;
  string password;
  //reads in from file and terminates when username is terminated by "end" 
  if(user_file.fail())
  {
    return false;
  }
  //continue to get username and password until string "end" is reached
  while(username != "end")
  {
    user_file >> username; 
    if(username != "end")
    {
      user_file >> password;
      add_user(username,password);
    }
  }
  //close file
  user_file.close();
  return true;
}

/* Member function that loads messages
 * @param datafile: Reads data from a file
 */
bool Bboard::load_messages(const string& datafile)
{
  //open file
  ifstream data_file(datafile.c_str());
  //declare needed variables
  string author;
  string subject;
  string header;
  string junk;
  unsigned id, msgs, child;
  vector<string>v_child;
  //make sure that datafile is not in a fail state
  if(data_file.fail())
  {
    return false;
  }
  else //otherwise
  {
    //read in from datafile # of msgs
    data_file >> msgs;
    //loop until #of msgs is reached
    for(unsigned i = 0; i < msgs; i++)
    {
      string body;
      string children;
      //read in from datafile line by line according to datafile format
      data_file >> header >> junk >> id >> junk;
      getline(data_file,subject);
      data_file >> junk >> author >> junk;
      //if :children: exists then do this
      if(junk == ":children:")
      {
        getline(data_file,children);
        v_child.push_back(children);
        data_file >> junk;
        //if there is a :body: do this
        if(junk == ":body:")
        {
          string temp;
          getline(data_file,temp);
          //while it is not <end> then continue reading in the body
          while(temp != "<end>")
          {
            body += temp + "\n";
            getline(data_file,temp);
          }
        }
      }
      else //otherwise
      {
        v_child.push_back("");
        string temp;
        getline(data_file,temp);
        //while it is not <end> then continue reading in the body
        while(temp != "<end>")
        {
          body += temp + "\n";
          getline(data_file,temp);
        }
      }
      //if the header is <begin_topic> then do this
      if(header == "<begin_topic>")
      {
        Topic* new_topic = new Topic(author,subject,body,id);
        message_list.push_back(new_topic);
      }
      //or if the header is <begin_reply> then do this
      if(header == "<begin_reply>")
      {
        Reply* new_reply = new Reply(author,subject,body,id);
        message_list.push_back(new_reply);
      }
    }
    //close the file
    data_file.close();
    //push back everything into a temporary vector
    for(unsigned i = 0; i < v_child.size(); i++)
    {
      istringstream ichild(v_child[i]);
      while(ichild >> child)
      {
        message_list[i]->add_child(message_list[child - 1]);
      }
    }
    return true;
  }
}

/* Member function that saves messages
 * @param userfile: Reads everything into datafile
 */
bool Bboard::save_messages(const string& datafile)
{
  //open
  ofstream data_file(datafile.c_str());
  //if it is in a fail state
  if(data_file.fail())
  {
    return false;
  }
  else //otherwise
  {
    //save all the messages
    data_file << message_list.size() << endl;
    for(unsigned i = 0; i < message_list.size(); i++)
    {
      data_file << message_list[i]->to_formatted_string();
    }
    //close
    data_file.close();
    return true;
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
        cout << "\nNothing to Display.\n"; // << endl; //display this
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
      //save_messages("data1.txt");
      cout << "Bye!" << endl;
      return;
    }
  }while(action != "Q" || action != "q");
}
