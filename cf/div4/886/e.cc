#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
  int n;
  i64 c;
  cin >> n >> c;

  vector<i64> ss(n);
  for (auto &x : ss) cin >> x;

  i64 L = 1, R = INT32_MAX;
  while (L < R) {
    i64 mid = (R - L) / 2 + L;
    i128 sum = 0;

    for (auto &s : ss)
      sum += i128(2 * mid + s) * (2 * mid + s);

    if (sum < c) L = mid + 1;
    else R = mid;
  }
  cout << L << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _T = 1;
  cin >> _T;

  while (_T--)
    solve();
}
