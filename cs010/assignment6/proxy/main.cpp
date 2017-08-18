#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main ()
{
    //seed the random number generator
    srand(time(NULL));
  
    //declare the constants
    const int A = 10;
    const int B = 100;
    const int USER_TURN = 0;
    const int COMPUTER_TURN = 1;
    const int MIN_TAKE_OUT = 1;
    const int STUPID = 0;
    const int SMART = 1;
   
    //random number generator
    int r = A + rand() % (B-A+1);
    const int MAX_TAKE_OUT = r/2;
   
   
    //declare variable types and initialize variables
   
    int total_marbles = r;
    int half_marbles = total_marbles / 2;
    int starter;
    int difficulty;
    int take_out;
    string answer;
    bool turn = true;
    int i = 0;
    int smart_cr;
   
   
   
    //greeting
    cout << "Welcome to my nim program." << endl << endl;
   
    //start the game
    do
    {
        cout << "There are now " << r << " marbles in the pile."
             << endl << endl;
       
        cout << "Who plays first (User: 0, Computer: 1)?";
        cin >> starter;   
        cout << endl;
       
        //determine who starts first
        while( starter != USER_TURN && starter != COMPUTER_TURN)
        {
            cout << "Error. You didn't pick 0 or 1. Pick again. ";
            cin >> starter;
            cout << endl;   
        }
       
        if(starter == USER_TURN)
        {
            cout << "You play first." << endl << endl;
           
        }
        else
        {
            cout << "I play first." << endl << endl;
        }
       
       
        //determine the computer difficulty level
        cout << "Computer difficulty (Stupid: 0, Smart: 1)";
        cin >> difficulty;
        cout << endl;
       
        while( difficulty != STUPID && difficulty != SMART)
        {
            cout << "Error. you didnt pick 0 or 1. Pick again. ";
            cin >> difficulty;
            cout << endl;
        }
   
        if(difficulty == STUPID)
        {
            cout << "I will use my stupid strategy." << endl << endl;
        }
        else
        { 
            cout << "I will use my smart strategy." << endl << endl;
        }
       
       
        //computer difficulty is easy and user goes first
        if(difficulty == 0 && starter == USER_TURN)
        {
           
            while( total_marbles > 1 )
            {
                if(turn)
                {
                    cout << "How many marble(s) do you want to remove "
                    << "from the pile?";
                    cin >> take_out;
                    cout << endl;
                   
                           
                    while(take_out > half_marbles || take_out < 1)
                    {
                        cout <<"Sorry, you can only remove between "
                             << MIN_TAKE_OUT
                             << " and " << half_marbles
                             << " marbles from the pile." << endl << endl;
                        cout << "How many marble(s) do you want to remove "
                             << "from the pile?";
                        cin >> take_out;
                        cout << endl;
                       
                       
                    }
                   
                   
                    total_marbles -= take_out;
                    half_marbles = total_marbles / 2;
                    cout << "There are now " << total_marbles
                         << " marble(s) in "
                         << "the pile." << endl << endl;
                        turn = false;
                   
                       
           
                   
                   
                    int cr = 1 + rand() % (half_marbles);
                    cout << "I am removing " << cr << " marble(s)"
                         << " from the pile" << endl << endl;
                    total_marbles -= cr;
                    half_marbles = total_marbles / 2;
                    cout << "There are now " << total_marbles
                         << " marble(s) in the pile." << endl << endl;
               
                        turn = true;
                    
                 }
                   
               
            }
           
           
        }
       
        //computer difficulty is easy and computer has the first move
        else if(difficulty == 0 && starter == COMPUTER_TURN)
        {
            turn = false;
            while(total_marbles > 1)
            {
                if(turn)
                {
                    cout << "How many marble(s) do you want to remove "
                    << "from the pile?" ;
                    cin >> take_out;
                    cout << endl;
                   
                    while(take_out < 1 || take_out > half_marbles)
                    {
                        cout <<"Sorry, you can only remove between "
                        << MIN_TAKE_OUT
                        << " and " << half_marbles
                        << " marbles from the pile." << endl << endl;
                        cout << "How many marble(s) do you want to remove "
                        << "from the pile?";
                        cin >> take_out;
                        cout << endl;
                    }
                total_marbles -= take_out;
                half_marbles = total_marbles / 2;
                cout << "There are now " << total_marbles
                     << " marble(s) in the pile." << endl << endl;
                turn = false;
                  }
            
           
               
                int cr = rand() % half_marbles + 1;
                cout << "I am removing " << cr << " from the pile."
                     << endl << endl;
                    
                total_marbles -= cr;
                half_marbles = total_marbles / 2;
                cout << "There are now " << total_marbles
                     << " marble(s) in the pile." << endl << endl;
                turn = true;
 
            }
       
        }
       
       
       
        if(total_marbles != 1 && total_marbles != 3 && total_marbles != 7
        && total_marbles != 15 && total_marbles != 31 &&
        total_marbles != 63)
       
        {
            if(total_marbles > 63)
            {
                smart_cr = total_marbles - 63;
            }
            else if(total_marbles > 31 && total_marbles < 63)
            {
                smart_cr = total_marbles - 31;
            }
            else if(total_marbles > 15 && total_marbles < 31)
            {
                smart_cr = total_marbles - 15;
            }
            else if(total_marbles > 7 && total_marbles < 15)
            {
                smart_cr = total_marbles - 7;
            }
            else if(total_marbles > 3 && total_marbles < 7)
            {
                smart_cr = total_marbles - 3;
            }
            else
            {
                smart_cr = total_marbles - 1;
            }
        }
        else if(total_marbles == 1 && total_marbles == 3
        && total_marbles == 7
        && total_marbles == 15 && total_marbles == 31 &&
        total_marbles == 63)
        {
            if(total_marbles > 63)
            {
                smart_cr = total_marbles - 63;
            }
            else if(total_marbles > 31 && total_marbles < 63)
            {
                smart_cr = total_marbles - 31;
            }
            else if(total_marbles > 15 && total_marbles < 31)
            {
                smart_cr = total_marbles - 15;
            }
            else if(total_marbles > 7 && total_marbles < 15)
            {
                smart_cr = total_marbles - 7;
            }
            else if(total_marbles > 3 && total_marbles < 7)
            {
                smart_cr = total_marbles - 3;
            }
            else
            {
                smart_cr = total_marbles - 1;
            }
        }
       
     
           
       
       
 
           
       
            //output who wins depending on who has the last turn       
            if(turn == true)
            {
                cout << "You Lose!" << endl << endl;
            }
            else
            {
                cout << "You Win!" << endl << endl;
            }
           
            //ask to play again
            cout << "Do you want to play again? (yes/no)" << endl << endl;
            cin >> answer;  
            cout << endl;
            r = A + rand() % (B-A+1); 
            total_marbles = r;
            half_marbles = total_marbles / 2;
    }
       
       
        //program replays if user types yes
        while(answer == "yes" );
        {
            //program quits if user does not want to play again
            cout << "Thanks for playing!" << endl << endl;
        }
       
      
   
   
    return 0; 
}
