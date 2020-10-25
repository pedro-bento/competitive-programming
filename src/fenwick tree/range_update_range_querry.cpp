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

/*            Fenwick Tree          */
/*    Range Update, Range Querry    */
/*            @Pedro Bento          */
/*         v1.0.0 - 25/10/2020      */

#define N 105
ll arr[N];
ll tree1[N];
ll tree2[N];
ll n;

void update(ll t[], ll x, ll val) {
  while (x <= n) {
    t[x] += val;
    x += (x & -x);
  }
}

void range_update(ll l, ll r, ll val) {
  update(tree1, l, val);
  update(tree1, r + 1, -val);

  update(tree2, l, val * (l - 1));
  update(tree2, r + 1, -val * r);
}

ll querry(ll t[], ll x) {
  ll sum = 0;
  while (x > 0) {
    sum += t[x];
    x -= (x & -x);
  }
  return sum;
}

ll prefix_querry(ll x) { return querry(tree1, x) * x - querry(tree2, x); }
ll range_querry(ll l, ll r) { return prefix_querry(r) - prefix_querry(l - 1); }

/*  *** MAIN ***  */

void test_case() {
  clr(arr);
  clr(tree1);
  clr(tree2);

  // CODE HERE
}

int main(void) {
  FAST_IO;

  ll t;
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
