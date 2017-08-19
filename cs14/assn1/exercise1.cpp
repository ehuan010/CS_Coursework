#include <iostream>
#include <string>

using namespace std;

//A (a) and (b)

bool isPoly(string poly)
{
  
  //break up string into substrings based on the + sign
  //check validity of each substring
  
  //SOOOOO everytime a + is found...I check it first and continue if 
  //everything is valid???
  string temp = "";
  string temp2 = poly;
  bool valid = true;
  for(int j = 0; j < poly.length(); j++)
  {
    //cout << temp << endl;
    if(temp2.find("+") == -1) //when there is no more + signs
    {
      temp = temp2; //stores rest of poly into temp
    }
    else if(temp2.substr(j,1) == "+")
    {
      temp = temp2.substr(0,j); //I want everything but the +
      temp2 = temp2.substr(j+1); //get the rest of poly from after the +
    }
    else
    {
    }
    
    cout << temp << " hmm" << endl;
    
    //****I think I have to have all this in the first IF statement...
    int n_pos = temp.find("n"); //stores the position of n
    int index = 1; //or do I want it to be 0?
    if(n_pos == 0)
    {
      int k; //counter
        for(k = 1; k < temp.length(); k++) //don't need to check 1st one
        {        
          if(temp.substr(k,1) == " ") //if there are spaces ignore them
          {
            
            valid = true; //still valid
            index++;
          }
          else
          {
            //Assuming double ^ is never entered...
            if(temp.substr(k,1) == "^")
               //&& (temp.substr(k-1,1) == " "
               //|| (temp.substr(k-1,1) == "n"))) //need an AND statement?
            {
              valid = true;
              cout << "valid: " << valid << endl;
              index--; //quickfix
            }
            else if(temp.substr(k,1) == "0" || temp.substr(k,1) == "1" ||
                    temp.substr(k,1) == "2" || temp.substr(k,1) == "3" ||
                    temp.substr(k,1) == "4" || temp.substr(k,1) == "5" ||
                    temp.substr(k,1) == "6" || temp.substr(k,1) == "7" ||
                    temp.substr(k,1) == "8" || temp.substr(k,1) == "9" ||
                    temp.substr(k,1) == " ")
            {
              valid = true;
            }
            else
            {
              cout << "do I get here?" << endl;
              return false;
            }
          }
        }

    }
    else if(n_pos == temp.length()-1)
    {
      //case for when n is at the end of substr
      //traverse backwards
      //ONE decimal is a valid input...
      //FIGURE THIS ONE OUT ASAP
      
      //base case
      if(temp.length() == 1 && temp.substr(n_pos,1) == "n")
      {
       //then return true, iff n there is only an n....?
       //what if there are spaces, then what
       //need to add this case for the previous part too?....
       return true; 
      }
      else
      {
      for(int m = temp.length()-2; m > 0 ; m--)//check one before "n"
      {
        if(temp.substr(m,1) == " ")
        {
          valid = true;
        }
        else
        {
          if(temp.substr(m-1,1) == "*") //should be a * otherwise false
          {
            
            valid = true;
          }
          else
          {
            //I want to make sure there is only 1 decimal though :/
            if(temp.substr(m,1) == "0" || temp.substr(m,1) == "1" ||
               temp.substr(m,1) == "2" || temp.substr(m,1) == "3" ||
               temp.substr(m,1) == "4" || temp.substr(m,1) == "5" ||
               temp.substr(m,1) == "6" || temp.substr(m,1) == "7" ||
               temp.substr(m,1) == "8" || temp.substr(m,1) == "9" ||
               temp.substr(m,1) == " " || temp.substr(m,1) == ".")
            {
              valid = true;
            }
            else
            {
              return false;
            }
          }
        }
      }
      }
    }
    else if(n_pos == -1)//when n_pos is -1 or not found
    {
      //implies that the substring is a number
      //this algorithm should be fine
      for(int l = 0; l < temp.length(); l++)
      {
        if(temp.substr(l,1) == "0" || temp.substr(l,1) == "1" ||
           temp.substr(l,1) == "2" || temp.substr(l,1) == "3" ||
           temp.substr(l,1) == "4" || temp.substr(l,1) == "5" ||
           temp.substr(l,1) == "6" || temp.substr(l,1) == "7" ||
           temp.substr(l,1) == "8" || temp.substr(l,1) == "9" ||
           temp.substr(l,1) == " ")
        {
          valid = true;
        }
        else
        {
          return false;
        }
      }
    }
    else //this is for when n is in the middle...
    {
    }
  }
  if(valid == true)
  {
    return true;
  }
}

int main()
{
  bool valid; //checks initial cases for polynomial
  string poly;
  //This loop asks for user input
  do
  {
    valid = true;
    //A DO-WHILE loop is the best for checking input
    cout << "Enter a polynomial: ";
    getline(cin, poly);
    
    for(int i = 0; i < poly.length(); i++)
    {
      if(poly.substr(i,1) == "(" || poly.substr(i,1) == ")"
         || poly.substr(i,1) == "-")
      {
        cout << "Invalid input!!! Try again!" << endl;
        valid = false;
      }
    }
  }while(valid != true);
  //cout << poly << endl; //output the valid polynomial
  //do I need an if to say that valid == true ?
  
  
  valid = isPoly(poly); //put poly in to check!!!
  
  cout << valid << endl;
  
  if(valid == true)
  {
    cout << "It is a polynomial" << endl;
  }
  else
  {
    cout << "This is not a valid polynomial" << endl;
  }
  
  //use find to find where + is
  //find gives you the index number of the string
  //confusing myself...can't figure out where errors are occuring
  
  return 0;
}

//B
//If the length of the input expression is m chars, what is the big-Oh 
//complexity of your program with respect to m?

//The big-Oh complexity of my program with respect to m is O(n)
//because I only go through the input expression of m chars m times.
//The nested for loop only looks at a substring of m, so I don't include
//it in the big-Oh complexity calculation with respect to m.

//C
//Missing completed code

//The asymptotic complexity of the new program would probably be O(n^2)
//because I would need to traverse the string to find repeat terms of
//the same degree.
