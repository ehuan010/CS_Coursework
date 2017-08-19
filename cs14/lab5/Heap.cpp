#include <cstdlib>
#include <iostream>

using namespace std;

template <typename Comparable> 
class BinaryHeap {
public:
  //Constructor & Destructor
  BinaryHeap(int initialSize);
  ~BinaryHeap();

  // Get the minimun but do not change the heap
  const Comparable  min() const {return data[1];}
  
  // Get the minimum element on the heap 
  // Rebuilt the array to keep the heap property 
  const Comparable  extractMin();

  // Add a element on the heap. 
  void     add(const Comparable &elem);

  //All this methods are using for debugging
  void     print() const;
  int      size() const {return sz-1;};
  int      reservedSpace() const {return reserved;};
  bool     checkHeapProperty() const;
private:
  int sz;
  int reserved;
  Comparable* data;
};

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int initialSize=2) {
  data = new Comparable[initialSize];
  reserved = initialSize;
  sz = 1;
}

template <typename Comparable>
BinaryHeap<Comparable>::~BinaryHeap() {
  delete [] data;
  data = NULL;
}


template <typename Comparable>
const Comparable BinaryHeap<Comparable>::extractMin() {
	Comparable min = data[1];
	Comparable max = data[sz-1];
	
	int pos = 1;
	data[1] = max;
	sz--;
	while( pos*2 < sz ){
		if( 1+(pos*2) >= sz && data[pos*2] < max ){
			data[pos] = data[pos*2];
			data[pos*2] = max;
			pos = pos*2;
		}
		else if( data[pos*2] < data[1+(pos*2)] && data[pos*2] < max ){
			data[pos] = data[pos*2];
			data[pos*2] = max;
			pos = pos*2;
		}
		else if( data[1+(pos*2)] < max ){
			data[pos] = data[1+(pos*2)];
			data[1+(pos*2)] = max;
			pos = 1+(pos*2);
		}
		else break;
	}
	return min;
}

//Add a element on the heap
template <typename Comparable>
void BinaryHeap<Comparable>::add(const Comparable& elem) {
	//Duplicate the space on the array
	if (sz == reserved) {
		Comparable* newdata = new Comparable[reserved*2];
		for(int i = 0; i < reserved; i++) {
			newdata[i] = data[i];
		}
		reserved = reserved*2;
		delete[] data;
		data = newdata;
	}
	//Element is added in the next position
	data[sz] = elem;
	int pos = sz;
	while( data[pos] < data[pos/2] && pos > 1){
		data[pos] = data[pos/2];
		data[pos/2] = elem;
		pos = pos/2;
	}
	sz++;
}

//Print the heap
template <typename Comparable>
void BinaryHeap<Comparable>::print() const {
  for (int i = 1; i < sz; i++) {
    cout << data[i] << "\t";
  } 
  cout << endl;
}

//Check this is a valid heap
template <typename Comparable>
bool BinaryHeap<Comparable>::checkHeapProperty() const {
  for (int i = 1; i < sz/2; i++) {
    int l = 2*(i);
    int r = 2*(i)+1;
    if (data[i] > data[l] || data[i] > data[l] ) {
      cout << "invalid entries at i:" << i << " a[i]:" << data[i] << " l:" << l << " a[l]:" << data[l] << " r:" << r << " a[r]:" << data[l] << endl;  
      return 0;
    }
  } 
  return 1;
}


main() {
  int sz = 1000000;

  BinaryHeap<int> heap;
  srand(1);

  int *elems = new int[sz];
  for (int i = 0; i < sz; i++) {
    int r = rand()%(1<<25);
    heap.add(r);
    elems[i] = r;
  }
  cout << endl;

  cout << "add size:" << heap.size() << " reserved:" << heap.reservedSpace() << " Heap Property:" << heap.checkHeapProperty() << "\n";
  

  int k = heap.size();
  for (int i = 0; i < 10; i++) {
    cout << heap.extractMin() << "new size" << heap.size() << "\n";
  }
 
  return 1;
}
