#include <iostream>
using namespace std;

int main()
{
	//have user input dollar ammount
	float dollar;
	cout << "Enter US dollars: $";
	cin >> dollar;
	
	//convert US dollar to Euros, Yen, Rand, Rupee, and Pesos
	float euros = dollar * 0.74;
	float yen = dollar * 99.6;
	float rand = dollar * 9.07;
	float rupees = dollar * 49.90;
	float pesos = dollar * 13.83;
	
	//output coversions
	cout << "Euros: "
	     << euros
	     << endl;
	     
	cout << "Yen: "
	     << yen
	     << endl;
	     
	cout << "Rand: "
	     << rand
	     << endl;
	     
	cout << "Rupees "
	     << rupees
	     << endl;
	
	cout << "Pesos: "
	     << pesos
	     << endl;
	
	return 0;
}
