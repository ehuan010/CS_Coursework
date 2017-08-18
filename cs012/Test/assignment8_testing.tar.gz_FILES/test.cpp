#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <fstream>

#include "sorting.h"
#include "utils.h"

using namespace std;

void correct_sort(vector<int> &v) {
  sort(v.begin(), v.end());
}

bool run_test(string test_file_name, int test_index) {
  ostringstream out;

  out << "Test case #" << test_index << endl;
  out << "Using file: " << test_file_name << endl;

  vector<int> v;

  ifstream in_file(test_file_name.c_str());
  int value;
  while (in_file >> value) {
    v.push_back(value);
  }
  in_file.close();
  
  vector<int> v_correct(v);
  vector<int> v_orig(v);

  merge_sort(v);
  correct_sort(v_correct);
  
  bool error = false;
  if (v != v_correct) {
    out << "\tMerge sort failed!\n";
    error = true;
  }

  unsigned size = v.size();

  for (int i = 0; i < 4; i++) {
    int correct_index = random_num(0, size-1);
    int value = v_correct[correct_index];
    int check_index = binary_search(v_correct, value);
    if (correct_index != check_index) {
      out << "\tBinary search failed: target = " << value << "\n";
      out << "\t\tExpected index: " << correct_index << ", but found " << check_index << "\n";
      error = true;
    }
  }

  int out_of_range = 2000000;
  int check_index = binary_search(v_correct, out_of_range);
  if (check_index != -1) {
      out << "\tBinary search failed: target = " << out_of_range << "\n";
      out << "\t\tExpected index: " << -1 << ", but found " << check_index << "\n";
      error = true;
  }
  out << endl;
  
  if (error) {
    cout << out.str();
  }

  return error;
}

void run_all_tests() {
  // assuming 18 test cases
  unsigned count = 18;
  bool error = false;
  for (unsigned i = 0; i < count; i++) {
    ostringstream oss;
    oss << "test_case_" << i; // change this appropriately if the tests are in some other directory
    if (run_test(oss.str(), i))
      error = true;
  }
  if (!error) {
	cout << "----------------------------------------------------" << endl;
    cout << "Success!! All test cases completed. No errors found!" << endl;
	cout << "----------------------------------------------------" << endl;
  }
}

int main(){
  run_all_tests();
  return -1;
}
