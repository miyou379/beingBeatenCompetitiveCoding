#pragma GCC optimize(3)
#include <iostream>
#include <vector>
#define endl "\n"

void Solution() {
  int x, cur = 0;
  std::vector<int> v(32);
  std::cin >> x;
  while (cur < 30 && x) {
    if (x & 1) {
      if (v[cur]) {
        v[cur] = 0;
        v[cur + 1] = 1;
      } else {
        if (!cur) v[0] = 1;
        else if (v[cur-1] == 1) {
          v[cur-1] = -1;
          v[cur] = 0;
          v[cur+1] = 1;
        } else {
          v[cur] = 1;
        }
      }
    }
    x >>= 1;
    ++cur;
  }
  std::cout << cur+1 << endl;
  for (int i = 0; i <= cur; ++i) std::cout << v[i] << (i == cur ? '\n' : ' ');
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
