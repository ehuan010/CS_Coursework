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
// Assignment: Assignment 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     cout << fixed
          << setprecision(2);
          
     //input name and incomes
     cout << "Enter person's name (last,first): ";
     string lname_fname;
     cin >> lname_fname;
     
     cout << "Enter January income: ";
     double jan_income;
     cin >> jan_income;
     
     cout << "Enter February income: ";
     double feb_income;
     cin >> feb_income;
     
     cout << "Enter March income: ";
     double mar_income;
     cin >> mar_income;
     
     cout << endl;
     
     cout << "Quarterly statement of earnings"
          << endl;
          
     cout << endl;
     
     //variables to output first and last name
     int comma = lname_fname.find(",");
     string fname = lname_fname.substr(comma+1);
     string lname = lname_fname.substr(0,comma);
     fname = "First name : "+ fname;
     
     //outputted code
     //line1
     cout << left
          << setw(30)
          << fname
          << "Last name : "
          << setw(38)
          << lname
          << endl; 
          
     //line2
     cout << setw(80) << setfill('=') << "";
     cout << setfill(' ');
     
     //line3
     cout << setw(30)
          << "January income"
          << setw(30)
          << "February income"
          << setw(20)
          << "March income"
          << endl;
          
     //line4
     cout << setw(30)
          << jan_income
          << setw(30)
          << feb_income
          << setw(20)
          << mar_income
          << endl;
          
     //line5
     cout << setw(80) << setfill('=') << "" << endl;
     cout << setfill(' ');
          
     //line6
     cout << setw(30)
          << "Total gross income"
          << setw(30)
          << "Income tax"
          << setw(20)
          << "Total net income"
          << endl;
          
     //calculation of total gross income, income tax, total net income
     double total_gross_income = jan_income + feb_income + mar_income;
     double income_tax = (total_gross_income*15)/100.00;
     double total_net_income = total_gross_income - income_tax;
     
     //line7
     cout << setw(30)
          << total_gross_income
          << setw(30)
          << income_tax
          << setw(20)
          << total_net_income
          << endl;
     
     return(0);
}

