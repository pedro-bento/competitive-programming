/*   Default Competitive Programming File    */
/*                @Pedro Bento               */
/*             v1.0.0 - 18/08/2020           */
/*             v1.0.1 - 25/10/2020           */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FORI(i, a, b) for (ll i = (a); i <= (b); ++i)
#define TRAV(x, xs) for (const auto& x : xs)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset((x), 0, sizeof((x)));

#define FAST_IO                          \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);
#define endl "\n"

/*            Segment Tree          */
/*            @Pedro Bento          */
/*         v1.0.0 - 31/10/2020      */

#define N 200005
#define NEUTRAL 0
ll n;
ll v[N];
ll st[N * 4];

ll merge(ll a, ll b) { return a + b; }

void build(ll pos, ll start, ll end) {
  if (start == end) {
    st[pos] = v[start];
  } else {
    ll middle = start + (end - start) / 2;
    build(pos * 2, start, middle);
    build(pos * 2 + 1, middle + 1, end);
    st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
  }
}

void update(ll pos, ll start, ll end, ll x, ll r) {
  if (start > x || end < x) return;
  if (start == end && start == x) {
    st[pos] = r;
  } else {
    ll middle = start + (end - start) / 2;
    update(pos * 2, start, middle, x, r);
    update(pos * 2 + 1, middle + 1, end, x, r);
    st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
  }
}

ll query(ll pos, ll start, ll end, ll x, ll y) {
  if (start > y || end < x) return NEUTRAL;
  if (start >= x && end <= y) return st[pos];

  ll middle = start + (end - start) / 2;
  ll a = query(pos * 2, start, middle, x, y);
  ll b = query(pos * 2 + 1, middle + 1, end, x, y);
  return merge(a, b);
}

/*  *** MAIN ***  */

void test_case() {
  clr(v);
  clr(st);

  
}

int main(void) {
  FAST_IO;

  int t;
  cin >> t;
  while (t--) {
    test_case();
  }

  // while (!cin.eof()) {
  //   test_case();
  // }

  // test_case();

  std::flush(cout);
  return EXIT_SUCCESS;
}
