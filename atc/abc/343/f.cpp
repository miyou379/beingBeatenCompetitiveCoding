#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <vector>
#include <functional>
#define LF "\n"

struct mx {
  int mx1, c1, mx2, c2;
  mx(int mx1 = -1, int c1 = 0, int mx2 = -1, int c2 = 0): mx1(mx1), c1(c1), mx2(mx2), c2(c2) {}
};

std::function<mx(const mx&, const mx&)> cmp = [](mx a, mx b) {
  if (a.mx1 == b.mx1) {
    if (a.mx2 < b.mx2) std::swap(a, b);
    a.c1 += b.c1;
    if (a.mx2 == b.mx2) a.c2 += b.c2;
  } else {
    if (a.mx1 < b.mx1) std::swap(a, b);
    if (b.mx1 > a.mx2) {
      a.mx2 = b.mx1;
      a.c2 = b.c1;
    } else if (b.mx1 == a.mx2) a.c2 += b.c1;
  }
  return a;
};

namespace std {
template <class T>
class rmqSegment {
  using func_t = std::function<T(const T&, const T&)>;
  private:
    std::vector<T> tree;
    int size;
    func_t rmq;
  public:
    rmqSegment(int n, func_t _rmq) { init(n, _rmq); }
    rmqSegment(vector<T> &data, int n, func_t _rmq) {
      init(n, _rmq);
      build(1, n, 1, data);
    }
    inline void init(int n, func_t &_rmq) {
      rmq = _rmq;
      size = n;
      tree.assign(n << 2, T{});
    }
    void build(int l, int r, int id, vector<T> &data) {
      if (l == r) { tree[id] = data[l]; return; }
      int mid = l + ((r - l) >> 1), lid = (id << 1), rid = lid + 1;
      build(l, mid, lid, data), build(mid+1, r, rid, data);
      tree[id] = rmq(tree[lid], tree[rid]);  // push_up
    }
    T query(int s, int t, int l, int r, int id) {
      if (l > t || r < s) return T{};
      if (s <= l && r <= t) return tree[id];
      int mid = l + ((r - l) >> 1), lid = (id << 1), rid = lid + 1;
      return rmq(query(s, t, l, mid, lid), query(s, t, mid+1, r, rid));
    }
    void set(int x, T val, int l, int r, int id) {
      if (l == r && l == x) { tree[id] = val; return; }
      int mid = l + ((r - l) >> 1), lid = (id << 1), rid = lid + 1;
      if (x <= mid) set(x, val, l, mid, lid);
      else set(x, val, mid+1, r, rid);
      tree[id] = rmq(tree[lid], tree[rid]);  // push_up
    }
    inline T query(int s, int t) { return query(s, t, 1, size, 1); }
    inline void set(int x, T val) { set(x, val, 1, size, 1); }
};
}  // namespace std

signed main(void) {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  int n, q, opt, l, r;

  std::cin >> n >> q;
  std::vector<mx> v(n+1);
  for (int i = 1; i <= n; ++i) {
    int tmp;
    std::cin >> tmp;
    v[i] = mx{tmp, 1};
  }
  std::rmqSegment<mx> t(v, n, cmp);

  while (q--) {
    std::cin >> opt >> l >> r;
    if (opt == 1) t.set(l, mx{r, 1});
    else std::cout << t.query(l, r).c2 << LF;
  }
  return 0;
}
