#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> get_initial_table(int W, int N) {
  vector<vector<int>> wn_weights;

  // value(0, j) <- 0
  vector<int> w0;
  
  for (int i = 0; i <= N; i++) {
    w0.push_back(0);
  }
 
  wn_weights.push_back(w0);


  // value(w, 0) <- 0
  for (int i = 1; i <= W; i++) {
    wn_weights.push_back({0});
  }
  
  return wn_weights;
}

int optimal_weight(int W, const vector<int> &items) {
  int N = items.size();
  
  auto dp_table = get_initial_table(W, N);

  for (int i = 1; i <= N; i++) {
    int wi = items[i - 1];

    for (int w = 1; w <= W; w++) {
      vector<int>& w_weights = dp_table[w];

      int weight_without_i = w_weights[i - 1];
      
      w_weights.push_back(weight_without_i);

      if (wi <= w) {
        int weight_with_i = dp_table[w - wi][i - 1] + wi;
        if (w_weights[i] < weight_with_i) {
          w_weights[i] = weight_with_i;
        }
      }
    }
  }
  return dp_table[W][N];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
