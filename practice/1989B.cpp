#pragma GCC optimize(3)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <string>
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
    string substr, subseq;
    cin >> substr >> subseq;
    int i = 0, j = 0;
    const int lenstr = substr.length(), lenseq = subseq.length();
    int ans = INF;
    for (int k = 0; k < lenseq; ++k) {
        i = 0;
        j = k;
        while (i < lenstr && j < lenseq) {
            if (subseq[j] == substr[i]) ++j;
            ++i;
        }
        ans = min(ans, (lenstr + lenseq-j + k));
    }
    std::cout << ans << endl;
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    std::cin >> _T; cin.get();
    // scanf("%d", &_T); getchar();
    
    while (_T--) {
        Solution();
    }
    
    return 0;
}
