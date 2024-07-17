#pragma GCC optimize(3)
// #include <bits/stdc++.h>
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>

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
    cin >> s;
    const int len = s.length();
    if (s[0]-'1' || s[len-1] == '9') {
        cout << "No" << endl;
    } else {
        for (int i = 1; i < len-1; ++i)
            if (s[i] == '0') { cout << "No" << endl; return; }
        cout << "Yes" << endl;
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
