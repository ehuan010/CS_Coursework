// Course: CS 12 Winter 2012
//
// First Name: Edward
// Last Name: Huang
// Course username: ehuan010
// email address: ehuan010@student.ucr.edu
//
// Lecture Section: 002
// Lab Section: 022
// TA: Wojchiek Karas
//
// Assignment: assn1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Generates a random integer between an upper and lower parameter
 * @param upper: The upper bound for the random number
 * @param lower The lower bound for the random number
 * @return: The integer value of the random number generated
 */
int random(int upper, int lower)
{
  return rand()% (upper - lower + 1) + lower;
}

/* Gets the value of powers of 2 minus 1
 * @param n: Passes in the power of 2
 * @return: Returns the value of the powers of (2^n - 1) 
 */
int powers_of_2(int n)
{
  int power = 1;
  for(int i = 0; i < n; i++)
  {
    power = power * 2;
  }
  power = power - 1;
  return power;
}


/* Calculates how much the computer removes from the pile during its turn
 * @param pile: Reference parameter to change the total # of marbles in pile
 * @param difficulty: Determines which strategy the computer will be using
 */
void computer_play(int &pile, string difficulty)
{
  const int difference1 = powers_of_2(1);
  const int difference2 = powers_of_2(2);
  const int difference3 = powers_of_2(3);
  const int difference4 = powers_of_2(4);
  const int difference5 = powers_of_2(5);
  const int difference6 = powers_of_2(6);
  if(difficulty == "n" || difficulty == "naive")
  {
    int half_pile = pile/2;
    int remove = random(half_pile, 1);
    cout << "I am removing " << remove << " marbles from the pile." << endl;
    pile = pile - remove;
  }
  else
  {
    if(pile != difference3 && pile != difference4 && pile != difference5)
    {
      int remove;
      if(pile > difference6)
      {
        remove = pile - difference6;
      }
      else if(pile > difference5 && pile < difference6)
      {
        remove = pile - difference5; 
      }
      else if(pile > difference4 && pile < difference5)
      {
        remove = pile - difference4;
      }
      else if(pile > difference3 && pile < difference4)
      {
        remove = pile - difference3;
      }
      else if(pile > difference2 && pile < difference3)
      {
        remove = pile - difference2;
      }
      else
      {
        remove = pile - difference1;
      }
      pile = pile - remove;
      cout << "I am removing " << remove << " marbles from the pile.\n";
    }
    else
    {
      int half_pile = pile/2;
      int remove = random(half_pile, 1);
      cout << "I am removing " << remove << " marbles from the pile.\n"; 
      pile = pile - remove;
    }
  }
}

/* Determines how many marbles the user removes during his/her turn
 * @param pile: Reference parameter to change the total # of marbles in pile
 */
void user_play(int &pile)
{
  cout << "How many marbles do you want to remove from the pile? ";
  int remove;
  cin >> remove;
  int half_pile = pile/2;
  while(remove < 1 || remove > half_pile)
  {
    cout << "Error! You can only remove between 1 and " << half_pile
         << " marbles." << endl
         << "How many marbles do you want to remove from the pile? ";
    cin >> remove;
  }
  pile = pile - remove;
}


/* This is the special case calculation and output for the user when there 
 * is 1 marble left in the pile
 * @param pile: Reference parameter to change the total # of marbles in pile
 */
void special_case_user(int &pile)
{
  cout << "How many marbles do you want to remove from the pile? ";
  int remove;
  cin >> remove;
  while(remove != 1)
  {
    cout << "Error! You can only remove between 1 and 1 marbles.\n"
         << "How many marbles do you want to remove from the pile? ";
    cin >> remove;
  }
  pile = pile - remove;
  cout << "You removed the last marble!\n";
}

int main()
{
  srand(time(NULL));
  string replay;
  const int UPPER = 100;
  const int LOWER = 10;
  const int COMP_TURN = 1;
  const int USER_TURN = 0;
  const int MIN_MARBLES = 1;
  //loop for the entire game
  do
  {
    //greeting
    cout << "Hello and welcome to the game of Nim!\n";
    
    //pick difficulty
    string difficulty;
    cout << "Choose difficulty for the computer (naive or smart): ";
    cin >> difficulty;
    
    //Generate initial size of pile
    int total_marbles = random(UPPER, LOWER);
    cout << "There are currently " << total_marbles
         << " marbles in the pile." << endl;
    
    //randomly generates who goes first: starter(0 = USER or 1 = COMP)
    int starter = random(COMP_TURN, USER_TURN);

    int turn_tracker = USER_TURN; //tracks whose turn it is
    if(starter == USER_TURN)  //If the user starts do this
    {
      cout << "You go first." << endl;
      while(total_marbles > MIN_MARBLES)
      {
        if(turn_tracker == USER_TURN)
        {
          user_play(total_marbles);
          cout << "There are now " << total_marbles 
               << " marbles in the pile." << endl;
          turn_tracker = COMP_TURN;
        }
        else
        {
          computer_play(total_marbles, difficulty);
          cout << "There are now " << total_marbles 
               << " marbles in the pile." << endl;
          turn_tracker = USER_TURN;
        }
      }
      while(total_marbles == MIN_MARBLES)
      {
        if(turn_tracker == USER_TURN)
        {
          special_case_user(total_marbles);
        }
        else
        {
          cout << "I removed the last marble!\n";
          total_marbles -= MIN_MARBLES;
        }
      }
    }
    else //If the computer starts do this
    {
      cout << "Computer goes first." << endl;
      turn_tracker = COMP_TURN;
      while(total_marbles > MIN_MARBLES)
      {
        if(turn_tracker == USER_TURN)
        {
          user_play(total_marbles);
          cout << "There are now " << total_marbles 
               << " marbles in the pile." << endl;
          turn_tracker = COMP_TURN;
        }
        else
        {
          computer_play(total_marbles, difficulty);
          cout << "There are now " << total_marbles 
               << " marbles in the pile." << endl;
          turn_tracker = USER_TURN;
        }
      }
      while(total_marbles == MIN_MARBLES)
      {
        if(turn_tracker == USER_TURN)
        {
          special_case_user(total_marbles);
        }
        else
        {
          cout << "I removed the last marble!\n";
          total_marbles -= MIN_MARBLES;
        }
      }
    }
    //Determines and prints out who wins/loses
    if(turn_tracker == USER_TURN)
    {
      cout << "You Lose!!! :(" << endl;
    }
    else
    {
      cout << "You Win!!! :)" << endl;
    }
    
    //asks to replay
    cout << "Would you like to play again? (yes or no)\n";
    cin >> replay;
  }while(replay == "y" || replay == "yes");
}
