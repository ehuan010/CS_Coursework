#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
  srand(1000);
 
 
 
  //Declaring initial values for number of times score is achieved
  double num0 = 0.0;
  double num20 = 0.0;
  double num21 = 0.0;
  double num22 = 0.0;
  double num23 = 0.0;
  double num24 = 0.0;
  double num25 = 0.0;
  
  cout << "Hold-at-20 turns simulations? ";
  int numTurns;
  cin >> numTurns;
  cout << endl;
 
 
  const int A = 1;
  const int B = 6;
 
 
  
 
  for(int i = 1; i <= numTurns; i++)
  { 
      //int diceRoll = A + rand() % (B - A + 1);
     bool roll = true;
     
      int score = 0;
      do
      {
          int diceRoll = A + rand() % (B - A + 1);
         
          //cout << diceRoll << " ";
          if(diceRoll == 1)
          {
              num0++;
              score = 0;
              roll = false;
          }
          else //if(diceRoll != 1)
          {
              score += diceRoll;
         
              if(score == 20)
              {
                  num20++;
                  //score = 0;
              }
              else if(score == 21)
              {
                  num21++;
              }
              else if(score == 22)
              {
                  num22++;
              }
              else if(score == 23)
              {
                  num23++;
              }
              else if(score == 24)
              {
                  num24++;
              }
              else if(score == 25)
              {
                  num25++;
              }
          }

 
      }while(roll == true && score < 20);
  }
 
     
 
 
  cout << "Score" << "   " << "Estimated Probability" << endl;
 
  cout << setw(8) << left << "0"
       << fixed << setprecision(6)
       << (num0) / (numTurns) << endl;
      
  cout << setw(8) << left << "20"
       << fixed << setprecision(6)
       << (num20) / (numTurns) << endl;
      
  cout << setw(8) << left << "21"
       << fixed << setprecision(6)
       << (num21) / (numTurns) << endl;
      
  cout << setw(8) << left << "22"
       << fixed << setprecision(6)
       << (num22) / (numTurns) << endl;
      
  cout << setw(8) << left << "23"
       << fixed << setprecision(6)
       << (num23) / (numTurns) << endl;
      
  cout << setw(8) << left << "24"
       << fixed << setprecision(6)
       << (num24) / (numTurns) << endl;
      
  cout << setw(8) << left << "25"
       << fixed << setprecision(6)
       << (num25) / (numTurns) << endl;
 
      
  return 0;
}
