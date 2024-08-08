#pragma GCC optimize(3)
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#define endl "\n"
using Graph = std::vector< std::vector<int> >;
const int maxn = 2e5 + 5;
int n, k;
int d[maxn];
bool vis[maxn];

int BFS(int start, std::set<int> &flg, Graph &G) {
  int cnt = k;
  memset(d, 0, sizeof(int) * (n+2));
  memset(vis, 0, sizeof(bool) * (n+2));
  d[start] = 0;
  vis[start] = true;
  std::queue<int> q;
  q.push(start);
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (flg.count(u)) --cnt;
    for (auto &v : G[u]) {
      if (!vis[v]) {
        vis[v] = true;
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
    if (!cnt) return u;
  }
  return -1;
}

void Solution() {
  std::set<int> flg;
  Graph G(n+2);
  for (int i = 0; i < k; ++i) {
    int tp;
    std::cin >> tp;
    flg.insert(tp);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int v1 = *flg.begin();
  int v2 = BFS(v1, flg, G);
  int v3 = BFS(v2, flg, G);
  std::cout << (d[v3] + 1) / 2 << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  int _T = 1;
  std::cin >> _T; std::cin.get();
  
  while (_T--) {
    std::cin >> n >> k;
    Solution();
  }
  
  return 0;
}
