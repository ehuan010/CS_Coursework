 #include <iostream>
 #include <vector>
 #include <cstdlib>
 #include <ctime>
 
 using namespace std;
 
 const int SENTINEL = -1;
 
 
 int search(vector<int> &values, int number)
 {
   for(int i = 0; i < values.size(); i++)
   {
     if(number == values[i])
     {
       return i;
     }
   }
   return SENTINEL;
 }
 
 void remove(vector<int>& values, int number)
 {
   if(search(values, number) != SENTINEL)
   {
     cout << "The number was found and removed." << endl;
     for(int i = search(values, number); i < values.size() - 1; i++)
     {
       values[i] = values[i+1];
     }
     values.pop_back();
     for(int j = 0; j < values.size(); j++)
     {
       cout << values[j] << " ";
     }
     cout << endl;
    }
   else
   {
     cout << "The number was not found and not removed." << endl;
   }
 }
 
 int main()
 {
   srand(time(NULL));
   vector<int>values(20);
   int random = rand()% (100 - 0 + 1);
   for(int i = 0; i < values.size(); i++)
   {
     values[i] = random;
     random = rand()% (100 - 0 + 1);
     cout << values[i] << " ";
   }
   
   cout << endl << "What number do you want to remove?(0-100) " << endl;
   int number;
   cin >> number;
   
   remove(values, number);
   
   return 0;
 }
