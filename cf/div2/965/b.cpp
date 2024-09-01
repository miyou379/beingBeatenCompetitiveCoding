#include <iostream>
#include <vector>
void Solution() {
  int n;
  std::cin >> n;
  std::vector<int> v(n+1);
  for (int i = 1; i <= n; ++i) std::cin >> v[i];
  std::cout << v[n];
  for (int i = 1; i < n; ++i) std::cout << " " << v[i];
  std::cout << "\n";
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  int _T = 1;
  std::cin >> _T;
  while (_T--) {
    Solution();
  }
  return 0;
}
