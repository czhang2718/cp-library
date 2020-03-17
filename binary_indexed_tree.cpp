template<typename T>
struct BinaryIndexedTree {
  // 1-indexed
  int n;
  vector<T> bit;

  BinaryIndexedTree(int n_, T d = 0):n(n_), bit(n_+1, d) {}

  void add(int i, T a) {
    if (i == 0) return;
    for (int x = i; x <= n; x += x&-x) {
      bit[x] += a;
    }
  }

  T sum(int i) {
    T s = bit[0];
    for (int x = i; x > 0; x -= x&-x) {
      s += bit[x];
    }
    return s;
  }

  T sum_between(int l, int r) {
    return sum(r) - sum(l-1);
  }

  // bit[1] + bit[2] + ... + bit[x] >= w;
  int lower_bound(T w){
    if (w <= 0) return 0;
    int x = 0, r = 1;
    while (r < n) r <<= 1;
    for (int k = r; k > 0; k >>= 1){
      if(x+k <= n && bit[x+k] < w){
        w -= bit[x+k];
        x += k;
      }
    }
    return x+1;
  }

  void add0(int i, T a) {
    add(i+1, a);
  }

  T sum0(int i) {
    return sum(i+1);
  }

  T sum_between0(int l, int r) {
    return sum(r+1) - sum(l);
  }
};