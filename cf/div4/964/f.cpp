#pragma GCC optimize(3)
#include <iostream>
#include <cstdint>
using i64 = int64_t;
constexpr int M1 = 1000000007;
#define endl "\n"
const int maxn = 2e5+5;
i64 fac[maxn], inv[maxn];
i64 qpow(i64 base, i64 exp) {
  i64 ans = 1;
  while (exp) {
    if (exp & 1) ans = ans * base % M1;
    base = base * base % M1;
    exp >>= 1;
  }
  return ans;
}

i64 combination(int n, int k) {
  i64 c = fac[n];
  c = c * inv[k] % M1;
  c = c * inv[n-k] % M1;
  return c;
}

void Solution() {
  int n, k;
  std::cin >> n >> k;
  int ones = 0, zero = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    std::cin >> tmp;
    if (!tmp) ++zero;
    else ++ones;
  }
  i64 ans = 0;
  for (int i = 0; i <= k/2 && i <= zero; ++i) {
    int j = k - i;
    if (j > ones) continue;
    // split this and ans, or it will overflow
    i64 tmp = combination(zero, i) * combination(ones, j) % M1;
    ans = (ans + tmp) % M1;
  }
  std::cout << ans << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  fac[0] = inv[0] = fac[1] = inv[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    fac[i] = fac[i-1] * i % M1;
    inv[i] = qpow(fac[i], M1-2);
  }
  while (_T--)
      Solution();
  return 0;
}
