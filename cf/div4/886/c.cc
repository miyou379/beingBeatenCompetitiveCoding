#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;

  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      char c;
      cin >> c;
      if (c == '.') continue;
      s += c;
    }
  }

  cout << s << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _T = 1;
  cin >> _T;

  while (_T--)
    solve();
}
