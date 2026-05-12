#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> fa(n + 1);
  vector<i64> w(n + 1);
  for (int i = 1; i <= n; ++i) fa[i] = i;

  auto search = [&](auto &&self, int x) -> pair<int, i64> {
    int r = x;
    i64 tot = 0;
    while (r != fa[r]) tot += w[r], r = fa[r];
    i64 res = tot;
    while (x != r) {
      int old_fa = fa[x];
      i64 old_w = w[x];
      fa[x] = r;
      w[x] = tot;
      x = old_fa, tot -= old_w;
    }
    return { r, res };
  };
  auto find = [&](int x) { return search(search, x).first; };
  auto len = [&](int x) { return search(search, x).second; };
  auto merge = [&](int x, int y, i64 d) -> bool {

    int i = find(x), j = find(y);
    if (i == j) return len(x) - len(y) == d;

    i64 q = len(x) - len(y) - d;
    fa[j] = i, w[j] = q;
    return true;
  };

  bool ok = true;
  while (m--) {
    int a, b;
    i64 d;
    cin >> a >> b >> d;

    if (!ok) continue;
    if (!merge(a, b, d)) ok = false;
  }

  if (ok) cout << "YES\n";
  else cout << "NO\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _T = 1;
  cin >> _T;

  while (_T--) {
    solve();
  }
}
