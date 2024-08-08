#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>

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
  for (int i = 0; i < 3; ++i) {
    std::cin.get();
    int a = 1, b = 1, c = 1;
    for (int j = 0; j < 3; ++j) {
      char ch = std::cin.get();
      if (ch == 'A') --a;
      if (ch == 'B') --b;
      if (ch == 'C') --c;
    }
    if (a) std::cout << 'A' << endl;
    if (b) std::cout << 'B' << endl;
    if (c) std::cout << 'C' << endl;
  }
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  std::cin >> _T;// std::cin.get();
  // std::scanf("%d", &_T); std::getchar();
  
  while (_T--) {
    Solution();
  }
  
  return 0;
}
