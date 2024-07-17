#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <bitset>
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
int pow2[33] = {};
void init() {
    int x = 1;
    for (int i = 0; i < 32; ++i) {
        pow2[i] = x;
        x <<= 1;
    }
}
void tobin(char *s, int x) {
    for (int i = 31; i >= 0; --i) {
        if (!x) break;
        s[i] = x & 1;
        x >>= 1;
    }
}
int xorandlowbit(char *sa, char *sb) {
    for (int i = 31; i >= 0; --i)
        sa[i] ^= sb[i];
    int i = 0;
    for (; i < 32; ++i)
        if (sa[31-i] == 1) break;
    return pow2[i];
}
void Solution() {
    int a, b;
    char sa[32] = {}, sb[32] = {};
    std::cin >> a >> b;
    tobin(sa, a); tobin(sb, b);
    std::cout << xorandlowbit(sa, sb) << endl;
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    std::cin >> _T; std::cin.get();
    // std::scanf("%d", &_T); std::getchar();
    init();
    while (_T--) {
        Solution();
    }
    
    return 0;
}
