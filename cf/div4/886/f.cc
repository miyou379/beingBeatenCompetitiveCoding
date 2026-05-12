#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  int n;
  cin >> n;

  map<int, i64> pos;
  for (int i = 1; i <= n; ++i) {
    int ai;
    cin >> ai;
    ++pos[ai];
  }

  vector<i64> cnt(n + 1);
  for (int p = 1; p <= n; ++p) {
    for (int i = 1; i * i <= p; ++i) {  // the first factor
      if (p % i != 0) continue;
      int j = p / i;
      cnt[p] += pos[i];
      if (i != j) cnt[p] += pos[j];
    }
  }

  i64 mx = 0;
  for (int i = 1; i <= n; ++i)
    mx = max(mx, cnt[i]);
  cout << mx << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _T = 1;
  cin >> _T;

  while (_T--)
    solve();
}
