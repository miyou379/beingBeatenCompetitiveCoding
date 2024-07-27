#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <set>
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
const int s[] = { 0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, \
                  1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, \
                  10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, \
                  11100, 11101, 11110, 11111, 100000 };
std::set<int> bd;
void init() {
    for (auto &p : s)
        for (auto &q : s)
            for (auto &a : s)
                for (auto &b : s)
                        bd.insert(q * p * a * b);
}


void Solution() {
    int n;
    std::cin >> n;
    if (bd.count(n)) std::cout << "YES" << endl;
    else std::cout << "NO" << endl;
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
