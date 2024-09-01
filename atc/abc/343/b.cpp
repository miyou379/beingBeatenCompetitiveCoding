#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
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
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int tmp;
      std::cin >> tmp;
      if (j != i && tmp == 1) std::cout << j << " ";
    }
    std::cout << endl;
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