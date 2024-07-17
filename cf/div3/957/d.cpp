#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
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
    int n, m, k;
    std::string s;
    std::cin >> n >> m >> k >> s;
    s = "L" + s + "L";
    int cur = 0, swim = 0;

    while (cur <= n) {
        if (s[cur] == 'W') {
            ++swim;
            ++cur;
            continue;
        }
        if (s[cur] == 'C') {
            break;
        }
        bool j = false;
        const int jm = std::min(cur+m, n+1);
        for (int i = jm; i > cur; --i)
            if (s[i] == 'L') {
                j = true;
                cur = i;
                break;
            }

        if (j) continue;

        for (int i = jm; i > cur; --i) {
            if (s[i] == 'W') {
                j = true;
                cur = i;
                break;
            }
        }
        if (!j) break;
    }
    std::cout << (cur == n+1 && swim <= k ? "Yes" : "No") << endl;
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
