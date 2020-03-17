#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> bool cmax(T& a, U b) { if (a<b) {a = b; return true;} else return false; }
template<class T, class U> bool cmin(T& a, U b) { if (a>b) {a = b; return true;} else return false; }

#include "../segment_tree.cpp"
#include "../modint.cpp"

using modint = ModInt<998244353>;

struct f{
  modint a, b;
  f(ll a, ll b) : a(a), b(b) {};
  f(modint a, modint b) : a(a), b(b) {};
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  SegmentTree<f> seg(n, f(modint(1), modint(0)), [](f l, f r){ return f(r.a*l.a, r.a*l.b+r.b); });
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    seg.change(i, f(a, b));
  }

  rep(i, q) {
    ll t;
    cin >> t;
    if (t == 0) {
      ll p, c, d;
      cin >> p >> c >> d;
      seg.change(p, f(c, d));
    } else {
      ll l, r, x;
      cin >> l >> r >> x;
      f e = seg.query(l, r);
      cout << e.a*modint(x)+e.b << endl;
    }
  }
}
