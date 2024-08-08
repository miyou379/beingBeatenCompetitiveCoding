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
  i64 n, m;
  std::cin >> n >> m;
  std::vector<i64> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  int i = 0, j = 0;
  i64 sum = 0, ans = 0;
  std::sort(v.begin(), v.end());
  while (i < n && j <= n) {  // [i, j)
    if (sum > m || v[j] > v[i]+1) {
      sum -= v[i++];
    } else if (sum < m) {
      sum += v[j++];
    }
    if (sum == m) { std::cout << m << endl; return; }
    if (sum < m) ans = std::max(sum, ans);
  }
  std::cout << ans << endl;
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
