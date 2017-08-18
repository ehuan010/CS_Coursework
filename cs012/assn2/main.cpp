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

//Tell program to use standard namespace
using namespace std;

//tests the default constructor
void test1()
{
     cout<<"1. Default"<<endl;
     Date x=Date();
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
     cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }
 
 //tests when everything entered is correct (constructor w/ int) 
 void test2()
 {
     cout<<"2. Numeric Date: 7.3.1991"<<endl;
     Date x=Date(7,3,1991);
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
     cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }    
 
 //tests when everything entered is correct (constructor w/ string)
 void test3()
 {
     cout<<"3. Alpha Date: July 3, 1991"<<endl; 
     Date x = Date("July",3,1991);
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
      cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }
 
 //tests when invalid numerical month is entered
 void test4()
 {
     cout<<"4. Invalid Numeric1: 0.3.1991 -> 1.3.1991"<<endl;
     Date x=Date(0,3,1991);
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
     cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }
 
 //tests when invalid number is entered for month and day
 void test5()
 {
     cout<<"5. Invalid Numeric1: 60.-10.1991 -> 12.1.1991"<<endl;
     Date x=Date(60,-10,1991);
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
     cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }
 
 //tests when month is entered as an invalid string
 void test6()
 {
     cout<<"6. Invalid Alpha1: dog.12.1900 -> January.1.1900"<<endl;
     Date x=Date("dog",12,1991);
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
     cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }
 
 //tests when month is lowercase
 void test7()
 {
     cout<<"7. Invalid Alpha2: february.12.1991 -> February.12.1991"<<endl;
     Date x=Date("february",12,1991);
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
     cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }
 
 //tests when day and month numbers are wrong
 void test8()
 {
     cout<<"8. Invalid Numeric2: -1.50.1991 -> 1.31.1991"<<endl;
     Date x=Date(-1,50,1991);
     cout<<"numeric:\t" ;
     x.print_numeric();
     cout<<endl;
     cout<<"alpha:\t";
     x.print_alpha();
     cout<<endl;
     cout<<"-------------"<<endl;
 }
 
 int main()
 {
   //run the test harness
   test1();
   test2();
   test3();
   test4();
   test5();
   test6();
   test7();
   test8();
   return 0;
 }

