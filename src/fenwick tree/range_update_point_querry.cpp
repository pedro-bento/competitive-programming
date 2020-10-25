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
/*    Range Update, Point Querry    */
/*            @Pedro Bento          */
/*         v1.0.0 - 25/10/2020      */

#define N 105
ll arr[N];
ll tree[N];
ll n;

void update(ll x, ll val) {
  while (x <= n) {
    tree[x] += val;
    x += (x & -x);
  }
}

void range_update(ll x, ll y, ll val) {
  update(x, val);
  update(y + 1, -val);
}

ll querry(ll x) {
  ll sum = 0;
  while (x > 0) {
    sum += tree[x];
    x -= (x & -x);
  }
  return sum;
}

/*  *** MAIN ***  */

void test_case() {
  clr(arr);
  clr(tree);

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
