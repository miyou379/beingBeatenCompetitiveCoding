#include <bits/stdc++.h>
// using namespace std;
using i64 = long long;
using i128 = __int128;

// Global variables/functions are declared here.

namespace std {
template <typename T>
class seg {
  private:
    vector<T> tree, lazy;
    int size;

    void init(int n) {
      size = n;
      tree.assign(n << 2, T{});
      lazy.assign(n << 2, T{});
    }

    #define getid int mid = l + ((r - l) >> 1), lid = id << 1, rid = lid + 1;
    void push_up(int id) { tree[id] = tree[id << 1] + tree[(id << 1) + 1]; }
    /**
     * the node who had a lazy flag is **already modified**
     * but its child nodes are not updated.
     * the "maintain" between lazyRangeAdd and lazyRangeSet differs a bit.
     */
    #define maintain do { \
                       tree[lid] = (mid - l + 1) * lazy[id];       \
                       tree[rid] = (r - mid) * lazy[id];           \
                       lazy[lid] = lazy[id], lazy[rid] = lazy[id]; \
                       lazy[id] = 0;                               \
                     } while (0)

    void build(int l, int r, int id, const vector<T> &data) {
      if (l == r) { tree[id] = data[l]; return; }
      getid;
      build(l, mid, lid, data);
      build(mid+1, r, rid, data);
      push_up(id);
    }

  public:
    // data starts from index 1, use **original data**
    seg(int n) { init(n); }
    seg(const vector<T> &data, int n) { init(n); build(1, n, 1, data); }

    T sum(int s, int t, int l, int r, int id) {  // query for [s, t]
      if (s <= l && r <= t) return tree[id];  // [l, r] is subset of [s, t]
      getid;
      if (lazy[id] != T{} && l != r) maintain;
      T ans = 0;
      if (s <= mid) ans += sum(s, t, l, mid, lid);
      if (t > mid) ans += sum(s, t, mid+1, r, rid);
      return ans;
    }

    void set(int s, int t, const T &val, int l, int r, int id) {
      if (s <= l && r <= t) {
        tree[id] = (r - l + 1) * val;  // range * val
        lazy[id] = val;
        return;
      }
      getid;
      if (lazy[id] != T{} && l != r) maintain;
      if (s <= mid) set(s, t, val, l, mid, lid);
      if (t > mid) set(s, t, val, mid+1, r, rid);
      push_up(id);
    }

    // when only single point operations involved, no need for lazy tag
    int upper_bound(const T &val, int l, int r, int id) {
      if (l == r) return l;
      getid;
      if (lazy[id] != T{} && l != r) maintain;

      if (tree[lid] <= val) return upper_bound(val - tree[lid], mid+1, r, rid);
      else return upper_bound(val, l, mid, lid);
    }

    // [s, t], starts from 1
    T sum(int s, int t) { return sum(s, t, 1, size, 1); }
    void set(int s, int t, const T &val) { set(s, t, val, 1, size, 1); }
    int upper_bound(const T &val) { return upper_bound(val, 1, size, 1); }
    #undef getid
    #undef maintain
};
}  // namespace std

void solve(void) {
  int n, m, h;
  std::cin >> n >> m >> h;

  std::seg<int> s(n);
  s.set(1, n, 1);
  std::vector<int> v(n + 1);

  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;

    mx = std::max(mx, x);
    v[i] = x - 1;
  }

  const int mx_v = mx;
  for (int _ = 1; _ <= m; ++_) {
    int b, c;
    std::cin >> b >> c;
    
    auto offs = s.sum(b, b) + c;  // two parts
    auto val = v[b] + offs;
    mx = std::max(val, mx);

    if (mx > h) {
      s.set(1, n, 1);
      mx = mx_v;
    } else {
      s.set(b, b, offs);
    }
  // for (int i = 1; i <= n; ++i) { std::cout << s.sum(i, i) << ' '; } std::cout << '\n';
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << s.sum(i, i) + v[i] << ' ';
  }
  std::cout << '\n';
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int _T = 1;
  std::cin >> _T;

  while (_T--) {
    solve();
  }
}