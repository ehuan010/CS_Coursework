#include <vector>
#include <iostream>
#include <string>
using namespace std;

const string SENTINEL = "done";
int main()
{
  
  vector<string>sentence;
  string word;
  
  cout << "Enter words (enter the word done to quit): ";
  while(word != SENTINEL)
  {
    cin >> word;
    if(word != SENTINEL)
    {
      sentence.push_back(word);
    }
  }
  char first_letter;
  cout << "Enter a letter: ";
  cin >> first_letter;
  for(int i = 0; i < sentence.size(); i++)
  {
    if(sentence[i][0] == first_letter)
    {
      cout << sentence[i] 
           << " ";
    }
  }
  cout << endl;
    
  return 0;
}
