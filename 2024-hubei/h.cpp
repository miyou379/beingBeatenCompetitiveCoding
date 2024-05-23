#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
using i64  =          long long;
using ui64 = unsigned long long;
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
constexpr int maxn = 1005;
int bmp[maxn][maxn];
int n, m;
static int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
inline getw(int &i, int &j) {
    int cnt = bmp[i][j];
    if (!cnt) return 0;
    for (int k = 0; k < 4; ++k) {
        int x = i+dx[k], y = j+dy[k];
        if (x < 1 || x > n) continue;
        if (y < 1 || y > m) continue;
        cnt += bmp[x][y];
    }
    return cnt;
}

void solve() {
    priority_queue< int, vector<int>, less<int> > q;
    int k;
    cin >> n >> m >> k;
    lfor (i, 1, k, 1) {
        int x, y, val;
        cin >> x >> y >> val;
        bmp[x][y] = val;
    }
    lfor (i, 1, n, 1) {
        lfor (j, 1, n, 1) {
            
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
    // std::cin >> T, std::cin.get();
    
    while (T--) {
        solve();
    }
    
    return 0;
}
