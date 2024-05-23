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
using gcd = std::__gcd;
int lcm(int x, int y) {
    return x*y / gcd(x, y);
}
int isSquare(int x) {
    int st = (int)floor(sqrt(x)+0.5);
    if (x == st*st)
        return st;
    if (x == (st+1)*(st+1))
        return st+1;
    return 0;
}

void solve() {
    int x, y;
    cin >> x >> y;
    pii ans = pii(0, 0);
    int ans = lcm(x, y) / gcd(x, y);
    for (int i = 1; i * i <= ans; ++i) {
        int n2 = (int)pow(i, 2);
        if (ans % n2 == 0) {
            int root = isSquare(ans / n2);
            if (root) {
                if (i * root > ans.fir)
                    ans = pii{i*root, }
            }
        }

    }
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
    std::cin >> T, std::cin.get();
    
    while (T--) {
        solve();
    }
    
    return 0;
}
