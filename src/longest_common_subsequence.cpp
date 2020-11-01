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
#define ROF(i, a, b) for (ll i = (a); i > (b); --i)
#define ROFI(i, a, b) for (ll i = (a); i >= (b); --i)
#define TRAV(x, xs) for (const auto& x : xs)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset((x), 0, sizeof((x)));

#define FAST_IO                          \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);
#define endl "\n"

/*     Longest Common Subsequence   */
/*            @Pedro Bento          */
/*         v1.0.0 - 01/11/2020      */

#define N 10000
ll n;
vector<string> seq1;
vector<string> seq2;

ll LCS() {
  ll s1 = seq1.size();
  ll s2 = seq2.size();

  ll dp[s1 + 1][s2 + 1] = {};
  FORI(i, 1, s1) {
    FORI(j, 1, s2) {
      if (seq1[i - 1] == seq2[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      } else {
        dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
      }
    }
  }

  return dp[s1][s2];
}

/*  *** MAIN ***  */

void test_case() {
  // CODE HERE
  seq1.clear();
  seq2.clear();

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
