#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl "\n"
constexpr int INF = 0x3f3f3f3f;
const int maxn = 7;
char G[maxn+2][maxn+2];
bool f[maxn+2][maxn+2];
int cnt, ans;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};

bool dfs(int a, int b) {
  f[a][b] = true;
  int c = 0;
  bool ok = false;
  for (int k = 0; k < 4; ++k) {
    int x = a + dx[k], y = b + dy[k];
    if (x < 1 || x > maxn || y < 1 || y > maxn) continue;
    if (G[x][y] == 'B') {
      ++c;
      if (!f[x][y] && dfs(x, y)) ok = true;
    }
  }
  if (c == 4) ++ans;
  return c == 4 || ok;
}

void Solution() {
  memset(f, 0, sizeof(f));
  cnt = 0, ans = 0;
  for (int i = 1; i <= maxn; ++i) {
    std::cin.get();
    for (int j = 1; j <= maxn; ++j) std::cin >> G[i][j];
  }
  for (int i = 1; i <= maxn; ++i)
    for (int j = 1; j <= maxn; ++j)
      if (G[i][j] == 'B' && !f[i][j]) {
        if (dfs(i, j)) ++cnt;
      }
  std::cout << "ans, cnt = " << ans << ", " << cnt << endl;
  std::cout << ans-cnt << endl;
}

signed main(void) {
  std::ios::sync_with_stdio(false);
  int _T = 1;
  std::cin >> _T;
  while (_T--) {
    Solution();
  }
  return 0;
}
