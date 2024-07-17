#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
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
inline int getsup(int x, const int y) {
    return (x / y + 1) * y;
}

void Solution() {
    int x, y, k;
    std::cin >> x >> y >> k;
    while (k) {
        const int delta = getsup(x, y) - x;
        if (x == 1) {
            x = 1 + k % (y - 1);
            k = 0;
        }
        if (k >= delta) {
            k -= delta;
            x += delta;
            while (x % y == 0) x /= y;
        } else {
            x += k;
            k = 0;
        }
    }
    std::cout << x << endl;
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    std::cin >> _T; std::cin.get();
    // std::scanf("%d", &_T); std::getchar();
    
    while (_T--) {
        Solution();
    }
    
    return 0;
}
