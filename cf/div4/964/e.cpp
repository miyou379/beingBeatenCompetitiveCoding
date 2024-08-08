#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <cmath>
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
const long double mul = 1 / log2(3);
i64 qpow(i64 x, int y) {
  i64 ans = 1;
  while (y) {
    if (y & 1) ans *= x;
    x *= x;
    y >>= 1;
  }
  return ans;
}

int radix(int x) {
  int r = int(log2(x) * mul + 0.5);
  if (qpow(3, r) > x) return r;
  if (qpow(3, r+1) > x) return r+1;
  if (qpow(3, r+2) > x) return r+2;
  return r;
}

void Solution() {
  int l, r;
  std::cin >> l >> r;
  int i = l+1, rad = radix(l);
  i64 sum = 0;
  sum += 2 * rad;
  while (i <= r) {
    int right = qpow(3, rad);
    if (i < right) {
      int jump = std::min(right, r+1);
      sum += (jump - i) * rad;
      i = right;
      ++rad;
    } else {
      rad = radix(i);
    }
  }
  std::cout << sum << endl;
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
