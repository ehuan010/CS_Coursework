#include <iostream>
#include <fstream>
#include "message.h"
using namespace std;

bool save_message(const string& filename, Message* m, unsigned child1, 
                  unsigned child2)
{
  fstream text;
  text.open(filename.c_str());
  string info = m->to_formatted_string(child1, child2);
  text << info;
  return true;
}
  

int main()
{
  fstream text;
  text.open("data0.txt");
  
  unsigned id = 3;
  string subject = "This is the subject";
  string author = "messi";
  unsigned child1 = 5;
  unsigned child2 = 6;
  string body = "the body had two lines this is the first line. \n"
                "and this is the second line.";
  Message* m = new Message(author,subject,body,id);
  save_message("data0.txt",m,child1,child2);

  return 0;
}
