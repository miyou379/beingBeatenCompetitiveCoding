#pragma GCC optimize(3)
#include <iostream>
#include <vector>
#include <set>
#include <cstdint>
using i64 = int64_t;
#define endl "\n"


void Solution() {
  int h, n;
  std::cin >> h >> n;
  std::vector<int> a(n+1), c(n+1);
  std::set< std::pair<i64, int> > s;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) { std::cin >> c[i]; s.insert({1, i}); }
  i64 turn = 0;
  while (h > 0) {
    auto rnd = (*s.begin()).first;
    auto id = (*s.begin()).second;
    s.erase(s.begin());
    turn = rnd;
    h -= a[id];
    s.insert({rnd+c[id], id});
  }
  std::cout << turn << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  
  while (_T--) {
    Solution();
  }
  
  return 0;
}
