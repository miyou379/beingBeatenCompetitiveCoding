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
    int length = 1;
    char s[50];
    scanf("%d", &length); getchar();
    scanf("%[^\n]%*c", s);
    int begin, end;
    for (begin = 0; begin < length; ++begin)
        if (s[begin] == 'B') break;
    for (end = length - 1; end >= 0; --end)
        if (s[end] == 'B') break;
    printf("%d\n", end - begin + 1);
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
