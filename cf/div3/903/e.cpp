#pragma GCC optimize(3)
#include <iostream>
#include <vector>
constexpr int INF = 0x3f3f3f3f;
#define endl "\n"
int n;

void Solution() {
  std::cin >> n;
  std::vector<int> v(n+2), dp(n+2);
  for (int i = 1; i <= n; ++i)
    std::cin >> v[i];
  dp[n] = 1;
  for (int i = n-1; i; --i) {
    int cur = v[i] + i + 1;
    dp[i] = std::min(dp[i+1] + 1, (cur > n+1 ? INF : dp[cur]));
  }
  std::cout << dp[1] << endl;
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
