#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
using i64  =  int64_t;
using uint = uint32_t;
using ui64 = uint64_t;
using i128 = __int128;
constexpr double eps = 1e-7;
constexpr int    INF = 0x3f3f3f3f;
constexpr int    M1  = 1000000007;
constexpr int    M2  = 998244353;
#define fir first
#define sec second
#define endl "\n"


void Solution() {
    int len;
    std::string s;
    std::cin >> len >> s;
    for (int i = 1; i <= len / 2; ++i) {
        if (len % i) continue;
        int seg = len / i;
        std::map<std::string, int> st;
        bool ok = true;
        for (int j = 0; j < seg; ++j) {
            ++st[s.substr(j * i, i)];
            if (st.size() > 2) { ok = false; break; }
        }
        if (!ok) continue;
        if (st.size() == 1) { std::cout << i << endl; return; }
        else {
            std::string a = (*st.begin()).first, b = (*st.rbegin()).first;
            if (!(st[a] == 1 || st[b] == 1)) continue;
            int cnt = 0;
            for (int k = 0; k < i; ++k) {
                if (a[k] != b[k]) ++cnt;
                if (cnt > 1) { ok = false; break; }
            }
            if (ok) { std::cout << i << endl; return; }
        }
    }
    std::cout << len << endl;
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    std::cin >> _T; std::cin.get();
    
    while (_T--) {
        Solution();
    }
    
    return 0;
}
