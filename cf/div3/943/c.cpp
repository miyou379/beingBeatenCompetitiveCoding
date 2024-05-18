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
constexpr int maxn = 504;

void solve() {
    int n;
    cin >> n;
    int mod[maxn] = {};
    int a[maxn] = {};
    lfor (i, 2, n, 1)
        cin >> mod[i];
    a[1] = mod[2]+1;
    lfor (i, 2, n, 1) {
        int R = mod[i+1], L = mod[i];
        int tmp = 0;
        while (tmp + L <= R) {
            tmp += a[i-1];
        }
        a[i] = tmp + L;
    }
    lfor (i, 1, n, 1)
        cout << a[i] << " ";
    cout << endl;
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
