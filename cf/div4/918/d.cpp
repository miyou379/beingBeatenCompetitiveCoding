#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
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


void Solution() {
  int len;
  std::string s;
  std::cin >> len >> s;
  std::vector<int> v(len+1);
  int id = 1;
  bool cur = 0;  // bcd
  for (int i = 0; i < len; ++i) {
    bool f = (s[i] == 'a' || s[i] == 'e');
    if (f == cur) v[i] = id;
    else { cur = f; v[i] = ++id; }
  }
  bool f = id % 2;
  int end = f ? id-2 : id-1;
  int cr = 0;
  for (int i = 1; i <= id; ++i) {
    while (cr < len && v[cr] == i || v[cr] == i+1) std::cout << s[cr++];
    if (i == end && f) {
      while (cr < len && v[cr] == i+2) std::cout << s[cr++];
    }
    if (i != end) std::cout << '.';
    if (i == end && f) i += 2;
    else i += 1;
  }
  std::cout << endl;
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
