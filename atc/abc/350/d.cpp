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
constexpr int maxn = int(2e5)+5;
vector<int> fa(maxn);
vector<int> rk(maxn);
vector<int> cnt(maxn);
void initF(int a, int b) {
    for (int i = a; i <= b; ++i) {
        fa[i] = i;
        rk[i] = 1;
    }
}
void initF(vector<int> q) {
    for (auto p : q) {
        fa[p] = p;
        rk[p] = 1;
    }
}
int findF(int x) {
    return (x == fa[x]) ? x : (fa[x] = findF(fa[x]));
}
void mergeF(int i, int j) {
    fa[findF(i)] = findF(j);
}
void merge(int i, int j) {
    int x = findF(i), y = findF(j);
    rk[x] < rk[y] ? (fa[x] = y) : (fa[y] = x);
    if (rk[x] == rk[y] && x != y)
        ++rk[x];
}
/*
void del(int x) {
    int y = findF(x);
    for (int i = 0; i < (int)fa.size(); ++i)
        if (fa[i] == y) {
            fa[i] = 0;
            rk[i] = 0;
        }
}
*/
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    initF(1, n);
    ll ans = -m;
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    lfor (i, 1, n, 1)
        ++cnt[findF(i)];
    lfor (j, 1, n, 1) {
        ll tmp = (ll)cnt[j] * (cnt[j]-1) / 2;
        ans += tmp;
    }
    printf("%lld\n", ans);
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
