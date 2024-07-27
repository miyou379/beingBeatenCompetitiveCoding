#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>

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
using namespace std;


void Solution() {
    int h, m;
    std::scanf("%d:%d", &h, &m);
    bool f = false;
    if (h >= 0 && h <= 11) f = true;  // AM
    if (h == 12 && h == 0) f = true;  // AM
    if (h == 0) h += 12;
    if (h > 12) h %= 12;
    std::printf("%02d:%02d", h, m);
    std::printf(" %s\n", (f ? "AM" : "PM"));
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    // std::cin >> _T; std::cin.get();
    std::scanf("%d", &_T); std::getchar();
    
    while (_T--) {
        Solution();
    }
    
    return 0;
}
