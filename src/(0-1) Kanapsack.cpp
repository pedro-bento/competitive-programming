/*   Default Competitive Programming File    */
/*                @Pedro Bento               */
/*             v1.0.0 - 18/08/2020           */
/*             v1.0.1 - 25/10/2020           */
/*             v1.0.2 - 01/11/2020           */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FORI(i, a, b) for (ll i = (a); i <= (b); ++i)
#define RFOR(i, a, b) for (ll i = (a); i > (b); --i)
#define RFORI(i, a, b) for (ll i = (a); i >= (b); --i)
#define TRAV(x, xs) for (const auto& x : xs)
#define RTRAV(x, xs) for (auto x = xs.rbegin(); x != xs.rend(); ++x)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset((x), 0, sizeof((x)));

#define FAST_IO                          \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);
#define endl "\n"

/*          (0-1) Kanapsack         */
/*            @Pedro Bento          */
/*         v1.0.0 - 01/11/2020      */

#define N 1000
ll n = 0, w = 0;
ll weight[N] = {};
ll value[N] = {};

ll knapsack() {
  ll dp[w + 1] = {};
  FOR(i, 0, n) {
    RFORI(j, w, weight[i]) {
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  return dp[w];
}

/*  *** MAIN ***  */
void test_case() {
  clr(weight);
  clr(value);
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
