#include <iostream>
using namespace std;

int main()
{
	//declare starting account balance, account interest rate, # of years
	double account_balance;
	double interest_rate;
	double number_of_years;
	
	//input starting account balance, account interest rate, # of years
	cout << "Enter account balance: ";
	cin >> account_balance;
	cout << "Enter interest rate: ";
	cin >> interest_rate;
	cout << "Enter # of years: ";
	cin >> number_of_years;
	
	//ouput interest
	double interest_rate_percent = interest_rate / 100.0;
	double interest = account_balance * interest_rate_percent * number_of_years;
	cout << "Interest income after "
	     << number_of_years
	     << " years: $"
	     << interest
	     << endl;
	     
	return 0;
}
