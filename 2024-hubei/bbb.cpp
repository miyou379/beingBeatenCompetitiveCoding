#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pll pair<long long, long long>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define ll long long
#define ull unsigned long long
const ll INF = 9187201950435737471;
const int inf = 2139062143;
const ll mod = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1.0);
const int N = 1007;
vector<array<int, 2>> p(N);
int n;
double s;
constexpr double dinf = (double)INF;
double getS(int x1, int y1, int x2, int y2, int x3, int y3) {
    double l[3] = {
                    sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)),
                    sqrt(pow(x2-x3, 2) + pow(y2-y3, 2)),
                    sqrt(pow(x1-x3, 2) + pow(y1-y3, 2))
                  };
    sort(l, l+3);
    if (l[0] + l[1] <= l[2]) return dinf;
    double s = 0.5 * fabs(1.0 * x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    return s;
}
void solve() {
    cin >> n;
    bool f = false;
    double s;
    for(int i=1; i<=n; i++) cin >> p[i][0] >> p[i][1];
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            for(int k=j+1; k<=n; k++) {
                //cout << getS(p[i][0], p[i][1], p[j][0], p[j][1], p[k][0], p[k][1]) << endl;
                double tmp = getS(p[i][0], p[i][1], p[j][0], p[j][1], p[k][0], p[k][1]);
                if (tmp != dinf) {
                    if (f) {
                        s = min(s, tmp);
                    } else {
                        f = true;
                        s = tmp;
                    }
                }
            }
        }
    }
    cout << (f ? s : -1) << endl;
}
int main() {
    FAST_IO;
    int _ = 1;
    cin >> _;
    while(_ --) solve();
    //cout << "Time used = " << (double)(clock() * 1.0 / CLOCKS_PER_SEC) << "s";
    return 0;
}
