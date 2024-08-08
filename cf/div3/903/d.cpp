#pragma GCC optimize(3)
#include <iostream>
#include <cstdint>
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
const char *ans[] = { "NO", "YES" };
std::map<int, int> pr;
void breakdown(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      while (x % i == 0) {
        x /= i;
        ++pr[i];
      }
    }
  }
  if (x != 1) ++pr[x];
}

void Solution() {
  pr.clear();
  int n;
  i64 avg = 1, sum = 0;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    std::cin >> tmp;
    breakdown(tmp);
  }
  /* for (auto &p : pr) {
    std::cout << p.first << ":" << p.second << " ";
  }
  std::cout << endl; */
  for (auto &p : pr) {
    int num = p.second;
    if (num % n) {
      std::cout << ans[0] << endl;
      return;
    }
  }
  std::cout << ans[1] << endl;
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
