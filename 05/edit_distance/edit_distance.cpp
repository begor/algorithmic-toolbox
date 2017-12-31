#include <iostream>
#include <string>
#include <algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  int D[str1.size()+1][str2.size()+1]; // Extra row and col for zeroes.

  for (int i = 0; i <= str1.size(); i++) {
    D[i][0] = i;
  }

  for (int j = 0; j <= str2.size(); j++) {
    D[0][j] = j;
  }

  for (int j = 1; j <= str2.size(); j++) {
    for (int i = 1; i <= str1.size(); i++) {
        int ins = D[i][j-1] + 1;
        int del = D[i-1][j] + 1;
        int match = D[i-1][j-1];
        int mismatch = D[i-1][j-1] + 1;

        if (str1[i-1] == str2[j-1]) {
            D[i][j] = std::min({ins, del, match});
        } else {
            D[i][j] = std::min({ins, del, mismatch});
        }
    }
  }

  return D[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
