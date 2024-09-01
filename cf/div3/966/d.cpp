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

namespace std {
// operation: a + b
template <typename T>
class fenwick {
  private:
    vector<T> tree;
    int size;
    inline int lowbit(int &x) { return x & -x; }
  public:
    fenwick(vector<T> &data, int n) {
      tree = vector<T>(n+1);
      size = n;  // no tree[n+1], it's useless
      for (int i = 1; i <= n; ++i) {
        tree[i] = data[i] - data[i - lowbit(i)];
      }
    }
    T query(int l, int r) {
      --l;
      T rsum = 0, lsum = 0;
      while (r) {
        rsum += tree[r];
        r = r - lowbit(r);
      }
      while (l) {
        lsum += tree[l];
        l = l - lowbit(l);
      }
      return rsum - lsum;
    }
    void add(int x, T val) {
      while (x <= size) {
        tree[x] += val;
        x = x + lowbit(x);
      }
    }
};
}  // namespace std

int n;
i64 score;
void div(int l, int r, std::string &s, std::fenwick<i64> &t) {
  if (l >= r) return;
  while (l <= n && s[l] != 'L') ++l;
  while (r >= 1 && s[r] != 'R') --r;
  if (l < r) {
    score += t.query(l, r);
    div(l+1, r-1, s, t);
  }
}

void Solution() {
  score = 0;
  std::cin >> n;
  std::vector<i64> v(n+1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> v[i];
    v[i] += v[i-1];
  }
  std::fenwick<i64> tree(v, n);
  std::string s;
  std::cin >> s;
  s = " " + s;
  div(1, n, s, tree);
  std::cout << score << endl;
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
