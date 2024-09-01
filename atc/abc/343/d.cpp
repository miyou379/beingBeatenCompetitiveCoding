#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
using uint = uint32_t;
using  i64 =  int64_t;
using  u64 = uint64_t;
using i128 = __int128;
constexpr double eps = 1e-7;
constexpr    int INF = 0x3f3f3f3f;
constexpr    int  M1 = 1000000007;
constexpr    int  M2 = 998244353;
#define endl "\n"


void Solution() {
  int n, t;
  std::cin >> n >> t;
  std::map<i64, int> sc;
  std::vector<i64> pla(n+1);
  sc[0] = n;
  for (int i = 1; i <= t; ++i) {
    int a, b;
    std::cin >> a >> b;
    i64 &q = pla[a];
    --sc[q];
    if (!sc[q]) sc.erase(q);
    q += b;
    ++sc[q];
    std::cout << sc.size() << endl;
  }
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  // std::cin >> _T; std::cin.get();
  // std::scanf("%d", &_T); std::getchar();
  
  while (_T--) {
    Solution();
  }
  
  return 0;
}
