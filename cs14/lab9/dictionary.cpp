#include "dictionary.h"
#include <iostream>

template <class HashFunction> 
Dictionary<HashFunction>::Dictionary(HashFunction hf) {
  capacity = 6151;
  entries = new pair< int,string > [capacity];
  for(int i=0; i < capacity; i++) entries[i].first = UNDEFINED;
  hashFunction = hf;
}

template <class HashFunction> 
Dictionary<HashFunction>::~Dictionary() {
  delete[] entries;
}

template <class HashFunction> 
string Dictionary<HashFunction>::find(int key) 
{
		int i = 0;
	    int pos = (key + i) % capacity;
	    while(entries[pos].first != key) 
	    {
				i++;
				pos = (key + i) % capacity;
				if(entries[pos].first == UNDEFINED) break;
		}
		if(entries[pos].first == key) return entries[pos].second;
  return "";
}

template <class HashFunction> 
void Dictionary<HashFunction>::add(int key,string value) 
{
	pair<int,string> entry(key, value);
	int i = 0;
	int pos = (key + i) % capacity;
	if(pos == UNDEFINED)
		entries[pos] = entry;
	else{
		while(pos == UNDEFINED)
		{
			 i++;
			 pos = (key + i) % capacity;
		}
		entries[pos] = entry;
	}
}
/*
 int main() {
   Dictionary<Naive> x(naive);
  
   x.add(17, "b");
   x.add(2 , "c");
   x.add(16, "e");
   x.add(34 ,"d");
   x.add(1 , "a");

   cout << x.find(1) << endl;
   cout << x.find(17) << endl;
   cout << x.find(2) << endl;
   cout << x.find(16) << endl;
   cout << x.find(34) << endl;

 

*/

int main () {

  Dictionary<Naive> x(naive);
  

  string line;
  ifstream myfile ("patents707.txt");
  if (myfile.is_open())
  {
    int r = 0;
    while ( myfile.good() )
    {
      getline (myfile,line);
      if (line.length() > 7) {
	int pos = line.find("\t"); 
	string sid =  line.substr(0,pos);
	int id = atoi(sid.c_str());
	string  title =  line.substr(pos);
	cout <<  id << "[" << title <<  "]" << endl;
	x.add(id, title);
	if (r > 2500) break;
	r++;
      }
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  cout << x.find(1) << endl;
  cout << x.find(3325264) << endl;
  cout << x.find(3421092) << endl;
  cout << x.find(3625505) << endl;
  cout << x.find(3651798) << endl;


  return 0;
}
