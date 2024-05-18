#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
typedef long long           ll;
typedef unsigned long long ull;
// Note that it's virtually < 2^31
const int    INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int    M1  = 1000000007;
const int    M2  = 998244353;
// Note that lfor requires indeed integer arguments
#define lfor(i, a, b, k)  for(int i=(a);i<=(b);i+=(k))
#define eq0(x)            ((x)<(eps)&&(-eps)<(x))
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
unordered_map<ll, long double> dp;
ll N, a;
long double x, y;
long double f(ll n) {
    if (!n)
        return 0.0;
    if (dp[n])
        return dp[n];
    long double ans1 = x + f(ll(n / a));
    long double ans2 = 0.0;
    lfor (i, 2, 6, 1)
        ans2 += y + f(n / i);
    return dp[n] = min(ans1, ans2 / 5);
}
// #undef int

int main(void) {
// Close the Sync_IO
ios::sync_with_stdio(false);
std::cin.tie(0), std::cout.tie(0);
// std::srand((int)std::time(nullptr));
// Be care of I/O!!!
    cin >> N >> a >> x >> y;
    y *= 1.2;
    cout << fixed << setprecision(15) << f(N) << endl;
    
    return 0;
}
