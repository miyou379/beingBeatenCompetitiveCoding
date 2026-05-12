#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  sort(v.begin(), v.end());

  int mx = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || v[i] - v[i - 1] <= k) ++cnt;
    else {
      mx = max(mx, cnt);
      cnt = 1;
    }
  }
  mx = max(mx, cnt);
  cout << n - mx << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _T = 1;
  cin >> _T;

  while (_T--)
    solve();
}
