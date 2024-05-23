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
typedef struct point {
    int x;
    int y;
    point(int a = 0, int b = 0) : x(a), y(b) {}
} point;
constexpr int maxn = 200005;
vector<point> dots(maxn);

long double func(int i, int j) {
    i64 a = abs(dots[i].x - dots[j].x);
    i64 b = abs(dots[i].y - dots[j].y);
    if (!a || !b) return 1.0L;
    i64 a2b2 = a*a + b*b;
    return ((a+b) * 1.0L/ sqrt(a2b2));
}

void Solution() {
    int n;
    cin >> n;
    pii ans;
    long double ans_f = 0.0L;
    lfor (i, 0, n-1, 1) {
        cin >> dots[i].x >> dots[i].y;
    }
    lfor (i, 0, n-1, 1) {
        lfor (j, i+1, n-1, 1) {
            int a = abs(dots[i].x - dots[j].x);
            int b = abs(dots[i].y - dots[j].y);
            if (!a || !b) continue;
            // long double tmp = max(a, b)*1.0L / min(a, b);
            long double tmp = a * 1.0L / b;
            if (tmp > ans_f) {
                ans = {i, j};
                ans_f = tmp;
            }
        }
    }
    // cout << ans.fir << " " << ans.sec << endl;
    cout << fixed << setprecision(12) << func(ans.fir, ans.sec) << endl;
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
