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

/*  Longest Increasing Subsequence  */
/*            @Pedro Bento          */
/*         v1.0.0 - 31/10/2020      */

#define N 10000
ll n;
ll arr[N];

ll LIS() {
  vector<int> dp;
  FOR(i, 0, n) {
    auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
    if (it == dp.end())
      dp.push_back(arr[i]);
    else
      *it = arr[i];
  }

  return dp.size();
}

/*  *** MAIN ***  */

void test_case() {
  // CODE HERE
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
