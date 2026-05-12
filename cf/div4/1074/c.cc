#include <bits/stdc++.h>
// using namespace std;
using i64 = long long;
using i128 = __int128;

// Global variables/functions are declared here.
void solve(void) {
  int n;
  std::cin >> n;

  std::vector<int> v(n);
  for (auto &x : v) std::cin >> x;

  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());

  int len = 1, mx = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i - 1] == v[i] - 1) {
      ++len;
    } else {
      mx = std::max(mx, len);
      len = 1;
    }
  }
  mx = std::max(mx, len);
  std::cout << mx << '\n';
}

int main(void) {
  std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);

  int _T = 1;
  std::cin >> _T;

  while (_T--) {
    solve();
  }
}