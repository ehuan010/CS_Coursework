/**
 ** Implements the ADT Set using an sorted array as backup.
 ** Student Names:
 **
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Set {
public:
  //Create a new vector
  Set(int reserve);
  //Destructor
  ~Set();
  //Add a new element to the set
  void add(int elem);
  // Returns true if the element is in the set,false otherwise
  bool exists(int elem) const;
  void printSet();
  void intersect( const Set& );
private:
  void doubleSpace();
  int binarySearch(int key, int imin, int imax) const;
  int* data;
  int sz;
  int reserved;
};


Set::Set(int reserve=1) {
  data = new int[reserve];
  reserved = reserve;
  sz = 0;
}

Set::~Set() {
  //delete[] data;
}


void Set::doubleSpace() {
    int* newdata = new int[reserved*2];
    for(int i = 0; i < reserved; i++) {
      newdata[i] = data[i];
    }
    reserved = reserved*2;
    data = newdata;
}

void Set::add(int elem) {
  if (sz >= reserved) {
    doubleSpace();
  }
  //Find where we are inserting
  int pos = -1;
	for( unsigned i = 0; i < sz; i++ ){
		if( elem < data[i] ){
			pos = i;
			break;
		}
	}
	if( pos < 0 ) pos = sz;
	
  //We return if we find the element already on the set
  if( pos == 0 ) {}
  else if( data[pos-1] == elem ) return;
  
  //We move all the elements after i 
	for( unsigned i = sz; i > pos; i-- ){
		data[i] = data[i-1];
	}
	
  //Finally we add the element and update the size
  data[pos] = elem;
  sz++;
}



bool Set::exists(int elem) const {
  //Call internal method
	if( binarySearch( elem, 0, sz-1 ) >= 0 ) return true;
	else return false;
}

int Set::binarySearch(int key, int imin, int imax) const
{
  //You can get this from wikipedia but be careful
  int mid = (imin+imax)/2;
  if( data[mid] == key ) return mid;
  if( imin >= imax ) return -1;
  
  if( data[mid] > key ) return binarySearch( key, imin, mid-1 );
  else return binarySearch( key, mid+1, imax );
}

void Set::printSet() {
  cout << "{";
  for (int i = 0; i < sz; i++) {
    cout << data[i] << " ";
  }
  cout << "}" << endl;
}

void Set::intersect( const Set& s ){
	int p1 = 0;
	int p2 = 0;
	int temp[reserved];
	int nsz = 0;
	while( p1 < sz && p2 < s.sz ){
		if( data[p1] == s.data[p2] ){
			temp[nsz] = data[p1];
			nsz++;
			p1++;
			p2++;
		}
		else if( data[p1] > s.data[p2] ) p2++;
		else p1++;
	}
	delete[] data;
	data = temp;
	sz = nsz;
}

int main() {
  srand(10);
  Set s;
  for (int i = 0; i < 10000; i++) {
    int elem = rand()%500;  
    if (elem != 0 && elem != 354 && elem != 499) s.add(elem);
    //cout << elem << ' ';
  }
  s.printSet();

  cout << "exists 1: " << s.exists(1)      << endl;
  cout << "exists 12: " << s.exists(12)    << endl;
  cout << "exists 354: " << s.exists(354)  << endl;
  cout << "exists 357: " << s.exists(357)  << endl;
  cout << "exists 498: " << s.exists(498)  << endl;
  cout << "exists 499: " << s.exists(499)  << endl;
  
  Set s2;
  s2.add( 12 );
  s2.add( 1);
  s2.add(354);
  s2.add( 493 );
  s2.add(415);
  s.intersect( s2 );
  s.printSet();
}
