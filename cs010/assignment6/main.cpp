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
// Assignment: Assignment 6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    //GAME OF NIM
    //take turns taking marbles
    //10-100 for initial size of pile (random)
    //random integer b/t 0-1 to decide whether computer or human is first
    //random int b/t 0-1 to decide stupid or smart computer difficulty
    //stupid: random legal value between (1 and n/2)
    //smart mode: value of ((2^n)-1). if pile  is one < power of 2 make
    //a random legal move for computer.
    
    //computer cannot be beaten in smart mode when it has the first move
    //unless pile size happens to be 15,31, or 63
    //if player goes first and knows winning strategy player can win 
    
    //NOTE: r gives you a different number everytime
    
    //
    
    srand(time(NULL));
    //declarations an initialization of variables
    const int A = 10;
    const int B = 100;
    bool winner = true;
    int user_comp;
    int stupid_smart;
    int smart_strat;
    int stupid_strat;
    int remove;
    string replay;
    int r = A + rand()%(B - A + 1);
    int total = r;
    
    
        
    do
    {
        cout << "Welcome to my nim program.\n"
             << endl;
    
        cout << "There are now "
             << r
             << " marbles in the pile.\n"
             << endl;
    
        cout << "Who plays first (User: 0, Computer: 1)? ";
        cin >> user_comp;
        cout << endl;
        while(user_comp == 0)
        {
            cout << "You play first.\n"
                 << endl;
            cout << "Computer difficulty (Stupid: 0, Smart:1)? ";
            cin >> stupid_smart;
            cout << endl;
            if(stupid_smart == 0)
            {
                cout << "I will use my stupid strategy.\n"
                     << endl;
                while(total >= 0 && total < B)
                {
                     cout << "How many marbles do you want to remove from" 
                          << " the pile? ";
                     cin >> remove;
                     cout << endl;
                     int C = 1;
                     int D = (total/2);
                     int r2 = C + rand()%(D - C + 1);
                     if(remove <= 0 || remove > D)
                     {
                         cout << "Sorry, you can only remove between 1"
                              << " and "
                              << D
                              << " marbles from the pile\n"
                              << endl;
                     }
                     else if(remove > 0 && remove < D)
                     //(remove > 0 && remove < D)
                     {
                         total -= remove;
                         cout << "There are now "
                              << total
                              << " marbles in the pile.\n"
                              << endl;

                         D = total/2;
                         r2 = C + rand()%(D - C + 1);
                         cout << "I am removing "
                              << r2
                              << " marbles from the pile.\n"
                              << endl;
                         total -= r2;
                         cout << "There are now "
                              << total
                              << " marbles in the pile.\n"
                              << endl;
                        }
                        if(total == 0)
                        {
                            cout << "There are now "
                                 << total
                                 << " marbles in the pile.\n"
                                 << endl;
                        }
                    }
                }
            else
            {
                cout << "I will use my smart strategy.\n"
                     << endl;
            }
            
        
        
        }
        while(user_comp == 1)
        {
            cout << "I play first.\n"
                 << endl;
        }
         
         

    cout << "Do you want to play again (yes or no)? " ;
    cin >> replay;
    cout << endl;
    }
    while(replay == "yes");
    
    cout << "Thanks for playing.\n";
    
    return 0;
}
