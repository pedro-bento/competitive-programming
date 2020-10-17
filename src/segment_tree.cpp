/*   Competitive Programming Standard File   */
/*     v1.0.0 - @Pedro Bento - 18/8/2020     */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define all(x) begin(x), end(x)

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define TRAV(x, xs) for (const auto& x : xs)

#define FAST_IO                          \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);
#define endl "\n"

/*   Competitive Programming Generic Sement Tree   */
/*       v1.0.0 - @Pedro Bento - 17/10/2020        */

template <typename T>
class SegmentTree {
 private:
  vector<T> segment_tree;
  ll n;
  T neutral;
  std::function<T(T, T)> merge;

  ll left(ll x) { return x * 2; }

  ll right(ll x) { return x * 2 + 1; }

  void build(ll pos, ll start, ll end, const vector<T>& xs) {
    if (start == end) {
      segment_tree[pos] = xs[start];
    } else {
      ll mid = start + (end - start) / 2;
      build(left(pos), start, mid, xs);
      build(right(pos), mid + 1, end, xs);
      segment_tree[pos] =
          merge(segment_tree[left(pos)], segment_tree[right(pos)]);
    }
  }

  void update1(ll pos, ll start, ll end, ll i, T v) {
    if (start > i || end < i) {
      return;
    }

    if (start == end && start == i) {
      segment_tree[pos] = v;
    } else {
      ll mid = start + (end - start) / 2;
      update1(left(pos), start, mid, i, v);
      update1(right(pos), mid + 1, end, i, v);
      segment_tree[pos] =
          merge(segment_tree[left(pos)], segment_tree[right(pos)]);
    }
  }

  T query1(ll pos, ll start, ll end, ll i, ll j) {
    if (i > j) {
      return neutral;
    }

    if (start == i && end == j) {
      return segment_tree[pos];
    }

    ll mid = start + (end - start) / 2;
    T a = query1(left(pos), start, mid, i, min(j, mid));
    T b = query1(right(pos), mid + 1, end, max(i, mid + 1), j);

    return merge(a, b);
  }

 public:
  SegmentTree(const vector<T>& xs, ll n_, T neutral_,
              std::function<T(T, T)> merge_)
      : n(n_), neutral(neutral_), merge(merge_) {
    segment_tree.resize(n * 4 + 5);
    build(1, 1, n, xs);
  }

  void update(ll i, T val) { update1(1, 1, n, i, val); }

  T query(ll i, ll j) { return query1(1, 1, n, i, j); }
};

/*  *** MAIN ***  */

void test_case() {
  // CODE HERE
}

int main(void) {
  FAST_IO;

  // int t;
  // cin >> t;
  // while (t--)
  // {
  //     test_case();
  // }

  while (!cin.eof()) {
    test_case();
  }

  // test_case();

  std::flush(cout);
  return EXIT_SUCCESS;
}
