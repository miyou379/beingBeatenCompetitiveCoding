#pragma GCC optimize(3)
// #include <bits/stdc++.h>
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <vector>
using i64  =  int64_t;
using ui64 = uint64_t;
using i128 = __int128;
constexpr double eps = 1e-7;
constexpr int    INF = 0x3f3f3f3f;
constexpr int    M1  = 1000000007;
constexpr int    M2  = 998244353;
#define fir first
#define sec second
#define endl "\n"
using namespace std;
using Graph = std::vector< std::vector<int> >;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;

inline int getMax(Graph &G, int i, int j) {
    const int &cur = G[i][j];
    int maxi = 0;
    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= n || x < 0 || y >= m || y < 0) continue;
        if (cur <= G[x][y]) return -1;
        else maxi = max(maxi, G[x][y]);
    }
    return maxi;
}

bool circular(Graph &G) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            const int maxi = getMax(G, i, j);
            if (maxi == -1) continue;
            G[i][j] = maxi;
            return true;
        }
    return false;
}

void Solution() {
    cin >> n >> m;
    Graph G = Graph(n+1, std::vector<int>(m+1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> G[i][j];
    while (true)
        if (!circular(G)) break;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << G[i][j] << " ";
        std::cout << endl;
    }
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    std::cin >> _T; std::cin.get();
    // scanf("%d", &_T); getchar();
    
    while (_T--) {
        Solution();
    }
    
    return 0;
}
