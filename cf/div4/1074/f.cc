#include <bits/stdc++.h>
#include <algorithm>
// using namespace std;
using i64 = long long;
using i128 = __int128;

// Global variables/functions are declared here.


void solve(void) {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> v(1 << n);
  for (auto &x : v) std::cin >> x;
  
  std::vector<int> g(1 << n);
  while (q--) {
    int b, c;
    std::cin >> b >> c;
    --b;

    std::iota(g.begin(), g.end(), 0);
    const auto old_val = v[b];
    v[b] = c;
    for (int _ = 0; _ < n; ++_) {  // _ rounds
      int sz = 1 << _;
      auto sum = [&](int i) {
        int res = 0;
        for (int l = i * sz, r = (i + 1) * sz; l < r; ++l) {
          res ^= v[g[l]];
        }
        return res;
      };

      auto swap = [&](int i, int j) {
        int l = i * sz, r = j * sz;
        for (int k = 0; k < sz; ++k) {
          std::swap(g[l + k], g[r + k]);
        }
      };

      for (int i = 0; i < (1 << n) / sz; i += 2) {
        int j = i + 1;
        int val_x = sum(i), val_y = sum(j);
        if (val_x >= val_y) swap(i, j);
      }
    }
    int p = 0;
    while (g[(1 << n) - 1 - p] != b) ++p;
    std::cout << p << '\n';

    v[b] = old_val;
  }
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