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
using namespace std;

int main()
{
    //seeds the random function
    srand(time(NULL));
    
    //constants and variables
    const int USER = 0;
    const int COMP = 1;
    const int A = 10;
    const int B = 100;
    const int MIN = 1;
    const int MAX = 100;
    const int STUPID = 0;
    const int SMART = 1;
    
    //powers of 2 minus 1 for smart computer
    const int power1 = 1;
    const int power2 = 3;
    const int power3 = 7;
    const int power4 = 15;
    const int power5 = 31;
    const int power6 = 63;
    
    //integer value declarations and initializations
    bool turn = true;
    int r = A + rand() % (B - A + 1);
    int total = r;
    int user_comp;
    int stupid_smart;
    int remove;
    int C = 1;
    int D = total/2;
    int comp_remove;
    int empty = 0;
    int smart_strat;
    

    //string declaration
    string replay;
    do
    {
        total = r;
        //start of program
        cout << "Welcome to my nim program.\n"
             << endl;
    
        cout << "There are now "
             << r
             << " marbles in the pile.\n"
             << endl;
        
        //asks who to play first
        cout << "Who plays first (User: 0, Computer: 1)? ";
        cin >> user_comp;
        cout << endl;
        
        //continue to ask until user inputs 0 or 1
        while(user_comp != USER && user_comp != COMP)
        {
            cout << "Who plays first (User: 0, Computer: 1)? ";
            cin >> user_comp;
            cout << endl;
        }
        
        //output when user inputs 0 or 1
        if(user_comp == USER)
        {
            cout << "You play first\n"
                 << endl;
        }
        else
        {
            cout << "I play first\n"
                 << endl;
        }
        
        //ask for computer difficulty level
        cout << "Choose computer difficulty (Stupid: 0, Smart: 1)? ";
        cin >> stupid_smart;
        cout << endl;
             
        //tell user to re-enter until they enter 0 or 1
        while(stupid_smart != STUPID && stupid_smart != SMART)
        {
            cout << "Choose computer difficulty (Stupid: 0, Smart: 1)? ";
            cin >> stupid_smart;
            cout << endl;
        }
        
        //outputs the strategy computer will use
        if(stupid_smart == STUPID)
        {
            cout << "I will use my stupid strategy.\n"
                 << endl;
        }
        else
        {
            cout << "I will use my smart strategy.\n"
                 << endl;
        }
        
        //user goes first and stupid difficulty
        if(user_comp == USER && stupid_smart == STUPID)
        {
            //do this while there are marbles in the pile
            while(total >= MIN)           
            {
                //when turn is true it is the users turn
                if(turn)
                {
                    if(total > MIN)
                    {
                    cout << "How many marbles do you want to remove from "
                         << "the pile? ";
                    cin >> remove;
                    cout << endl;
                    
                    //output error message: input isn't in range
                    //ask for input again or continue loop
                    while(remove < C || remove > D)
                    {
                        cout << "Sorry, you can only remove between "
                             << C
                             << " and "
                             << D
                             << " marbles from the pile."
                             << endl
                             << endl;
                        cout << "How many marbles do you want to remove from"
                             << " the pile? ";
                        cin >> remove;
                        cout << endl;
                    }
                    
                    //do math to get how much is removed from total
                    total = total - remove;
                    //output marbles in pile after removing
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                    //Computers turn
                    turn = false;
                    
                    //computer remove calculation
                    D = total/2;
                    comp_remove = C + rand()%(D - C + 1);
                    //Computer removes from pile
                    cout << "I am removing "
                         << comp_remove
                         << " marbles from the pile."
                         << endl
                         << endl;
                         
                    
                    total -= comp_remove;
                    //output total after computer removes
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                    //next move can't remove D = total/2;
                    D = total/2;
                    
                    //back to users turn
                    turn = true;
                }
                else
                {
                    if(turn == true)
                    {
                        cout << "How many marbles do you want to remove "
                             << "from the pile? ";
                        cin >> remove;
                        cout << endl;
                        total -= remove;
                        cout << "There are now 0 marbles in the pile"
                             << endl
                             << endl;
                    }
                    else
                    {
                        turn = false;
                        cout << "I am removing 1 marble from the pile.\n"
                             << endl;
                        total -= MIN;
                        cout << "There are now 0 marbles in the pile.\n"
                             << endl
                             << endl;
                    }
                }
                }
            }
        }
        
        //computer goes first and stupid strategy
        if(user_comp == COMP && stupid_smart == STUPID)
        {
            //do this while there are marbles in the pile
            while(total >= MIN)           
            {
                //when turn is true it is the users turn
                if(turn)
                {
                    if(total > MIN)
                    {
                    //Computers turn
                    turn = false;
                    
                    //computer remove calculation
                    D = total/2;
                    comp_remove = C + rand()%(D - C + 1);
                
                    //Computer removes from pile
                    cout << "I am removing "
                         << comp_remove
                         << " marbles from the pile."
                         << endl
                             << endl;
                         
                    
                    total -= comp_remove;
                    //output total after computer removes
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                    //next move can't remove D = total/2;
                    D = total/2;
                    
                    //back to users turn
                    turn = true;
                    
                    cout << "How many marbles do you want to remove from "
                         << "the pile? ";
                    cin >> remove;
                    cout << endl;
                    
                    //output error message: input isn't in range
                    //ask for input again or continue loop
                    while(remove < C || remove > D)
                    {
                        cout << "Sorry, you can only remove between "
                             << C
                             << " and "
                             << D
                             << " marbles from the pile."
                             << endl
                             << endl;
                        cout << "How many marbles do you want to remove from"
                             << " the pile? ";
                        cin >> remove;
                        cout << endl;
                    }
                    
                    //do math to get how much is removed from total
                    total = total - remove;
                    //output marbles in pile after removing
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                }
                //do this when the total is 1
                else
                {
                    if(turn == true)
                    {
                        cout << "How many marbles do you want to remove "
                             << "from the pile? ";
                        cin >> remove;
                        cout << endl;
                        total -= remove;
                        cout << "There are now 0 marbles in the pile"
                             << endl
                             << endl;
                    }
                    else
                    {
                        turn = false;
                        cout << "I am removing 1 marble from the pile.\n"
                             << endl;
                        total -= MIN;
                        cout << "There are now 0 marbles in the pile.\n"
                             << endl
                             << endl;
                    }
                }
                }
            }
        }
        
        
        
        //user goes first and computer uses smart strategy
        if(user_comp == USER && stupid_smart == SMART)
        {
            //do this while there are marbles in the pile
            while(total >= MIN)           
            {
                //when turn is true it is the users turn
                if(turn)
                {
                    if(total >MIN)
                    {
                    cout << "How many marbles do you want to remove from "
                         << "the pile? ";
                    cin >> remove;
                    cout << endl;
                    
                    //output error message: input isn't in range
                    //ask for input again or continue loop
                    while(remove < C || remove > D)
                    {
                        cout << "Sorry, you can only remove between "
                             << C
                             << " and "
                             << D
                             << " marbles from the pile."
                             << endl
                             << endl;
                        cout << "How many marbles do you want to remove from"
                             << " the pile? ";
                        cin >> remove;
                        cout << endl;
                    }
                    
                    //do math to get how much is removed from total
                    total = total - remove;
                    //output marbles in pile after removing
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                    //Computers turn
                    turn = false;
                    
                    //computer remove calculation
                    D = total/2;
                    //the smart strategy calculations and formulas
                    if(total != power1 && total!= power2 && total != power3
                    && total != power4 && total != power5 &&
                    total != power6)
                    {
                        if(total > power6)
                        {
                            comp_remove = total - power6;
                        }
                        else if(total > power5 && total < power6)
                        {
                            comp_remove = total - power5;
                        }
                        else if(total > power4 && total < power5)
                        {
                            comp_remove = total - power4;
                        }
                        else if(total > power3 && total < power4)
                        {
                             comp_remove = total - power3;
                        }
                        else if(total > power2 && total < power3)
                        {
                             comp_remove = total - power2;
                        }
                        else
                        {
                             comp_remove = total - power1;
                        }
                    }
                    else
                    {
                        comp_remove = C + rand()%(D - C + 1);
                    }
                    
                    
                    //Computer removes from pile
                    cout << "I am removing "
                         << comp_remove
                         << " marbles from the pile."
                         << endl
                         << endl;
                         
                    
                    total -= comp_remove;
                    //output total after computer removes
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                    //next move can't remove D = total/2;
                    D = total/2;
                    
                    //back to users turn
                    turn = true;
                }
                //do this when the total is 
                else
                {
                    if(turn == true)
                    {
                        cout << "How many marbles do you want to remove "
                             << "from the pile? ";
                        cin >> remove;
                        cout << endl;
                        total -= remove;
                        cout << "There are now 0 marbles in the pile"
                             << endl
                             << endl;
                    }
                    else
                    {
                        turn = false;
                        cout << "I am removing 1 marble from the pile.\n"
                             << endl;
                        total -= MIN;
                        cout << "There are now 0 marbles in the pile.\n"
                             << endl
                             << endl;
                    }
                }
                }
            }
        }
        
        //computer goes first and uses smart strategy
        if(user_comp == COMP && stupid_smart == SMART)
        {
            //do this while there are marbles in the pile
            while(total > MIN)           
            {
                //when turn is true it is the users turn
                if(turn)
                {
                    if(total >MIN)
                    {
                    //Computers turn
                    turn = false;
                    
                    //computer remove calculation
                    D = total/2;
                    //the smart strategy calculations and formulas
                    if(total != power1 && total!= power2 && total != power3
                    && total != power4 && total != power5 &&
                    total != power6)
                    {
                        if(total > power6)
                        {
                            comp_remove = total - power6;
                        }
                        else if(total > power5 && total < power6)
                        {
                            comp_remove = total - power5;
                        }
                        else if(total > power4 && total < power5)
                        {
                            comp_remove = total - power4;
                        }
                        else if(total > power3 && total < power4)
                        {
                            comp_remove = total - power3;
                        }
                        else if(total > power2 && total < power3)
                        {
                            comp_remove = total - power2;
                        }
                        else
                        {
                            comp_remove = total - power1;
                        }
                    }
                    else
                    {
                        comp_remove = C + rand()%(D - C + 1);
                    }
                    
                    //Computer removes from pile
                    cout << "I am removing "
                         << comp_remove
                         << " marbles from the pile."
                         << endl
                         << endl;
                         
                    
                    total -= comp_remove;
                    //output total after computer removes
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                    //next move can't remove D = total/2;
                    D = total/2;
                    
                    //back to users turn
                    turn = true;
                    
                    cout << "How many marbles do you want to remove from "
                         << "the pile? ";
                    cin >> remove;
                    cout << endl;
                    
                    //output error message: input isn't in range
                    //ask for input again or continue loop
                    while(remove < C || remove > D)
                    {
                        cout << "Sorry, you can only remove between "
                             << C
                             << " and "
                             << D
                             << " marbles from the pile."
                             << endl
                             << endl;
                        cout << "How many marbles do you want to remove from"
                             << " the pile? ";
                        cin >> remove;
                        cout << endl;
                    }
                    
                    //do math to get how much is removed from total
                    total = total - remove;
                    //output marbles in pile after removing
                    cout << "There are now "
                         << total
                         << " marbles in the pile."
                         << endl
                         << endl;
                }
                //do this when the total is 1
                else
                {
                    if(turn == true)
                    {
                        cout << "How many marbles do you want to remove "
                             << "from the pile? ";
                        cin >> remove;
                        cout << endl;
                        total -= remove;
                        cout << "There are now 0 marbles in the pile"
                             << endl
                             << endl;
                    }
                    else
                    {
                        turn = false;
                        cout << "I am removing 1 marble from the pile.\n"
                             << endl;
                        total -= MIN;
                        cout << "There are now 0 marbles in the pile.\n"
                             << endl
                             << endl;
                    }
                }
                }
            }
        }
        
        
        //outputs whether user wins or loses
        if(turn == USER)
        {
            cout << "You win\n"
                 << endl;
        }
        else
        {
            cout << "You lose\n"
                 << endl;
        }

        //reset variables
        r = A + rand() % (B - A + 1);
        total = r;
        D = total/2;
        //ask to play again
        cout << "Do you want to play again (yes or no)? " ;
        cin >> replay;
        cout << endl;
    }
    while(replay == "yes");
    //if user inputs no then program quits
    cout << "Thanks for playing.\n";
    
    
    return 0;
}
