#pragma GCC optimize(3)
#include <iostream>

void Solution() {
  int low = 0, high = 1000, ans;
  while (low < high) {
    int lmid = low + (high - low) / 3;
    int rmid = high + (low - high) / 3;
    std::cout << "? " << lmid << " " << rmid << std::endl;
    std::cin >> ans;
    if (ans == lmid * rmid) {
      low = rmid + 1;
    } else if (ans == (lmid + 1) * (rmid + 1)) {
      high = lmid;
    } else if (ans == lmid * (rmid + 1)) {
      low = lmid + 1;
      high = rmid;
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
