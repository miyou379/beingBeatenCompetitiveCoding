#pragma GCC optimize(3)  // O3 optimize
#include <bits/stdc++.h>
typedef long long           ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll>   pll;
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
// #define int long long
constexpr int maxn = (int)4e5+3;
vector<ull> nums(maxn);
void solve() {
    int n;
    cin >> n;
    ull sum = 0;
    // I choose i-1 to represent the num of element that lies on the left.
    lfor (i, 0, n-1, 1) {
        cin >> nums[i];
        sum += nums[i]*i;
    }  // addition valid sequence
    sort(nums.begin(), nums.end(), greater<ull>());
    lfor (i, 0, n-1, 1) {
        sum -= nums[i]*i;
    }  // subtraction valid sequence
    /**
     * Notice that if (Aj-Ai < 0), after sorting, it will appear
     * as Ai-Aj, so it's neutralized, that's the crux of max(Aj-Ai, 0)
     */
    cout << sum << endl;
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
