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
// Assignment: assn2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

//Needed includes
#include <iostream>
#include "date.h"

using namespace std;
//Private Member Functions

/* Private member function for the date function that checks if it is a leap
 * year or not
 * @param y: Takes in an integer value for the year
 * @return: Returns true if it is a leap year, otherwise returns false
 */
bool Date::is_leap( int y ) const
{
  if(y % 4 == 0) //is a leap year
  {
    if(y % 100 == 0) //is not a leap year
    {
      if(y % 400 == 0) //is a leap year
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return true;
    }
  }
  else
  {
    return false;
  }
}

/* Private member function for the date function that calculates the number
 * of days in a month
 * @ param m: Takes in an integer value for the month
 * @ param y: Takes in an integer value for the year
 * @ return: Returns number of days allowed in a given month
 */
int Date::days_per_month( int m, int y ) const
{
  if(m >= 1 && m < 8) //if the month is July or before
  {
    if(m % 2 == 0 && m != 2) //if it is not feb. and is an even month
    {
      return 30; //the month will have 30 days
    }
    else if(m == 2) //if the month is feb.
    {
      if(is_leap(y)) //if it is a leap year
      {
        return 29; //the month will have 29 days
      }
      else //otherwise it isn't a leap year
      {
        return 28; //the month will have 28 days
      }
    } 
    else //if the month is an odd month 
    {
      return 31; //the month will have 31 days
    }
  }
  else if(m >= 8 && m <= 12) //if the month is August and after
  {
    if(m % 2 == 0) //if the month is even
    {
      return 31; //the month will have 31 days
    }
    else //if the month is odd
    {
      return 30; //the month will have 30 days
    }
  }
}

/* Private member function that gets the string name of a given month
 * @param m: Takes in an integer value for the month
 * @return: Returns name of a given month
 */
string Date::name( int m ) const
{
  string month; //Stores a string in month
  if(m == 1) //month 1 is January
  {
    month = "January"; //set month to January
  }
  else if(m == 2) //month 2 is Feb
  {
    month = "February"; //set month to Feb
  }
  else if(m == 3) //month 3 is march 
  {
    month = "March"; //set month to March
  }
  else if(m == 4) //month 4 is April
  {
    month = "April"; //set month to April
  }
  else if(m == 5) //month 5 is May
  {
    month = "May"; //set month 5 to May
  }
  else if(m == 6) //month 6 is June
  {
    month = "June"; //set month to June
  }
  else if(m == 7) //month 7 is July
  {
    month = "July"; //set month to July
  }
  else if(m == 8) //month 8 is August
  {
    month = "August"; //set month to August
  }
  else if(m == 9) //month 9 is Sept
  {
    month = "September"; //set month to Sept
  }
  else if(m == 10) //month 10 is Oct
  {
    month = "October"; //set month to Oct
  }
  else if(m == 11) //month 11 is Nov
  {
    month = "November"; //set month to Nov
  }
  else //otherwise set month to december
  {
    month = "December";
  }
  return month; //Returns whatever is stored in month
}

/* Private member function that gets the integer number for a given month 
 * name
 * @param mn: Pass by reference to a string that takes in a month's name
 * @return: Returns the integer for a given month
 */
int Date::number( const string &mn ) const
{
  int month; //Stores an integer for month
  if(mn == "January" || mn == "january") //month of Jan is 1
  {
    month = 1;
  }
  else if(mn == "February" || mn == "february") //month of Feb is 2
  {
    month = 2;
  }
  else if(mn == "March" || mn == "march") //month of March is 3
  {
    month = 3;
  }
  else if(mn == "April" || mn == "april") //month of April is 4
  {
    month = 4;
  }
  else if(mn == "May" || mn == "may") //month of May is 5
  {
    month = 5;
  } 
  else if(mn == "June"|| mn == "june") //month of June is 6
  {
    month = 6;
  }
  else if(mn == "July" || mn == "july'") //month of July is 7
  {
    month = 7;
  }
  else if(mn == "August" || mn == "august") //month of August is 8
  {
    month = 8;
  }
  else if(mn == "September"|| mn == "september") //month of Sept is 9
  {
    month = 9;
  }
  else if(mn == "October" || mn == "octorber") //month of Oct is 10
  {
    month = 10;
  }
  else if(mn == "November" || mn == "november") //month of Nov is 11
  {
    month = 11;
  }
  else if(mn == "December" || mn == "december") //month of Dec is 12
  {
    month = 12;
  }
  else //if none of the above is true month is given default value 0
  {
    month = 0;
  }
  return month; //return the value stored in month
}


//---------------------------------------------------------------------------
//Public Member Functions Below


//Default constructor
Date::Date( )
{
  day = 1;
  month = 1;
  year = 1900;
  month_name = "January";
}

/* Constructor with three parameters
 * @param m: Takes in the integer value for the month
 * @param d: Takes in the integer value for the day
 * @param y: Takes in the integer value for the year
 */
Date::Date( int m, int d, int y )
{
  year = y; //year is assigned whatever y is
  
  if(m > 12) //when the month is too large assign month to 12
  {
    month = 12;
  }
  else if(m < 1) //when the month is too small assign month to 1
  {
    month = 1;
  }
  else //otherwise assign month with the value of m
  {
    month = m;
  }
  
  if(d > days_per_month(month, year)) //day value too large assign day to 
  {                                   //largest possible day
    day = days_per_month(month, year);
  }
  else if(d < 1) //day value is too small assign day to 1
  {
    day = 1;
  }
  else //otherwise assign day with the value of d
  {
    day = d;
  }
  
  //if there is any problems with month or day output error message with
  //the corrected month and day
  if(d > days_per_month(month, year) || d < 1 
     || m > 12  || m < 1 ) 
  {
    cout << "\"Invalid date values: Date corrected to " << month << "/"
         << day << "/" << year << ".\"" << endl;
  }

  //call name function and pass in month to get the string type and assign it
  //to month_name
  month_name = name(month); 
}

/* Constructor with three parameters
 * @param mn: Pass by reference to a string that takes in a month's name
 * @param d: Takes in the integer value for the day
 * @param y: Takes in the integer value for the year
 */
Date::Date( const string &mn, int d, int y )
{
  if(number(mn) == 0) //if the month name is invalid assign default values
                      //and output error message
  {
    month_name = "January";
    month = 1;
    day = 1;
    year = 1900;
    cout << "\"Invalid date values: Date corrected to " << month << "/"
         << day << "/" << year << ".\"" << endl;
  }
  else //otherwise construct the object accordingly
  {
    year = y; //year is assigned with the value in y
    
    //month_name is assigned the returned string after calling the name
    //function with the argument of number function with argument mn
    month_name = name(number(mn));
    
    month = number(mn); //month is assigned the returned int from calling the
                        //number function with argument mn
    
    if(d > days_per_month(month, year)) //day value too large
    {
      day = days_per_month(month, year); //assign day to largest possible val
    }
    else if(d < 1) //day value is too small
    {
      day = 1; //assign day to smallest possible value
    }
    else //otherwise day is assigned the value of d
    {
      day = d;
    }
  }
}

// Print function that outputs the date in the format of 3/1/2010
void Date::print_numeric( ) const
{
  cout << month << "/" << day << "/" << year;
}

//Print function that outputs the date in the format of March 1, 2010
void Date::print_alpha( ) const
{
  cout << month_name << " " << day << ", " << year;
}

