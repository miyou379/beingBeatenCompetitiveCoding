#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <queue>
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
struct p {
  int a, b;
  p(int a = 0, int b = 0): a(a), b(b) {}
};

struct cmp {
  bool operator() (p &x, p &y) {
    if (x.a != y.a) return x.a > y.a;
    return x.b > y.b;
  }
};

void Solution() {
  int n, k;
  i64 ans = 0;
  std::cin >> n >> k;
  std::priority_queue<p, std::vector<p>, cmp> q;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    std::cin >> a >> b;
    if (b < a) std::swap(a, b);
    q.push({a, b});
    ans += (i64)a + b;
  }
  if ((i64)k > ans) { std::cout << -1 << endl; return; }
  i64 cnt = 0, score = 0;
  while (score < k) {
    p tmp = q.top();
    q.pop();
    int a = tmp.a, b = tmp.b;
    --b;
    cnt += a;
    ++score;
    if (b < a) std::swap(a, b);
    if (a && b) q.push({a, b});
    else ++score;
  }
  std::cout << cnt << endl;
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
