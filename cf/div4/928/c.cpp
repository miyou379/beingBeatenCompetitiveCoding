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
i64 ans[int(2e5) + 5] = {};
i64 cov(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void init() {
    for (int i = 1; i < int(2e5)+2; ++i) {
        ans[i] = ans[i-1] + cov(i);
    }
}

void Solution() {
    int x;
    std::cin >> x;
    std::cout << ans[x] << endl;
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    init();
    std::cin >> _T; std::cin.get();
    // std::scanf("%d", &_T); std::getchar();
    
    while (_T--) {
        Solution();
    }
    
    return 0;
}
