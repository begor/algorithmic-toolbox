#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();

  while(n--) {
    int max_idx = 0;
    double max_available = 0.0;

    for(int i = 0; i < weights.size(); i++) {
      if (weights[i] == 0) {
        continue;
      }
      
      double this_unit = (double)values[i] / (double)weights[i];

      if (this_unit >= max_available) {
        max_idx = i;
        max_available = this_unit;
      }
    }

    int use_weight = std::min(capacity, weights[max_idx]);

    value += use_weight * max_available;
    weights[max_idx] -= use_weight;
    capacity -= use_weight;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  
  vector<int> values(n);
  vector<int> weights(n);
  
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
