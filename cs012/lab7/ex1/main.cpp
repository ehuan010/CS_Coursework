#include <iostream>
#include <fstream>
#include "message.h"
using namespace std;

bool load_message(const string& filename)
{
  fstream text;
  text.open(filename.c_str());
  
  unsigned id;
  string temp;
  string subject;
  string author;
  string child1;
  string child2;
  string body;
  string end;
  
  text >> temp >> temp >> id;
  text >> temp;
  getline(text,subject);
  text >> temp >> author;
  text >> temp >> child1 >> child2;
  text >> temp;
  
  while(!text.eof())
  {
    getline(text,end);
    if(end != "<end>")
    {
      body += end;
      body += "\n";
    }
  }
  Message m = Message(author,subject,body,id);
  m.print();
  return true;
}

int main()
{
  load_message("data0.txt");
  return 0;
}
