#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string>
#include <vector>
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

int n, m;
void Solution() {
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];
  std::cin >> m;
  while (m--) {
    std::string s;
    std::cin >> s;
    if (s.length() != n) { std::cout << "No" << endl; continue; }
    std::map<int, char> mp;
    std::map<char, int> pm;
    bool f = true;
    for (int i = 0; i < n; ++i) {
      int &u = v[i];
      char &c = s[i];
      bool f1 = mp.count(u), f2 = pm.count(c);
      if (!f1 && !f2) { mp[u] = c; pm[c] = u; }
      else if (f1 && !f2 && mp[u] == c) pm[c] = u;
      else if (!f1 && f2 && pm[c] == u) mp[u] = c;
      else if (f1 && f2 && mp[u] == c && pm[c] == u) {}
      else { f = false; break; }
    }
    if (f) std::cout << "Yes" << endl;
    else std::cout << "No" << endl;
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
