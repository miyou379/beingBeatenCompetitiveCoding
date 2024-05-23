#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
using i64  = long long;
// using i128 = __int128_t;
typedef std::pair<int,int> pii;
typedef std::pair<i64,i64> pll;
// Note that it's virtually < 2^31
const int    INF = 0x3f3f3f3f;
const double eps = 1e-6;
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
    int x, y;
    point(int a = 0, int b = 0) : x(a), y(b) {}
} point;
inline double accfloat(double x) {
    if (x > ceil(x)-eps)
        return ceil(x);
    if (x < floor(x)+eps)
        return floor(x);
    return x;
}
double line(point a, point b) {
    double ll = pow(a.x - b.x, 2);
    ll += pow(a.y - b.y, 2);
    return sqrt(ll);
}
inline bool triangle(double a, double b, double c) {
    return a + b - eps > c;
}
double helen(point a, point b, point c) {
    double x = line(a, b), y = line(b, c), z = line(a, c);
    if (y < x) swap(x, y);
    if (z < y) swap(y, z);
    if (y < x) swap(y, x);
    if (!triangle(x, y, z))
        return -1;
    double p = x+y+z;
    p /= 2;
    double ans = sqrt(p * (p-x) * (p-y) * (p-z));
    return ans;
}
void solve() {
    bool f = false;
    int n;
    cin >> n;
    vector<point> pp(n+2);
    lfor (i, 1, n, 1)
        cin >> pp[i].x >> pp[i].y;
    double minS;
    lfor (i, 1, n, 1)
        lfor (j, i+1, n, 1)
            lfor (k, j+1, n, 1) {
                double tmp = helen(pp[i], pp[j], pp[k]);
                if (tmp != -1) {
                    if (f) {
                        minS = min(minS, tmp);
                    } else {
                        f = true;
                        minS = tmp;
                    }
                }
            }
    cout << (f ? minS : -1) << endl;
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
