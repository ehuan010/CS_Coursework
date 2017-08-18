#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "sorting.h"
#include "utils.h"

using namespace std;

void write_test(const vector<int> &v_orig, unsigned test_index) {
  ostringstream oss;
  oss << "test_case_" << test_index;
  string out_file_name = oss.str();
  ofstream out_file(out_file_name.c_str(), ios::out);

  unsigned size = v_orig.size();
  for (unsigned i = 0; i < size; i++) {
    out_file << v_orig[i] << " ";
  }

  out_file.close();
}

void test(unsigned size, int test_index, int type) {
  vector<int> v;
  
  switch(type) {
  case 0:
    generate_unique_random_set(v, size);
  case 1:
    generate_ascending_set(v, size);
  case 2:
    generate_descending_set(v, size);
  }
  
  write_test(v, test_index);
}

void run_tests() {
  vector<int> sizes_to_test;
  sizes_to_test.push_back(100);
  sizes_to_test.push_back(163);
  sizes_to_test.push_back(228);
  sizes_to_test.push_back(467);
  sizes_to_test.push_back(697);
  sizes_to_test.push_back(1001);

  int n = sizes_to_test.size();

  int types[] = {0, 1, 2};

  int test_index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      test(sizes_to_test[i], test_index, types[j]);
      test_index++;
    }
  }
}

int main(){
  run_tests();
  return -1;
}
