#pragma GCC optimize(3)
// #include <bits/stdc++.h>
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <string>
#include <array>
#include <set>
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


void Solution() {
    string s;
    int n, m;
    set<int> ind;
    std::cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        ind.insert(tmp);
    }
    cin.get();
    array<char, int(1e5+5)> c;
    for (int i = 0; i < m; ++i)
        cin >> c[i];
    sort(c.begin(), c.begin()+m);
    int idx = 0;
    for (auto &p : ind)
        s[p-1] = c[idx++];
    std::cout << s << endl;
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
