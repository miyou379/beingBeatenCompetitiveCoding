#include <algorithm>
#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
typedef long long           ll;
typedef unsigned long long ull;
// Note that it's virtually < 2^31
const int    INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int    M1  = 1000000007;
const int    M2  = 998244353;
#define lfor(i, a, b, k)  for(int i=(a);i<=(b);i+=(k))
#define eql(x, y, z)      ((x==y)&&(x==z))
#define eqll(a, b, c, d)  ((a==b)&&(a==c)&&(a==d))
#define maxx(x, y, z)     std::max(x,std::max(y,z))
#define maxxx(a, b, c, d) std::max(std::max(a,b),std::max(c,d))
#define ALL(x)            x.begin(),x.end()
#define INS(x)            inserter(x,x.begin())
#define fir  first
#define sec  second
#define endl '\n'
using namespace std;
// #define int long long
vector<int> init;
map<int, int> ini;  // value -> index
vector< pair<int, int> > pp;
void solve() {
    int n;
    scanf("%d", &n);
    lfor (i, 0, n-1, 1) {
        int tmp;
        scanf("%d", &tmp);
        init.push_back(tmp);
    }
    vector<int> final(init);
    sort(ALL(final));
    for (int j = 0; j < init.size(); ++j)
        ini[init[j]] = j;
    int cnt = 0;
    for (int i = 0; i < n;) {
        while (init[i] != final[i]) {
            pp.push_back({min(ini[final[i]], ini[init[i]]), max(ini[final[i]], ini[init[i]])});
            swap(ini[init[i]], ini[final[i]]);
            swap(init[ini[init[i]]], init[ini[final[i]]]);
            ++cnt;
        }
        ++i;
    }
    printf("%d\n", cnt);
    /* for (auto p : pp) {
        printf("%d %d\n", p.first, p.second);
    } */
}
// #undef int

int main(void) {
// Close the Sync_IO
ios::sync_with_stdio(false);
std::cin.tie(0), std::cout.tie(0);
// std::srand((int)std::time(nullptr));
    int T = 1;
// Be care of I/O!!!
    // scanf("%d", &T), getchar();
    // std::cin >> T, std::cin.get();
    
    while (T--) {
        solve();
    }
    
    return 0;
}
