#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
using uint = uint32_t;
using  i64 =  int64_t;
using  u64 = uint64_t;
using i128 = __int128;
constexpr double eps = 1e-5;
constexpr    int INF = 0x3f3f3f3f;
constexpr    int  M1 = 1000000007;
constexpr    int  M2 = 998244353;
#define endl "\n"
inline bool check(i64 x) {
  std::string s = std::to_string(x);
  int len = s.length();
  int a = 0, b = len-1;
  while (a < b)
    if (s[a++] != s[b--]) return false;
  return true;
}

void Solution() {
  i64 n;
  std::cin >> n;
  i64 i = powl(n, 1.0L/3) + eps;
  for (; i >= 1; --i) {
    i64 t = i*i*i;
    if (check(t)) {
      std::cout << t << endl;
      break;
    }
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
