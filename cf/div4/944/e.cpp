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
void show(vector<int> &v, int k) {
    for (int i = 0; i <= k; ++i)
        cout << v[i] << " ";
    cout << endl;
}
int binarySearch(int x, int l, int r, vector<int> &p) {
    int mid = ((r - l) >> 1) + l;
    if (l == r)
        return l;
    if (p[mid] == x)
        return mid;
    if (p[mid] < x) {
        if (p[mid+1] > x)  // crucial
            return mid;
        return binarySearch(x, mid+1, r, p);
    } else {
        return binarySearch(x, l, mid, p);
    }
}

void Solution() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k+1), b(k+1);
    lfor (i, 1, k, 1) {
        cin >> a[i];
    }
    lfor (i, 1, k, 1) {
        cin >> b[i];
    }
    while (q--) {
        int tmp;
        cin >> tmp;
        int nearby = binarySearch(tmp, 0, k, a);
        // cout << nearby << endl, show(b, k), show(a, k);
        if (tmp == a[nearby]) {
            cout << b[nearby] << " ";
        } else {
            cout << b[nearby] + int((b[nearby+1]-b[nearby])*1.0 / \
                                (a[nearby+1]-a[nearby]) * \
                                (tmp - a[nearby]) + eps) << " ";
        }
    }
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
        cout << endl;
    }
    
    return 0;
}
