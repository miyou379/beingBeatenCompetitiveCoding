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
  i64 a, b, c;
  std::cin >> a >> b >> c;
  i64 sum = a + b + c;
  i64 tar = std::min(std::min(a, b), c);
  if (sum % tar || sum / tar > 6) { std::cout << "NO" << endl; return; }
  bool f = true;
  while (a > 0) {
    a -= tar;
    if (a % tar) f = false;
  }
  while (b > 0) {
    b -= tar;
    if (b % tar) f = false;
  }
  while (c > 0) {
    c -= tar;
    if (c % tar) f = false;
  }
  if (f) std::cout << "YES" << endl;
  else std::cout << "NO" << endl;
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
