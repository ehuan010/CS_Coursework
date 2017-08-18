#include "instinct.h"
#include <vector>



void points(vector<Point>&v)
{
  for(int i = 0; i < v.size(); i++)
  {
    v[i] = win.get_click("Click anywhere on the screen");
    double x = v[i].get_x();
    double y = v[i].get_y();
    Message m = Message(Point(x+.1, y-.3), i);
    win << v[i] << m;
    win.output_buffer();
  }
}

void connect(const vector<Point>&v, vector<Line>&lines)
{
  string s;
  do
  {
    int a = win.get_int("Pick a dot");
    int b = win.get_int("Pick another dot");
    win.clear_buffer();
    Line l = Line(v[a],v[b]);
    lines.push_back(l);
    for(int i = 0; i < v.size(); i++)
    {
      double x = v[i].get_x();
      double y = v[i].get_y();
      Message m = Message(Point(x+.1, y-.3), i);
      win << v[i] << m;
    }
    for(int j = 0; j < lines.size(); j++)
    {
      win << lines[j];
    }
    win.output_buffer();
    s = win.get_string("Draw more lines? (yes/no)");
  }while(s == "yes");
}

int instinct_main()
{
  vector<Point>v(10);
  vector<Line>lines;
  points(v);
  connect(v, lines);
}
