#pragma GCC optimize(3)
#include <iostream>
#define endl "\n"
int big(int a, int b) {
  return int(a > b);
}

void Solution() {
  int a1, a2, b1, b2;
  std::cin >> a1 >> a2 >> b1 >> b2;
  int ans = 0;
  if ((big(a1, b1) + big(a2, b2)) > (big(b1, a1) + big(b2, a2))) ++ans;
  if ((big(a2, b1) + big(a1, b2)) > (big(b1, a2) + big(b2, a1))) ++ans;
  std::cout << ans * 2 << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  while (_T--) {
    Solution();
  }
  return 0;
}
