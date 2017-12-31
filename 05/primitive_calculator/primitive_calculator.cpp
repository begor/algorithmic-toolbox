#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using std::vector;


vector<int> optimal_sequence(int n) {
  vector<int> initial = {1};
  vector<vector<int>> dp_table = {{}, initial};

  for (int i = 2; i <= n; ++i) {
    vector<int> min_move = dp_table[i - 1];

    if (i % 3 == 0 && dp_table[i / 3].size() < min_move.size()) {
      min_move = dp_table[i / 3];
    }

    if (i % 2 == 0 && dp_table[i / 2].size() < min_move.size()) {
      min_move = dp_table[i / 2];
    }

    min_move.push_back(i);
    dp_table.push_back(min_move);
  }

  return dp_table[n];
}


int main() {
  int n;
  std::cin >> n;

  vector<int> sequence = optimal_sequence(n);

  std::cout << sequence.size() - 1 << std::endl;
  
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
