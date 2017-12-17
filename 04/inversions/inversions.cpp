#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

using result = pair<long long, vector<int>>;

result merge_with_inversions_count(vector<int> &b, vector<int> &c) {
  long long number_of_inversions = 0;
  vector<int> merged;

  int bid = 0, cid = 0;

  while(true) {
    if (bid == b.size()) {
      merged.insert(merged.end(), c.begin() + cid, c.end());
      break;
    } else if (cid == c.size()) {
      merged.insert(merged.end(), b.begin() + bid, b.end());
      break;
    }

    int bel = b[bid], cel = c[cid];

    if (bel <= cel) {
      merged.push_back(bel);
      bid++;
    } else {
      number_of_inversions += (long long)(b.size() - bid);
      merged.push_back(cel);
      cid++;
    }
  }

  return std::make_pair(number_of_inversions, merged);
}

result merge_sort(vector<int> &a, int l, int r) {
  if (r <= l + 1 || a.size() == 1) {
    return std::make_pair(0, vector<int> {a[l]});
  }
  
  size_t ave = l + (r - l) / 2;
  
  result left = merge_sort(a, l, ave);
  result right = merge_sort(a, ave, r);

  result total = merge_with_inversions_count(left.second, right.second);
  total.first += left.first + right.first;

  return total;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  result r = merge_sort(a, left, right);
  
  return r.first;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
