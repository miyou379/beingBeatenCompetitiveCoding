//#pragma GCC optimize(3)
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
    int a, b, c;
    std::cin >> a >> b >> c;
    int sum = a + b + c;
    int cur = 1;
    int depth = -1;
    while (sum) {
        bool leq = false;
        for (int na = cur; na >= 0; --na) {
            if (leq) break;
            for (int nb = cur - na; nb >= 0; --nb) {
                int nc = cur - na - nb;
                if (na && nb && a == b) continue;
                if (na && nc && a == c) continue;
                if (nb && nc && b == c) continue;
                int next = na * 2 + nb;
                if (na + nb + nc == 0 || next == 0) { std::cout << -1 << endl; return; }
                if (next <= sum - cur) {
                    leq = true;
                    sum -= (na + nb + nc);
                    ++depth;
                    cur = next;
                    break;
                }
            }
        }
        if (!leq) { std::cout << -1 << endl; return; }
    }
    std::cout << depth << endl;
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
