// Course: CS 10 Fall 2011
//
// First Name: Edward
// Last Name: Huang
// Login id: ehuan010
// email address: ehuan010@student.ucr.edu
//
// Lecture Section: 003
// Lab Section: 023
// TA: Huy Hang
//
// Assignment: Assignment 10
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

//Function to sort vector a and vector b in order and store values in merged
// *compares index's in a and b
// *stores larger one in merged
// *if sizes are diff. merged continues taking values from the larger vector
// after comparing the two
void merge_sorted(vector<int> &merged, 
                 const vector<int> &a, 
                 const vector<int> &b)
{
  int i = 0;
  int j = 0;
  while(i < a.size() && j < b.size())
  {
    if(a[i] < b[j])
    {
      merged.push_back(a[i]);
      i++;
    }
    else
    {
      merged.push_back(b[j]);
      j++;
    }
  }
  while(i < a.size())
  {
    merged.push_back(a[i]);
    i++;
  }
  while(j < b.size())
  {
    merged.push_back(b[j]);
    j++;
  }
}

//equals: helper function for test harness
// *checks if index in v1 and v2 are the same
bool equals(const vector<int> &v1, const vector<int> &v2)
{
  if(v1.size() != v2.size())
  {
    return false;
  }
  for(int i = 0; i < v1.size(); i++)
  {
    if(v1[i] != v2[i])
    {
      return false;
    }
  }
  return true;
}


//Compares if values in vector m and vector expected are the same
// *outputs actual values that are sorted into m
// *outputs what the expected values are (self-calculated)
// *outputs Failed if two vectors do not match
// *outputs Passed if the two vectors match and pass the test
void test_harness(const vector<int> &m, const vector<int> &expected)
{
  cout << "Actual: ";
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i] << " ";
  }
  cout << endl
       << "Expected: ";
  for(int k = 0; k < expected.size(); k++)
  {
    cout << expected[k] << " ";
  }
  cout << endl;
  if(!equals(m, expected))
  {
    cout << "Failed";
  }
  else
  {
    cout << "Passed";
  }
  cout << endl;
}

int main()
{
  //vectors used to store values
  vector<int>m;
  vector<int>test1;
  vector<int>test2;
  vector<int>expected;

//---------------------------------------------------------------------------
  
  //Test when vector test1 and test2 are the same size
  
  //4 values in test1 vector
  test1.push_back(1); 
  test1.push_back(3); 
  test1.push_back(4); 
  test1.push_back(7); 
  //4 values in test2 vector;
  test2.push_back(2);
  test2.push_back(4);
  test2.push_back(8);
  test2.push_back(10);
  //8 expected values in order
  expected.push_back(1);
  expected.push_back(2);
  expected.push_back(3);
  expected.push_back(4);
  expected.push_back(4);
  expected.push_back(7);
  expected.push_back(8);
  expected.push_back(10);
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << "Test case: Vector test1 and vector test2 are the same size"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();

//---------------------------------------------------------------------------  

  //Test when both vectors are empty
  
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << endl
       << "Test case: Vector test1 and vector test2 are empty vectors"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();
  
//---------------------------------------------------------------------------

  //Test when size of vector test1 is smaller than size of vector test2
  
  //test1 with 2 values
  test1.push_back(12);
  test1.push_back(14);
  //test2 with 4 values
  test2.push_back(4);
  test2.push_back(9);
  test2.push_back(11);
  test2.push_back(13);
  //6 expected values in order
  expected.push_back(4);
  expected.push_back(9);
  expected.push_back(11);
  expected.push_back(12);
  expected.push_back(13);
  expected.push_back(14);
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << endl
       << "Test case: Vector test1 is smaller than vector test2"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();
  
//---------------------------------------------------------------------------

  //Test when size of vector test1 is larger than size of vector test2
  
  //test1 with 4 values
  test1.push_back(4);
  test1.push_back(7);
  test1.push_back(15);
  test1.push_back(18);
  //test2 with 2 values
  test2.push_back(13);
  test2.push_back(20);
  //6 expected values in order
  expected.push_back(4);
  expected.push_back(7);
  expected.push_back(13);
  expected.push_back(15);
  expected.push_back(18);
  expected.push_back(20);
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << endl
       << "Test case: Vector test1 is larger than vector test2"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();
  
//---------------------------------------------------------------------------
  
  //Test when vector test1 is empty and vector test2 has values
  
  //test2 with 4 values
  test2.push_back(3);
  test2.push_back(6);
  test2.push_back(9);
  test2.push_back(12);
  //4 expected values in order;
  expected.push_back(3);
  expected.push_back(6);
  expected.push_back(9);
  expected.push_back(12);
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << endl
       << "Test case: Vector test1 is empty and vector test2 has 4 values"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();
  
//---------------------------------------------------------------------------

  //Test when vector test1 has values and test2 is empty
  
  //test1 with 4 values
  test1.push_back(2);
  test1.push_back(4);
  test1.push_back(6);
  test1.push_back(8);
  //4 expected values in order;
  expected.push_back(2);
  expected.push_back(4); 
  expected.push_back(6);
  expected.push_back(8);
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << endl
       << "Test case: Vector test1 has 4 values and vector test2 is empty"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();
  
//---------------------------------------------------------------------------

  //Test when negative values are in vector 1 and vector 2
   
  //test1 with 3 values
  test1.push_back(-14);
  test1.push_back(-9);
  test1.push_back(-2);
  //test2 with 3 values
  test2.push_back(-7);
  test2.push_back(-2);
  test2.push_back(-1);
  //6 expected values in order;
  expected.push_back(-14);
  expected.push_back(-9);
  expected.push_back(-7);
  expected.push_back(-2);
  expected.push_back(-2);
  expected.push_back(-1);
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << endl
       << "Test case: Vector test1 and vector test2 has negative values"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();
  
  //---------------------------------------------------------------------------

  //Test when negative and positive values are in vector 1 and vector 2
   
  //test1 with 4 values
  test1.push_back(-15);
  test1.push_back(-9);
  test1.push_back(-2);
  test1.push_back(0);
  //test2 with 4 values
  test2.push_back(-7);
  test2.push_back(-5);
  test2.push_back(4);
  test2.push_back(15);
  //8 expected values in order;
  expected.push_back(-15);
  expected.push_back(-9);
  expected.push_back(-7); 
  expected.push_back(-5);
  expected.push_back(-2);
  expected.push_back(0);
  expected.push_back(4);
  expected.push_back(15);
  //sorts the two vectors and places them into vector m
  merge_sorted(m, test1, test2);
  //explains the test case
  cout << endl
       << "Test case: Both vectors have mix of negative and positive values"
       << endl;
  //takes vector m and expected compares whether they are the same
  test_harness(m, expected);
  
  //clear the vectors to be re-used
  test1.clear();
  test2.clear();
  m.clear();
  expected.clear();
}
