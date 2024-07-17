#pragma GCC optimize(3)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define endl "\n"
const int pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
int n, len;

bool determine(const int &a, const int &b, const int &slen) {
    int delta = slen - b;
    int res = n * a - b;
    int ans = 0;
    while (delta) {
        if (delta >= len) {
            ans *= pow10[len];
            ans += n;
            delta -= len;
        } else {
            ans *= pow10[delta];
            ans += n / pow10[len-delta];
            delta = 0;
        }
    }
    return ans == res;
}

void Solution() {
    std::cin >> n;
    std::vector< std::pair<int, int> > ans;
    len = (std::to_string(n)).length();
    for (int a = 1; a <= 10000; ++a) {
        const int slen = a * len;
        const int inf = std::max(1, slen-7);
        const int sup = std::min(slen-1, 10000);
        for (int b = inf; b <= sup; ++b)
            if (determine(a, b, slen)) ans.push_back({a, b});
    }
    std::cout << ans.size() << endl;
    for (auto &p : ans)
        std::cout << p.first << " " << p.second << endl;
}

signed main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int _T = 1;
    std::cin >> _T; std::cin.get();
    while (_T--)
        Solution();
    return 0;
}
