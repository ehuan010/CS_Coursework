#include <stdlib.h>
#include <time.h>
#include "utils.h"

static const int RANGE = 200000;

int random_num(int from, int to){
	int range = to - from + 1;
	return from + rand() % range;
}

void generate_random_set(vector<int> &v, unsigned int n){
	for(unsigned i =0;i<n;i++)
		v.push_back(random_num(-RANGE/2,RANGE/2));
}


void generate_ascending_set(vector<int> &v, unsigned int n){
	int inc = RANGE/n;
	int start = -RANGE/2;
	for(unsigned i =0;i<n;i++){
		start += random_num(1,inc);
		v.push_back(start);
	}
}

void generate_descending_set(vector<int> &v, unsigned int n){
	int inc = RANGE/n;
	int start = RANGE/2;
	for(unsigned i =0;i<n;i++){
		start -= random_num(1,inc);
		v.push_back(start);
	}
}


ostream& operator<<(ostream& out, const vector<int>& v){
	out<<"  ";
	for(unsigned i =0;i<v.size();i++){
		out<<" "<<v[i];
	}
	return out;
}

bool operator==(const vector<int>& v, const vector<int>& y){
	if(v.size()!=y.size()){
		cout<<"  Error: Sizes do not match!"<<endl;
	}

	vector<unsigned>mistakes;

	for(unsigned i =0 ;i<v.size();i++)
		if(v[i]!=y[i]) mistakes.push_back(i);

	if(mistakes.empty()) return true;

	cout<<"  Error: Element(s) does not match!"<<endl;
	for(unsigned i =0 ;i<mistakes.size();i++){
		unsigned ind = mistakes[i];
		cout<<"    index ("<<ind<<"): ["<<v[ind]<<"] != ["<<y[ind]<<"]"<<endl;
	}
	return false;

}

