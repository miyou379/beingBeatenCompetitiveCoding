#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
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
  int n;
  std::cin >> n;
  std::vector< std::pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i].first;
  for (int i = 0; i < n; ++i) std::cin >> v[i].second;
  int scr1 = 0, scr2 = 0;
  i64 cnt[3] = {};
  for (int i = 0; i < n; ++i) {
    auto fir = v[i].first, sec = v[i].second;
    if (fir == sec) {
      ++cnt[(fir + 3) % 3];
    } else {
      int Xor = (fir ^ sec);
      // (0, 1) = 1, (0, -1) = -1, (1, -1) = -2
      if (Xor == -1) {
        // One of them increase by 0
      } else {
        if (fir == 1) scr1 += 1;
        else scr2 += 1;
      }
    }
  }
  if (scr1 < scr2) std::swap(scr1, scr2);
  int b1 = scr1 - cnt[2], b2 = scr2 + cnt[1];
  if (b1 >= b2) std::cout << b2 << endl;
  else {
    int b = b1 + b2;
    if (b >= 0) b /= 2;
    else b = (b-1)/2;
    std::cout << b << endl;
  }
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
