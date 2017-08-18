#ifndef _M_UTILS
#define _M_UTILS
#include <iostream>
#include <vector>
using namespace std;

int random_num(int from, int to);

void generate_unique_random_set(vector<int> &v, unsigned int n);

void generate_random_set(vector<int> &v, unsigned int n);

void generate_ascending_set(vector<int> &v, unsigned int n);

void generate_descending_set(vector<int> &v, unsigned int n);

ostream& operator<<(ostream& out, const vector<int>& v);

bool operator==(const vector<int>& v, const vector<int>& y);

#endif
