#pragma GCC optimize(3)
#include <iostream>

void Solution() {
  int low = 0, high = 1000;
  while (low < high) {
    int mid = low + ((high - low) >> 1);
    std::cout << "? " << mid << " " << mid << std::endl;
    int ans;
    std::cin >> ans;
    if (ans == mid * mid) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  std::cout << "! " << low << std::endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  int _T = 1;
  std::cin >> _T;
  while (_T--) {
    Solution();
  }
  return 0;
}
