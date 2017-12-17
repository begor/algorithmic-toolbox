#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using std::vector;
using std::swap;
using std::pair;


pair<int, int> partition(vector<int> &a, int l, int r) {
  int x = a[l];
  int m1 = l, m2 = l;
  
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      m1++;
      m2++;
      
      swap(a[m1], a[m2]);
      
      if (i != m2) {
        swap(a[i], a[m1]);
      }
    } else if (a[i] == x) {
      m2++;
      
      swap(a[i], a[m2]);
    }
  }

  swap(a[l], a[m1]);

  return std::make_pair(m1, m2);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  
  swap(a[l], a[k]);
  
  pair<int, int> ms = partition(a, l, r);

  randomized_quick_sort(a, l, ms.first - 1);
  randomized_quick_sort(a, ms.second + 1, r);
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
