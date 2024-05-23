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
constexpr int maxn = 100005;

// insert v into u
inline void insert(int u, int v, vector< vector<int> > &connexion) {
    connexion[u].push_back(v);
}

void Solution() {
    int n;
    cin >> n;
    vector< vector<int> > connexion(n+1);
    vector<int> val(n+1);
    lfor (i, 1, n, 1)
        cin >> val[i];
    lfor (i, 1, n-1, 1) {
        int u, v;
        cin >> u >> v;
        insert(u, v, connexion);
        insert(v, u, connexion);
    }
    // vector<int> ans;
    int num = 0;
    lfor (i, 1, n, 1) {
        queue<int> bfs;
        vector<int> flag(n+1);
        flag[i] = 1;
        bfs.push(i);
        int s;
        bool continue_f = true;
        while ((s = bfs.size()) && continue_f) {
            lfor (k, 1, s, 1) {
                for (auto p : connexion[bfs.front()]) {
                    double bottom = val[bfs.front()]*1.0/2;
                    if (!flag[p]) {
                        if (val[p] < bottom) { continue_f = false; break; }
                        bfs.push(p);
                        flag[p] = 1; 
                    }
                }
                bfs.pop();
            }
        }
        if (continue_f) {
            // ans.push_back(i);
            ++num;
        }
    }
    // for (auto p : ans) { cout << p << " "; cout << endl; };
    cout << num << endl;
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