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
// Assignment: Assignment 2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include <iostream>
using namespace std;

int main()
{
     //declare variables for the words that will be inputed by user
     string grade;
     string tv_series;
     string main_char;
     string name;
     string place;
     string verb;
     string noun;
     string noun_two;
     string verb_ing;
     string noun_three;
     int year;
     string verb_ed;
     string adjective;
     int whole_number;
     string animal;
     string noun_four;
     
     //ask user to input words for the declared variables
     cout << "Enter school grade: ";
     cin >> grade;
     
     cout << "Enter name of a tv series: ";
     cin >> tv_series;
     
     cout << "Enter name of character: ";
     cin >> main_char;
     
     cout << "Enter another name: ";
     cin >> name;
     
     cout << "Enter a place: ";
     cin >> place;
     
     cout << "Enter a verb: ";
     cin >> verb;
     
     cout << "Enter a noun: ";
     cin >> noun;
     
     cout << "Enter another noun: ";
     cin >> noun_two;
     
     cout << "Enter a verb ending in -ing: ";
     cin >> verb_ing;
     
     cout << "Enter a noun: ";
     cin >> noun_three;
     
     cout << "Enter a year: ";
     cin >> year;
     
     cout << "Enter a verb ending in -ed: ";
     cin >> verb_ed;
     
     cout << "Enter an adjective: ";
     cin >> adjective;
     
     cout << "Enter a whole number: ";
     cin >> whole_number;
     
     cout << "Enter name of an animal: ";
     cin >> animal;
     
     cout << "Enter a noun: ";
     cin >> noun_four;
     
     //output user inputted words into story
     //paragraph 1
     cout << "     When I was in the " 
          << grade
          << " grade I started watching a\ntelevision series called "
          << tv_series
          << "."
          << " The main character's\nname is "
          << main_char
          << " and he has a Pokemon called "
          << name
          << "\nthat follows him around. "
          << "Pokemon usually tend to stay in\ntheir "
          << place
          << " but his "
          << name
          << " is a rebel."
          << " He traveled\nthe world of Pokemon hoping to "
          << verb
          << " them all, but that\nnever actually happens."
          << endl;
     cout << endl;   
     //paragraph 2  
     cout << "     On his journey he meets a "
          << noun
          << " named Misty and a\n"
          << noun_two
          << " named Brock."
          << " They end up "
          << verb_ing
          << " the Pokemon\nworld together through a few seasons "
          << "of the show, before\nleaving him."
          << " He continues his quest of becoming a Pokemon\n"
          << noun_three
          << ", but no one cares anymore because the "
          << year
          << "\ngeneration of Pokemon look like "
          << verb_ed
          << " Digimon."
          << endl;
     cout << endl;     
     //paragraph 3
     cout << "     The most "
          << adjective
          << " thing about the show though is why\n"
          << main_char
          << " does not age with us."
          << " It has been about "
          << whole_number
          << "\nyears since the series began and it seems like Pokemon\n"
          << "follows "
          << animal
          << " years."
          << " It may be just a "
          << noun_four
          << ", but\nit makes absolutely no sense!"
          << endl;
     
     return 0;
}
