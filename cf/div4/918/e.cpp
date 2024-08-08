#include <iostream>
#include <map>
#include <cstdint>
#include <cstring>
using i64 = int64_t;
#define endl "\n"
const int maxn = 2e5 + 5;
i64 v[maxn] = { 0 };
const char *ans[] = { "NO", "YES" };

void Solution() {
  int n;
  std::cin >> n;
  std::map<i64, bool> mp;
  bool ok = false;
  for (int i = 1; i <= n; ++i) {
    i64 tmp;
    std::cin >> tmp;
    if (i % 2) v[i] = v[i-1] + tmp;
    else v[i] = v[i-1] - tmp;
    if (v[i] == 0) ok = true;
    else {
      if (mp[v[i]]) ok = true;
      else mp[v[i]] = true;
    }
  }
  std::cout << ans[ok] << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  while (_T--) {
    Solution();
  }
  return 0;
}
