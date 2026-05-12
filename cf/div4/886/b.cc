#include <bits/stdc++.h>
using namespace std;

void solve() {
  pair<int, int> wisdom{-1, -1};

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;

    if (a > 10) continue;
    if (b > wisdom.second) wisdom = {i, b};
  }

  cout << wisdom.first << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _T = 1;
  cin >> _T;

  while (_T--)
    solve();
}
