#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
string re[] = {"SAME", "TAOYUAN", "JAKARTA"};
#define c(x) cout<<re[x]<<endl
void solve() {
    i64 Rt, Rj;
    double st, sj;
    cin >> Rt >> Rj >> st >> sj;
    i64 St = i64(100 * st), Sj = i64(100 * sj);
    if (Rt == 1 && Rj == 1) {
        if (St > Sj)
            c(1);
        else if (St < Sj)
            c(2);
        else
            c(0);
        return;
    }
    i64 lcm = St * Sj / __gcd(St, Sj);
    i64 rkt = (Rt-1) * (lcm / St), rkj = (Rj-1) * (lcm / Sj);
    if (Rt == Rj && Rt == 1) {
        if (St == Sj) c(0);
        else (St > Sj) ? c(1) : c(2);
        return;
    }
    if (rkt == rkj)
        c(0);
    else if (rkt < rkj)
        c(1);
    else
        c(2);
}

int main(void) {
    solve();
    return 0;
}
