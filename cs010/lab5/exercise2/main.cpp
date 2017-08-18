#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     cout << fixed << setprecision(1);
     
     int planet;
     cout << "Do you want to go to the Moon or Mars?";
     cout << "(0 for the Moon, 1 for Mars): ";
     cin >> planet;
     
     int weight;
     cout << "Enter your weight: ";
     cin >> weight;
     
     const double MARS = (377/1000.0);
     const double MOON = (1/6.0);
     double mars_weight = weight * MARS;
     double moon_weight = weight * MOON;
     
     if(planet == 0)
     {
          cout << "Your weight on the Moon is "
               << moon_weight
               << endl;
     }
     else
     {
          cout << "Your weight on Mars is "
               << mars_weight
               << endl;
     }
     return(0);
}
