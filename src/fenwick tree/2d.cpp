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
/*                2D                */
/*            @Pedro Bento          */
/*         v1.0.0 - 25/10/2020      */

#define N 1050
ll matrix[N][N];
ll tree[N][N];
ll n;

void update(ll x, ll y, ll val) {
  ll y1;
  while (x <= n) {
    y1 = y;
    while (y1 <= n) {
      tree[x][y1] += val;
      y1 += (y1 & -y1);
    }
    x += (x & -x);
  }
}

ll querry(ll x, ll y) {
  ll y1, sum = 0;
  while (x > 0) {
    y1 = y;
    while (y1 > 0) {
      sum += tree[x][y1];
      y1 -= (y1 & -y1);
    }
    x -= (x & -x);
  }
  return sum;
}

ll range_querry(ll x1, ll y1, ll x2, ll y2) {
  return querry(x2, y2) - querry(x1 - 1, y2) - querry(x2, y1 - 1) + querry(x1 - 1, y1 - 1);
}

/*  *** MAIN ***  */

void test_case() {
  clr(matrix);
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
