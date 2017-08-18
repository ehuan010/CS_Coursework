#include <iostream>
using namespace std;

int main()
{
	//input users age
	double age;
	cout << "Enter your age: ";
	cin  >> age;
	
	//calculation for lower and upper heart rate limit in beats per minute
	double lower_limit = (220-age)*(3.0/5.0);
	double upper_limit = (220-age)*(3.0/4.0);
	cout << "Your target heart rate is between " 
	     << lower_limit
	     << " and "
	     << upper_limit
	     << " bpm."
	     << endl;
	return 0;
}
