#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <vector>
using i64  =  int64_t;
using uint = uint32_t;
using ui64 = uint64_t;
using i128 = __int128;
constexpr double eps = 1e-7;
constexpr int    INF = 0x3f3f3f3f;
constexpr int    M1  = 1000000007;
constexpr int    M2  = 998244353;
#define endl "\n"
// using namespace std;

void Solution() {
  i64 s, m;
  int n;
  std::cin >> n >> s >> m;
  std::vector<std::pair<i64, i64>> v(n+2);
  
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].first >> v[i].second;
  }
  v[n].first = 0, v[n].second = 0;
  v[n+1].first = m; v[n+1].second = m;
  std::sort(v.begin(), v.end());
  for (int i = 1; i < n+2; ++i) {
    i64 gap = v[i].first - v[i-1].second;
    if (gap >= s) {
      std::cout << "YES" << endl;
      return;
    }
  }
  std::cout << "NO" << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  // std::scanf("%d", &_T); std::getchar();
  
  while (_T--) {
    Solution();
  }
  
  return 0;
}
