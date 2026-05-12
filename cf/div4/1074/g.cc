#include <bits/stdc++.h>
// using namespace std;
using i64 = long long;
using i128 = __int128;

// Global variables/functions are declared here.
int find_mex(std::vector<int> &v) {
  int n = v.size(), mex = 0;

  for (int i = 0; i < n; ++i) {
    auto &x = v[i];
    while (x >= 0 && x < n) {
      auto &y = v[x];
      if (x == y) break;
      std::swap(x, y);
    }
  }

  while (mex < n && v[mex] == mex) ++mex;
  return mex;
}

void solve(void) {
  int n;
  std::cin >> n;

  auto G = std::vector(n + 1, std::vector<int>());

  for (int i = 1; i <= n; ++i) {
    int len;
    std::cin >> len;

    while (len--) {
      int x;
      std::cin >> x;
      G[i].emplace_back(x);
    }
  }

  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = )
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