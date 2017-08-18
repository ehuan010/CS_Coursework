#include <iostream>
#include <vector>

using namespace std;

int largest_element(vector<int> v)
{
  if(v.empty())
  {
    return 0;
  }
  if(v.size() == 1)
  {
    return v[0];
  }
  
  if(v[v.size()-2] <= v[v.size()-1])
  {
    v[v.size()-2] = v[v.size()-1];
    v.pop_back();
    return largest_element(v);
  }
  else
  {
    v.pop_back();
    return largest_element(v);
  }
}

int main()
{
  vector<int>v;
  v.push_back(7);
  v.push_back(6);
  v.push_back(2);
  v.push_back(9);
  v.push_back(0);
  v.push_back(17);
  v.push_back(4);
  int test = largest_element(v);
  cout << test << endl;
  return 0;
}
