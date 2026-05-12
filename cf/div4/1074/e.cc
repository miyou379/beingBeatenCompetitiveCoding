#include <bits/stdc++.h>
// using namespace std;
using i64 = long long;
using i128 = __int128;

// Global variables/functions are declared here.


void solve(void) {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> a(n), b(m);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;

  std::string ins;
  std::cin >> ins;

  std::map<int, std::set<int>> diff;
  std::sort(b.begin(), b.end());

  for (int i = 1; i <= n; ++i) {
    int x = a[i - 1];
    auto it = std::upper_bound(b.begin(), b.end(), x);
    if (it == b.end()) {
      int offs = *std::prev(it) - x;
      diff[offs].insert(i);
    } else if (it == b.begin()) {
      int offs = *it - x;
      diff[offs].insert(i);
    } else {
      int offs_l = *std::prev(it) - x,
          offs_r = *it - x;
      diff[offs_l].insert(i);
      diff[offs_r].insert(i);
    }
  }

  int offs = 0;
  std::set<int> cur;
  for (int i = 1; i <= n; ++i) cur.insert(i);
  std::map<int, bool> vis;
  for (auto c : ins) {
    if (c == 'L') {
      --offs;
      if (vis[offs] == false) {
        vis[offs] = true;
        for (auto &&to_rm : diff[offs]) {
          cur.erase(to_rm);
        }
      }
    } else {  // c == 'R'
      ++offs;
      if (vis[offs] == false) {
        vis[offs] = true;
        for (auto &&to_rm : diff[offs]) {
          cur.erase(to_rm);
        }
      }
    }
    std::cout << cur.size() << ' ';
  }
  std::cout << '\n';
}

int main(void) {
  std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);

  int _T = 1;
  std::cin >> _T;

  while (_T--) {
    solve();
  }
}