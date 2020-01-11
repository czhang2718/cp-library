// https://atcoder.jp/contests/aising2019/tasks/aising2019_c
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

class UnionFind {
private:
  vector<ll> parent;
  vector<ll> rank;

public:
  UnionFind(ll size) : parent(size), rank(size, 0) {
    for (ll i = 0; i < size; i++) {
      parent[i] = i;
    }
  }

  ll find(ll x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(ll x, ll y) {
    return find(x) == find(y);
  }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vi dx = {0, 0, 1, -1};
  vi dy = {1, -1, 0, 0};
  UnionFind uf(h*w);
  rep(i, h) rep(j, w) rep(k, 4) {
    int ni = i+dx[k];
    int nj = j+dy[k];
    if (0 <= ni && ni < h && 0 <= nj && nj < w && s[i][j] != s[ni][nj]) {
      uf.unite(i*w + j, ni*w + nj);
    }
  }

  vector<ll> black(h*w, 0), white(h*w, 0);
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') black[uf.find(i*w + j)]++;
    else white[uf.find(i*w + j)]++;
  }

  ll ans = 0;
  rep(i, h*w) {
    ans += black[i] * white[i];
  }
  cout << ans << endl;
}
