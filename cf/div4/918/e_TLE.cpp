#pragma GCC optimize(3)
#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>
using i64 = int64_t;
using uint = uint32_t;
using ui64 = uint64_t;
using i128 = __int128;
constexpr double eps = 1e-7;
constexpr int INF = 0x3f3f3f3f;
constexpr int M1 = 1000000007;
constexpr int M2 = 998244353;
#define endl "\n"

namespace std {
// operation: a + b
template <typename T> class fenwick {
private:
  vector<T> tree;
  int size;
  inline int lowbit(int &x) { return x & -x; }

public:
  fenwick(vector<T> &data, int n) {
    tree = vector<T>(n + 1);
    size = n; // no tree[n+1], it's useless
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
};
} // namespace std

void Solution() {
  int n;
  std::cin >> n;
  // WTF this must be n/2+2, the index is in [1, n / 2 + 1]
  std::vector<i64> v1(n / 2 + 2), v2(n / 2 + 2);
  int lcur = 1, rcur = 1;
  for (int i = 1; i <= n; ++i) {
    i64 tmp;
    std::cin >> tmp;
    if (i % 2) {
      v1[lcur] = tmp + v1[lcur - 1];
      ++lcur;
    } else {
      v2[rcur] = tmp + v2[rcur - 1];
      ++rcur;
    }
  }
  std::fenwick<i64> fwk1(v1, (n + 1) / 2), fwk2(v2, n / 2);
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      int n1 = (r - l + 2) / 2, n2 = (r - l + 1) / 2;
      int x1 = l / 2 + 1, x2 = (l + 1) / 2;
      if (!(l & 1)) std::swap(n1, n2); // **
      i64 ans1 = fwk1.query(x1, x1 + n1 - 1);
      i64 ans2 = fwk2.query(x2, x2 + n2 - 1);
      if (ans1 == ans2) {
        std::cout << "YES" << endl;
        return;
      }
    }
  }
  std::cout << "NO" << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int _T = 1;
  std::cin >> _T;
  std::cin.get();
  // std::scanf("%d", &_T); std::getchar();

  while (_T--) {
    Solution();
  }

  return 0;
}
