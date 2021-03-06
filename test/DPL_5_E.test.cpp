#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E"

#include "src/template.hpp"
#include "src/modint.hpp"
#include "src/combination.hpp"

int main() {
  ll n, k;
  cin >> n >> k;
  Combination<mint> c(n+k);
  cout << c.C(k, n) << el;
}
