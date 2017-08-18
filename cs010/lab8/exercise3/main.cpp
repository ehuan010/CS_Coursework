#include <iostream>

using namespace std;

void find_digits(int value, int& val1, int& val2, int& val3)
{
  val1 = value / 100;
  val2 = (value % 100) / 10;
  val3 = ((value % 100) % 10); 
}

int main()
{
  int value, val1, val2, val3;
  cout << "Enter an integer(0-999) ";
  cin >> value;

  while(value >= 0)
  {
    
    if(value > 999)
    {
      cout << "Invalid input: try again.\n"
           << "Enter an integer(0-999): ";
      cin >> value;
      find_digits(value, val1, val2, val3);
      cout << val1 << " " << val2 << " " << val3 << endl;
    }
    else
    {
      find_digits(value, val1, val2, val3);
      cout << val1 << " " << val2 << " " << val3 << endl;
    }
    cout << "Enter an integer(0-999): ";
    cin >> value;
  }
  
  return 0;
}


