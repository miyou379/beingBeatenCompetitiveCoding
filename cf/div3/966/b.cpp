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
  int n;
  std::cin >> n;
  std::vector<int> v(n+2);
  for (int i = 0; i < n; ++i) std::cin >> v[i];
  int p = v[0], l = p-1, r = p+1;
  for (int i = 1; i < n; ++i) {
    bool fl = false, fr = false;
    int cur = v[i];
    if (cur == l) { --l; fl = true; }
    if (cur == r) { ++r; fr = true; }
    if (fl || fr) continue;
    else { std::cout << "No" << endl; return; }
  }
  std::cout << "Yes" << endl;
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
