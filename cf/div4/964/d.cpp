#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>

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
  std::string s, t;
  std::cin >> s >> t;
  int i = 0, j = 0;
  while (i < s.length() && j < t.length()) {
    if (s[i] == '?' || s[i] == t[j]) {
      s[i] = t[j];
      ++i;
      ++j;
    } else if (s[i] != t[j]) {
      ++i;
    }
  }
    if (j == t.length()) {
      for (auto &c : s) {
        if (c == '?') c = 'a';
      }
      std::cout << "Yes\n" << s << endl;
    } else {
      std::cout << "No" << endl;
    }
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
