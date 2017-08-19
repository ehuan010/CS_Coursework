#include <iostream>
#include <vector>

using namespace std;

//A.

//Works Assuming all inputs are in the set of Natural numbers
//and that there is a subset of a whose product is s
vector<int> subsetExists(int a[], int n, int s)
{
  vector<int> finalv;
  //IMPORTANT!!!: NEED A Case for when s = 0 and/or n = 0,1
  if(n == 0 || n == 1)
  {
    cout << "The array is empty" << endl;
    finalv.push_back(-1);
    return finalv;
  }
  if(s == 0 && n >= 2)
  {
    for(int b = 0; b < n; b++)
    {
      if(a[b] == 0 && b == 0)
      {
        finalv.push_back(0);
        finalv.push_back(a[b+1]);
        return finalv;
      }
      if(a[b] == 0 && b > 0)
      {
        finalv.push_back(0);
        finalv.push_back(a[b-1]);
        return finalv;
      }
    }
  }
  
  //FIND ALL FACTORS OF S first
  int remainder;
  int factor;
  int divisor;
  vector<int> v; //this holds all factors of s
  for(divisor = s; divisor > 0; divisor--)
  {
    remainder = s%divisor;
    if(remainder == 0)
    {
      factor = divisor;
      v.push_back(factor); 
    }
  }
  
  int element;
  vector<int> v2; //resulting vector after comparing v and a
  for(int i = 0; i < v.size(); i++)
  {
    element = v[i];
    for(int j = 0; j < n; j++)
    {
      if(element == a[j])
      {
        v2.push_back(a[j]);
      }
    }
  }
  
  //print vector 2;
  for(int c = 0; c < v2.size(); c++)
  {
    cout << v2[c] << " ";
  }
  cout << endl;
  
  //special case for when only 1 factor is found and stored in v2
  if(v2.size() == 1)
  {
    cout << "No subset exists" << endl;
    finalv.push_back(-1);
    return finalv;
  }
  
  //finds a subset that multiplies to s
  int newS = s;
  finalv.clear();
  for(int o = 0; o < v2.size(); o++)
  {
    for(int p = o; p < v2.size(); p++)
    {
      if(newS == v2[p] && v2[v2.size()-1] == 1)
      {
        finalv.push_back(v2[p]);
        finalv.push_back(v2[v2.size()-1]);
        return finalv;
      }
      if(newS == v2[p] && v2[v2.size()-1] != 1)
      {
        finalv.clear(); //clear the vector
        newS = s; //reassign newS to s
      }
      else if(newS % v2[p] == 0) //check if it divides
      {
        newS = newS/v2[p]; //now get the new number
        finalv.push_back(v2[p]);
        for(int q = p; q < v2.size(); q++) //start at where p is
        {
          if(newS == v2[q]) //if it finds a match in v2
          {
            finalv.push_back(v2[q]);
            return finalv;
          }
        } 
      }
    }
    if(newS != 1)
    {
      finalv.clear(); //clear the vector
      newS = s; //reassign newS to s
    }
  }
  
  if(!finalv.empty())
  {
    return finalv;
  }
  else
  {
    cout << "No subset exists" << endl;
    finalv.push_back(-1);
    return finalv;
  }
}

int main()
{
  int size = 10;
  int a[size];
  a[0] = 2;
  a[1] = 3;
  a[2] = 4;
  a[3] = 120;
  a[4] = 11;
  a[5] = 9;
  a[6] = 6;
  a[7] = 3;
  a[8] = 0;
  a[9] = 2;
  int product = 9;
  vector<int> subset = subsetExists(a, size, product);
  for(int i = 0; i < subset.size(); i++)
  {
    cout << subset[i] << " ";
  }
  cout << endl;
  return 0;
}

//B. This program executes at an asymptotic complexity of O(n^3)
