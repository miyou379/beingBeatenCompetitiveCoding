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

int minconv(std::map<char, int> &cnt) {
  int s = 0;
  char tar = (*cnt.rbegin()).first;
  for (auto &p : cnt) {
    char cur = p.first;
    if (cur == tar) break;
    s += (tar - cur) * p.second;
  }
  // if (s) std::cout << "target: " << tar << " = " << s << endl;
  return s;
}

void Solution() {
  int n;
  std::cin >> n;
  int sum = 0;
  std::vector<std::vector<char>> G(n+1, std::vector<char>(n+1));
  int d = 1;
  for (int i = 1; i <= n; ++i) {
    std::cin.get();
    for (int j = 1; j <= n; ++j) G[i][j] = std::cin.get();
  }
  int maxn = n / 2;
  while (d <= maxn) {
    for (int j = d; j <= n-d; ++j) {
      int a = d, b = j;
      std::map<char, int> cnt;
      for (int k = 0; k < 4; ++k) {
        ++cnt[G[a][b]];
        int ta = b, tb = n + 1 - a;
        a = ta, b = tb;
      }
      sum += minconv(cnt);
    }
    ++d;
  }
  std::cout << sum << endl;
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
