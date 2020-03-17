---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :heavy_check_mark: union_find.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-17 18:17:55+09:00




## Verified with

* :heavy_check_mark: <a href="../verify/test/union_find.test.cpp.html">test/union_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
  struct Node {
    ll parent;
    ll size;
  };
  vector<Node> tree;

  UnionFind(ll size) : tree(size) {
    for (ll i = 0; i < size; i++) {
      tree[i].parent = i;
      tree[i].size = 1;
    }
  }

  ll find(ll x) {
    while (tree[x].parent != x) {
      ll p = tree[x].parent;
      tree[x].parent = tree[p].parent;
      x = p;
    }
    return x;
  }

  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (tree[x].size < tree[y].size) swap(x, y);
    tree[y].parent = x;
    tree[x].size += tree[y].size;
  }

  bool same(ll x, ll y) {
    return find(x) == find(y);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "union_find.cpp"
struct UnionFind {
  struct Node {
    ll parent;
    ll size;
  };
  vector<Node> tree;

  UnionFind(ll size) : tree(size) {
    for (ll i = 0; i < size; i++) {
      tree[i].parent = i;
      tree[i].size = 1;
    }
  }

  ll find(ll x) {
    while (tree[x].parent != x) {
      ll p = tree[x].parent;
      tree[x].parent = tree[p].parent;
      x = p;
    }
    return x;
  }

  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (tree[x].size < tree[y].size) swap(x, y);
    tree[y].parent = x;
    tree[x].size += tree[y].size;
  }

  bool same(ll x, ll y) {
    return find(x) == find(y);
  }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>
