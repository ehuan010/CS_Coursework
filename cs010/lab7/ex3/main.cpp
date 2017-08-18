/* Exercise 3 of Lab 7
 *
 * Name: Edward Huang
 * Lab Section: 23
 * Date: 11/8/11
 *
 * Create the card game in the lab specification.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

// TODO: Face card constants (declared globally)
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 1;

// TODO: Suit type constants (declared globally)
const int HEARTS = 1;
const int DIAMONDS = 2;
const int SPADES = 3;
const int CLUBS = 4;

// TODO: Grab random function from previous exercise and copy it here
int random_number(int A, int B)
{
    return A + rand() % (B - A + 1);
}

// TODO: create translate_card_type function, takes a suit type number returns
//        a string of the proper suit
// HINT: you will need to copy your constants for suit types from main
string translate_card_type(int c)
{
    string s;
    if(c == 1)
    {
        s = "Hearts";
    }
    else if(c == 2)
    {
        s = "Diamonds";
    }
    else if(c == 3)
    {
        s = "Spades";
    }
    else
    {
        s = "Clubs";
    }
    return s;
}

// TODO: create translate_card_num function, takes a card number and the proper
//        face name string for associated with the card is returned
// HINT: you will need to copy your constants for face card numbers from main
string translate_card_number(int d)
{
    string card_trans;
    if(d == 1)
    {
        card_trans = "Ace";
    }
    else if(d == 2)
    {
        card_trans = "2";
    }
    else if(d == 3)
    {
        card_trans = "3";
    }
    else if(d == 4)
    {
        card_trans = "4";
    }
    else if(d == 5)
    {
        card_trans = "5";
    }
    else if(d == 6)
    {
        card_trans = "6";
    }
    else if(d == 7)
    {
        card_trans = "7";
    }
    else if(d == 8)
    {
        card_trans = "8";
    }
    else if(d == 9)
    {
        card_trans = "9";
    }
    else if(d == 10)
    {
        card_trans = "10";
    }
    else if(d == 11)
    {
        card_trans = "Jack";
    }
    else if(d == 12)
    {
        card_trans = "Queen";
    }
    else
    {
        card_trans = "King";
    }
    return card_trans;
}

// TODO: create a determine_prize function to determine what the player wins
//         the function takes the two numerical values of the card and returns
//         a string stating 'large prize', 'small prize' or 'nothing'
string determine_prize(int card1, int card2)
{
    string prize;
    if(card1 == card2)
    {
        prize = "You win the large prize!";
    }
    else if(card1 == 11 || card2 == 11)
    {
        prize = "You win the small prize!";
    }
    else
    {
        prize = "Sorry you win nothing!";
    }
    return prize;
}

int main()
{
    // TODO: Ranges for random, some based on other constants
    const int MIN_CARDS = 1;
    const int MAX_CARDS = 13;
    const int MIN_SUIT = 1;
    const int MAX_SUIT = 4;


    // Game variables
    int first_card_num, second_card_num;
    int first_card_type, second_card_type;
    string card_num, card_type, prize;

    // TODO: Seed the random number generator
    srand(time(NULL));


    // TODO: Draw first card
    first_card_num = random_number(MIN_CARDS, MAX_CARDS);
    first_card_type = random_number(MIN_SUIT, MAX_SUIT);
    second_card_type = random_number(MIN_SUIT, MAX_SUIT);


    // TODO: do-Keep drawing second card while-it is the same as first
    do
    {
        second_card_num = random_number(MIN_CARDS, MAX_CARDS);
    }
    while(second_card_num == first_card_num);



    // TODO: Translate the card number and type into strings using functions
    card_num = translate_card_number(first_card_num);
    card_type = translate_card_type(first_card_type);
    


    // TODO: Output first card to user
    // HINT: two cases, face card and not
    cout << "You drew a "
         << card_num
         << " of "
         << card_type
         << "."
         << endl;

    
    // TODO: Translate the card number and type into strings using functions
    card_num = translate_card_number(second_card_num);
    card_type = translate_card_type(second_card_type);

    
    // TODO: Output first card to user
    // HINT: two cases, face card and not
    cout << "You drew a "
         << card_num
         << " of "
         << card_type
         << "."
         << endl;
     
 
    // TODO: Output winnings, using string returned by prize function
    cout << determine_prize(first_card_num, second_card_num)
         << endl;
 
    return 0;
}


// s = "0123456789"
// "0" "1"
//string convert(int i)
//{
    //return s.substr(i,1)
//}
