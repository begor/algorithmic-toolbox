#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

bool is_majority(vector<int> &a, int left, int right, int x) {
  int n_over_2 = (right - left) / 2;

  int count = std::count(a.begin() + left, a.begin() + right, x);

  return count > n_over_2;
}


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];

  int median = (left + right - 1) / 2;

  int lmajority = get_majority_element(a, left, median);
  int rmajority = get_majority_element(a, median + 1, right);

  if (lmajority != -1 && is_majority(a, left, right, lmajority)) {
    return lmajority;
  } 

  if (rmajority != -1 && is_majority(a, left, right, rmajority)) {
    return rmajority;
  }

  return -1;  
}

int main() {
  int n; 
  std::cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
