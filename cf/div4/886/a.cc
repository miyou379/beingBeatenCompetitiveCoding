#include <bits/stdc++.h>
using namespace std;

void solve(void) {
  int a, b, c;

  cin >> a >> b >> c;

  if (c > b) swap(b, c);
  if (b > a) swap(a, b);
  if (c > b) swap(b, c);

  if (a + b >= 10)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(void) {
  ios::sync_with_stdio(false);

  int _T = 1;
  cin >> _T;

  while (_T--)
    solve();
}
