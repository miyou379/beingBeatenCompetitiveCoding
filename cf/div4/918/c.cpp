#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <cmath>
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
  i64 sum = 0;
  for (int i = 1; i <= n; ++i) {
    i64 tmp;
    std::cin >> tmp;
    sum += tmp;
  }
  i64 root = floor(sqrt(double(sum))+0.5);
  if (root * root == sum || (root + 1) * (root + 1) == sum || (root-1) * (root-1) == sum) std::cout << "YES" << endl;
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
