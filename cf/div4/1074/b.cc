#include <bits/stdc++.h>
// using namespace std;
using i64 = long long;
using i128 = __int128;

// Global variables/functions are declared here.


void solve(void) {
  int n;
  std::cin >> n;

  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;

    mx = std::max(mx, x);
  }

  std::cout << mx * n << '\n';
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