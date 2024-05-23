#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
using i64  = long long;
// using i128 = __int128_t;
typedef std::pair<int,int> pii;
typedef std::pair<i64,i64> pll;
// Note that it's virtually < 2^31
const int    INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int    M1  = 1000000007;
const int    M2  = 998244353;
// Note that lfor requires indeed Integer arguments
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
// #define int i64
i64 exgcd(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve() {
    i64 sum = 0;
    int n;
    cin >> n;
    lfor (i, 1, n, 1) {
        i64 tmp;
        cin >> tmp;
        sum += tmp;
    }
    sum %= M2;
    i64 x = 0, y = 0;
    exgcd(n, M2, x, y);
    x = (x % M2 + M2) % M2;
    cout << x * sum % M2 << endl;
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
