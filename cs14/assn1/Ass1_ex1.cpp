#include <iostream>
#include <string>

using namespace std;


//Returns true if valid polynomial, false otherwise
bool isValid(string str1)
{
	//First loop to iterate through the given string
	for(unsigned i = 0; i < str1.length(); ++i)
	{
		if(str1[i] == '^')//Checks to see if the '^' char is used
		{
			//If '^' char is used, creates a second string consisting of
			//only characters from '^' +1 onwards
			string str2 = str1.substr(i+1);
			for(unsigned j = 0; j < str2. length(); ++j)
			{
				
				if(str2[j] == '^')
				{
					string str3 = str2.substr(j+1);
					for(unsigned k = 0; k < str3.length(); ++k)
					{
						if(str3[k] == '-' || str3[k] != '1' && str3[k] != '2'
						&& str3[k] != '3' && str3[k] != '4' && str3[k] != '5'
						&& str3[k] != '6' && str3[k] != '7' && str3[k] != '8'
						&& str3[k] != '9' && str3[k] != '*' && str3[k] != '/'
						&& str3[k] != '+' && str3[k] != '-' && str3[k] != 'n'
						&& str3[k] != ' ')
						{
							cerr << "False. String 3 failed at: " << str3[k] << endl;
							return false;
						}
					}
				}
				//If statement checks to see if a negative number is used
				//in the exponent or a number other than a whole number
				//is used
				if(str2[j] == '-' || str2[j] != '1' && str2[j] != '2'
				&& str2[j] != '3' && str2[j] != '4' && str2[j] != '5'
				&& str2[j] != '6' && str2[j] != '7' && str2[j] != '8'
				&& str2[j] != '9' && str2[j] != '*' && str2[j] != '/'
				&& str2[j] != '+' && str2[j] != '-' && str2[j] != 'n'
				&& str2[j] != ' ' && str2[j] != '^')
				{
					cerr << "False. String 2 failed at: " << str2[j] << endl;
					return false;
				}
			}
		}
		//If statement to make sure that after a number, an operator
		//or another number must be used before the variable n
		if(str1[i] == '1' || str1[i] == '2' || str1[i] == '3' ||
		str1[i] == '4' || str1[i] == '5' || str1[i] == '6' ||
		str1[i] == '7' || str1[i] == '8' || str1[i] == '9')
		{
			//If an operator or another number is not found, returns false;
			if(str1[i+1] == 'n')
			{
				cerr << "False(no operator): " << str1[i+1] << endl;
				return false;
			}
		}
		//After the variable 'n' is used, it must be followed by a math
		//operator or the '^' symbol
		if(str1[i] == 'n')
		{
			if(str1[i+1] != '*' && str1[i+1] != '-' && str1[i+1] != '+' 
			&& str1[i+1] != '/' && str1[i+1] != '^' && str1[i+1] != '\0'
			&& str1[i+1] != ' ')
			{
				return false;
			}
		}
	}
	return true;
}


int main()
{
	string str1;
	
	cout << "Input polynomial to validate: ";
	getline(cin, str1);	
	
	bool a = isValid(str1);
	cout << endl << str1;

	
	cout << endl << a << endl;
	
	
	
	return 0;
}
