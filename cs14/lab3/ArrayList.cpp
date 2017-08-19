/**
 ** Implements the ADT list using an array.
 ** Student Names:
 **
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class ArrayList {
public:
  //Create a new vector
  ArrayList(int reserve);
  //Destructor
  ~ArrayList();
  //Return the element at index i, else return null
  string operator[](int i) const;
  //Add a new element to the end of the ArrayList
  void add(string elem);
  //Return the index of the first ocurrence, -1 if not found
  int  find(string elem);
  //Return the space that is reserved 
  int  reservedSpace() const {return reserved;};
  //Number of elements on the list
  int  size() const {return sz;};
  //Returns true if the list is empty, false if not
  bool isEmpty() const {return sz == 0;}
  //Reverse the list
  void reverse();
  //Append a second list to the end of the list, in the same order
  void append(ArrayList& v);
  //Returns a new vector that remove the duplicates
  ArrayList* makeSet();
private:
  string* data;
  int sz;
  int reserved;
};


ArrayList::ArrayList(int reserve=2) {
  data = new string[reserve];
  reserved = reserve;
  sz = 0;
}

ArrayList::~ArrayList() {
  delete[] data;
}

string ArrayList::operator[](int i) const {
  if (i >= sz) return NULL;
  else return data[i];
}


void ArrayList::add(string elem) {
  if (sz == reserved) {
    //Resize the array here
    string* temp = data;
    data = new string[2*reserved];
    reserved = 2*reserved;
    for(int i = 0; i < sz; i++)
    {
      data[i] = temp[i];
    }
  }
  data[sz] = elem;
  sz++;
}

int ArrayList::find(string elem) {
  //Add code
  return -1;
}

void ArrayList::reverse() {
  //Add code
}

void ArrayList::append(ArrayList& v) {
  //Add code
}

ArrayList* ArrayList::makeSet() {
  ArrayList* l = new ArrayList();
  //Add code
  return l;
}


ostream& operator<<(ostream& out, const ArrayList&l) {
  for (int i = 0 ; i < l.size() ; i++ ) {
    out << l[i] << " ";
  }
  return out;
}

int main() {
  
  ArrayList l;
  cout << "Testing Empty List:" << endl;
  cout << "*******************" << endl;
  cout << "is empty:" << (l.isEmpty()==true) << endl;
  cout << "size:" << (l.size() == 0) << endl;
  cout << "find a" << (l.find("a") == -1) << endl;
  l.reverse();
  l.makeSet();
  cout << "reverse and makeset: 1" << endl;


  l.add("a");
  l.add("b");
  l.add("c");
  l.add("d");
  l.add("e");

  cout << "Testing List:" << endl;
  cout << "*******************" << endl;
  cout << "is empty:" << (l.isEmpty()==false) << endl;
  cout << "size:" <<  (l.size()    == 5) << endl;
  cout << "find a" << (l.find("a") == 0) << endl;
  cout << "find b" << (l.find("b") == 1) << endl;
  cout << "find e" << (l.find("e") == 4) << endl;
  cout << "find f" << (l.find("f") == -1) << endl;
  l.reverse();
  cout << l << endl;

  cout << "Testing Append:" << endl;
  ArrayList l2;
  l2.add("a");
  l2.add("e");
  l2.add("a");
  l.append(l2);
  cout << "size:" <<  (l.size()    == 8) << endl;
  cout << l << endl;
  ArrayList& l3 = *l.makeSet();
  cout << "size:" <<  (l3.size()  == 5) << endl;
  cout << l3 << endl;
  

  ArrayList l4;
  l4.append(l2);
  l3 = *l4.makeSet();
  cout << "size:" <<  (l3.size() == 2) << endl;
  cout << l3 << endl;



}
