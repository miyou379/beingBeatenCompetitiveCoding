#pragma GCC optimize(3)
#include <cstdio>
#include <cstdint>
#include <vector>
using i64 = int64_t;
#define endl "\n"

void Solution() {
  i64 h;
  int n;
  std::scanf("%lld%d", &h, &n);
  std::vector<int> a(n+2), c(n+2);
  for (int i = 1; i <= n; ++i) std::scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) std::scanf("%d", &c[i]);
  i64 l = 1, r = 1e12;
  while (l < r) {
    i64 t = l + ((r - l) >> 1);
    i64 tot = 0;
    for (int i = 1; i <= n && tot < h; ++i) tot += ((t-1) / c[i] + 1) * a[i];
    if (tot >= h) r = t;
    else l = t + 1;  // lower_bound
  }
  std::printf("%lld\n", l);
}

signed main(void) {
  int _T = 1;
  std::scanf("%d", &_T); std::getchar();
  
  while (_T--) {
    Solution();
  }
  
  return 0;
}
