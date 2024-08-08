#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>

using i64 = int64_t;

void Solution() {
  int l = 1, r = 1000;
  while (true) {
    int mid = l + ((r - l) >> 1);
    if (l == mid || mid == l+1) {
      std::cout << "! " << l << std::endl;
      return;
    }
    std::cout << "? " << l << " " << mid-1 << std::endl;
    int corr = l * (mid-1);
    int resp;
    std::cin >> resp;
    if (corr == resp) {
      l = mid;
    } else {
      r = mid;
    }
  }
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  
  while (_T--) {
    Solution();
  }
  
  return 0;
}
