#include <iostream>
#define endl "\n"

void Solution() {
  int n, lines = 0, rows = 0;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin.get();
    int f1 = 0;
    for (int j = 1; j <= n; ++j) {
      char c = std::cin.get();
      if (c == '1') ++f1;
    }
    if (f1) ++rows;
    lines = std::max(lines, f1);
  }
  if (lines == rows) std::cout << "SQUARE" << endl;
  else std::cout << "TRIANGLE" << endl;
}

signed main() {
  std::ios::sync_with_stdio(false);
  int _T = 1;
  std::cin >> _T;
  while (_T--) {
    Solution();
  }
  return 0;
}
