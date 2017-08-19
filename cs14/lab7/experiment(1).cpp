#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


void insertVector(vector< pair<int, int> >* v, int key,int value) {
  //Use push_back
  v->push_back(pair<int, int> (key,value));
}


bool searchVector(vector< pair<int, int> >* v, int key) {
  //Search with iterators
  vector< pair<int, int> >::iterator it;
  for(it = v->begin(); it != v->end();++it){
   if(it->first == key){     
    return true;
    }
  } 
  return false;
}

bool compare (pair<int, int> i, pair<int, int> j) 
{ return (i.first < j.first ); }

void sortVector(vector< pair<int, int> >* v) {
  //Use sort
  sort(v->begin(), v->end(), compare);
}

bool searchSortedVector(vector< pair<int, int> >* v,int key) {
  //Use STL Binary Search
  return binary_search(v->begin(), v->end(), pair<int,int> (key, 0), compare );
}

void insertMap(map<int, int>* m, int key,int value) {
  //Use insert function in map
  m->insert(m->begin(), pair<int, int> (key, value));
}

bool searchMap(map<int, int>* m, int key) {
  //Use the find function in map
  return m->end() != m->find(key);
}


main() {

  srand(1);
  
  vector< pair<int,int> >*   myVector = new vector< pair<int,int> >();
  vector< pair<int,int> >* mySortedVector = new vector< pair<int,int> >();
  map<int,int>* myMap = new map<int,int>();

  for(int exp = 0; exp <= 2; exp++) {
    for (int k = 16; k < 24; k++) {
      
      //Phase I: insert
      int sz = 1<<k;
      long start=clock();
      for (int i = 0; i < sz; i++) {
	int r = rand()%(1<<25);
	int v = rand()%(1<<25);
	if (exp == 0) insertVector(myVector,r,v);
	if (exp == 1) insertVector(mySortedVector,r,v);
	if (exp == 2) insertMap(myMap,r,v);
      }
      if (exp == 1) sortVector(mySortedVector);
      double diff=(clock()-start)*1000.0/(double) CLOCKS_PER_SEC;
      cout<< "Insert " << exp << " " << sz << " " << diff << endl;

      
      //Phase 2: execute 10000 search
      start=clock();
      for (int i = 0; i < 100; i++) {
	int r = rand()%(1<<24);
	if (exp == 0) searchVector(myVector,r);
	if (exp == 1) searchSortedVector(mySortedVector,r);
	if (exp == 2) searchMap(myMap,r);
      }
      diff=(clock()-start)*1000.0/(double) CLOCKS_PER_SEC;
      cout<< "Search " << exp << " " << sz << " " << diff << endl;
      
      

    } 

  }


  

}

