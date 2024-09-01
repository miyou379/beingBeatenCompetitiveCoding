#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
// #define int long long
typedef long long    ll;
typedef unsigned int uint;
// Note that it's virtually < 2^31
const int    INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int    M1  = 1000000007;
const int    M2  = 998244353;
#define maxx(x, y, z)     max(x,max(y,z))
#define maxxx(a, b, c, d) max(max(a,b),max(c,d))
#define endl '\n'
using namespace std;


void solve() {
    int in[200002] = {};
    char s[200002] = {};
    queue<int> zeros;
    int len = 0;
    scanf("%d", &len); getchar();
    for (int i = 0; i < len; ++i) {
        scanf("%d", &in[i]);
        if (in[i] == 0) {
            s[i] = 'a' + zeros.size();
            zeros.push(i);
        }
    }
    while (zeros.size()) {
        int ct = 1;
        int start = zeros.front();
        char tmp = s[start];
        zeros.pop(); in[start] = -1;
        for (int i = start; i < len; ++i) {
            if (in[i] == ct) {
                ++ct;
                s[i] = tmp;
                in[i] = -1;
            } else {
                continue;
            }
        }
    }
    printf("%s\n", s);
}

int main() {
// Close the Sync_IO
ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
// Be care of I/O!!!
    scanf("%d", &T); getchar();
    // cin >> T; cin.get();
    
    while (T--)
        solve();
    
    return 0;
}
