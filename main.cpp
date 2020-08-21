/*   Competitive Programming Standard File   */
/*     v1.0.0 - @Pedro Bento - 18/8/2020     */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;

#define fst first
#define snd second
#define all(x) begin(x), end(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define PER(i,b) ROF(i,0,b)
#define TRAV(x,xs) for (const auto& x : xs)

#define FAST_IO\
  std::ios_base::sync_with_stdio(false);\
  std::cin.tie(NULL); std::cout.tie(NULL);
#define endl "\n"

template <typename I>
void print(I it, I end) { while(it != end) { cout << *it++ << " "; } }

template <typename T>
void print(const T &x) { cout << x; }

template <typename T>
void println(const T &x) { print(x); cout << endl; }

template <typename I>
void println(I it, I end) { print(it,end); cout << endl; }

/*  *** MAIN ***  */

void test_case() {
  // Example.
  vi v {0,1,2,3,4,5,6,7,8,9};
  println(all(v));
}

int main(void) {
  FAST_IO;

  int t;
  cin >> t;

  while(t-- > 0) {
    test_case();
  }

  flush(cout);
  return EXIT_SUCCESS;
}
