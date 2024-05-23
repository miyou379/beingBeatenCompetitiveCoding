#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
using i64  =  int64_t;
using ui64 = uint64_t;
using i128 = __int128;
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
constexpr i64 upper = 20000000000;
constexpr i64 lower = 123456789;
vector<i64> tens = {1LL, 10LL, 100LL, 1000LL, 10000LL, \
                        100000LL, 1000000LL, 10000000LL, \
                        100000000LL, 1000000000LL, 10000000000LL, \
                        100000000000LL};
vector<int> initV = {1, 2, 3, 4, 5, 6, 7, 8, 9};
i64 n, d;
constexpr i64 maxn = LONG_LONG_MAX;
void dfs(vector<int> v) {
    // for (int i = 0; i < 9; ++i)
}

i64 dvpd(i64 x) {
    vector<int> cnt(10);
    i64 base = x;
    while (base < maxn) {
        i64 tmp = base;
        if (tmp) {
            ++cnt[tmp % 10];
            tmp /= 10;
        }
        bool f = true;
        for (int i = 1; i <= 9; ++i) {
            if (!cnt[i])  { f = false; break; }
            if (i == d && cnt[d] < 2) { f = false; break; }
        }
        if (f)
            return base;
        base += x;
    }
    return -1LL;
}

void Solution() {
    cin >> n >> d;
    vector<int> v = initV;
    cout << dvpd(n) << endl;
}
// #undef int

signed main(void) {
// Close the Sync_IO
std::ios::sync_with_stdio(false);
std::cin.tie(0), std::cout.tie(0);
// std::srand((int)std::time(nullptr));
    int T = 1;
// Be care of I/O!!!
    // scanf("%d", &T), getchar();
    std::cin >> T, std::cin.get();
    
    while (T--) {
        Solution();
    }
    
    return 0;
}
