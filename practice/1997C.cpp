#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
using uint = uint32_t;
using  i64 =  int64_t;
using  u64 = uint64_t;
using i128 = __int128;
constexpr double eps = 1e-7;
constexpr    int INF = 0x3f3f3f3f;
constexpr    int  M1 = 1000000007;
constexpr    int  M2 = 998244353;
#define LF "\n"


void Solution() {
  int n, cur = 0;
  i64 ans = 0;
  std::cin >> n;
  std::stack<int> pos;
  std::string s;
  std::cin >> s;
  while (cur < n) {
    if (s[cur] == '_') {
      if (pos.empty()) pos.push(cur);
      else {
        int a = pos.top();
        pos.pop();
        ans += cur - a;
      }
    } else if (s[cur] == '(') pos.push(cur);
    else {
      int a = pos.top();
      pos.pop();
      ans += cur - a;
    }
    ++cur;
  }
  std::cout << ans << LF;
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
