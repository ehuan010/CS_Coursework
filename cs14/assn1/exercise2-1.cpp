#include <iostream>
#include <vector>

using namespace std;

//vector<int> subset

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
      v.push_back(factor); //might be able to take out a variable
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
        /**
        for(int k = 0; k < v2.size() - 1; k++)
        {
          if(v2[k] == a[j])
          {
            v2.pop_back(); //removes the recently added element(repeats)
          }
        }
        */
      }
    }
  }
  
  //print vector 2;
  for(int c = 0; c < v2.size(); c++)
  {
    cout << v2[c] << " ";
  }
  cout << endl;
  
  //THIS ONLY WORKS IF I WANT TO GET 2 integers that multiply to product
  //what to do for three....OR does it work for 3 now?!
  
  /**
  divisor = s; //sets divisor to the the product I want
  remainder = s%divisor; //gets me the remainder
  int quotient;
  for(divisor = s; divisor > 0; divisor--)
  {
    remainder = s%divisor;
    if(remainder == 0)
    {
      quotient = s/divisor;
      factor = divisor; //factor stores the divisor #
      for(int l = 0; l < v2.size(); l++) //check divisor validity
      {
        //if the divisor is in the vector then 
        if(divisor == v2[l])
        {
          for(int m = 0; m < v2.size(); m++)
          {
            if(quotient == v2[m])
            {
              finalv.push_back(factor);
              finalv.push_back(quotient);
              return finalv;
            }
          }
        }
      }
    }
  }
  */
  
  //vector.clear();
  
  //IF v2 has 1 element that is 1
  //it will print out 1 1 as a subset....this is WRONG
  //have to consider this bound case
  if(v2.size() == 1)
  {
    cout << "No subset exists" << endl;
    finalv.push_back(-1);
    return finalv;
  }
  
  //Aw man the logic is off...if there is 9 but no 2 it will break for 18
  
  int newS = s;
  finalv.clear();
  for(int o = 0; o < v2.size(); o++)
  {
    for(int p = o; p < v2.size(); p++)
    {
      //case when a factor = s (kinda cheating) this makes quotient
      //1 which happens only once
      
      //I think this should be != to 1 then some statements...
      if(newS == v2[p] && v2[v2.size()-1] == 1) //check statement
      {
        finalv.push_back(v2[p]);
        finalv.push_back(v2[v2.size()-1]);
        return finalv;
      }
      if(newS == v2[p] && v2[v2.size()-1] != 1) //check statement
      {
        finalv.clear(); //clear the vector
        newS = s;
      }
      else if(newS % v2[p] == 0) //check if it divides
      {
        newS = newS/v2[p]; //now get the new number
        finalv.push_back(v2[p]);
        for(int q = p; q < v2.size(); q++) //start at where p is)
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
      newS = s;
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
  
  /**
  int total;
  do
  {
    total = 1;
    //multiplies all the numbers
    for(int n = 0; n < v2.size(); n++)
    {
      total *= a[n];
    }
    if(total != s)
    {
      //checking the subvector
      for(int o = 0; o < v2.size()-1; o++)
      {
        v2[o] = v2[o+1]; //makes vector shift to left
      }
      v2.pop_back(); //removes last element(first actually gets removed)
    }
    cout << total << endl;
  }while(total != s && total > s);
  
  if(total == s)
  {
    return v2;
  }
  */
}

//the double number breaks the program
//if 10 is entered once it will output 10 10...BAD

//repeats are messing me up.....OMG
//my algorithm does not work...sigh have to go back to the drawing board

int main()
{
  int size = 10;
  int a[size];
  a[0] = 2;
  a[1] = 3;
  a[2] = 4;
  a[3] = 120;
  a[4] = 11;
  a[5] = 0;
  a[6] = 5;
  a[7] = 24;
  a[8] = 17;
  a[9] = 3;
  int product = 24;
  vector<int> subset = subsetExists(a, size, product);
  for(int i = 0; i < subset.size(); i++)
  {
    cout << subset[i] << " ";
  }
  cout << endl;
  return 0; 
}

//B. This program executes at an asymptotic complexity of O(n^3)
