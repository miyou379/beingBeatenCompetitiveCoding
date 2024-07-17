#pragma GCC optimize(3)
// #include <bits/stdc++.h>
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <vector>
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
    int n;
    cin >> n;
    std::vector<int> v(n+1);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = n-1; i >= 0; --i)
        v[i] = std::max(v[i], v[i+1]+1);
    cout << v[0] << endl;

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
