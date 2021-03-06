#define  PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include "src/template.hpp"
#include "src/cumulative_sum.hpp"

int main() {
  while (1) {
    ll n, k;
    cin >> n >> k;
    if (n == 0 and k == 0) return 0;
    vl a(n);
    rep(i, n) {
      cin >> a[i];
    }

    CumulativeSum<ll> cs(a);
    cs.build();
    ll ans = -1e4;
    for (ll i = 0; i+k-1 < n; i++) {
      cmax(ans, cs.sum(i, i+k-1));
    }

    cout << ans << el;
  }
}
