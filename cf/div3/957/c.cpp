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
    int n, m, k;  // n is length, <= m g(i), >= k f(i)
    // f(i) and g(i) begins at index 1.
    std::cin >> n >> m >> k;
    for (int i = n; i >= k; --i)
        std::cout << i << " ";
    for (int i = k-1; i > m; --i)
        std::cout << i << " ";
    for (int i = 1; i <= m; ++i)
        std::cout << i << " ";
    std::cout << endl;
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
