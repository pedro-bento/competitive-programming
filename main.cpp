/*
  
  **Competitive Programming Standard File**

  v0.0.5 - as_path_bfs, FORE, println.
  v0.0.4 - Print.
  v0.0.3 - FAST_IO, Float Types, FOR, std namespace, Includes.  
  v0.0.2 - Integer Types.
  v0.0.1 - Graph Struct. 

  @Pedro Bento - 18/8/2020

*/

/* Includes. */

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>
#include <set>
#include <cstdint>

using namespace std;

/* Macros. */

#define FAST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

#define FOR(i,a,b) for (size_t i = (a); i < (b); i++) // incr for 
#define FORE(x,xs) for(const auto& x : xs)  // for_each

/* Integer And Float Types. */

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;
typedef long double f128;

/* Graph Struct. */

template <typename N, typename A>
struct Graph
{
private:
  unordered_map<N, unordered_map<N, A>> data;

public:
  Graph()
  {
    data = unordered_map<N, unordered_map<N, A>>();
  }

  ~Graph() {}

  bool as_node(const N &n) const
  {
    auto res = data.find(n);
    return res != data.end();
  }

  bool as_arc(const N &n, const N &m) const
  {
    if (as_node(n) && as_node(m))
    {
      auto res = data.at(n).find(m);
      return res != data.at(n).end();
    }
    return false;
  }

  void insert_node(const N &n)
  {
    if (!as_node(n))
    {
      data[n] = unordered_map<N, A>();
    }
  }

  void insert_arc(const N &n, const N &m, const A &a)
  {
    if (!as_arc(n, m))
    {
      data[n][m] = a;
    }
  }

  void insert_arc_node(const N &n, const N &m, const A &a) 
  {
    insert_node(n);
    insert_node(m);
    insert_arc(n, m, a);
  }

  const A& arc_at(const N &n, const N &m) const
  {
    return data[n][m];
  }

  const unordered_map<N, A>& node_neighbours(const N &n) const
  {
    return data.at(n);
  }

  template <size_t VSIZE>
  bool as_path_bfs(N s, N t, array<bool, VSIZE> &v) const
  {
    if (s == t)
      return true;
    if (v[s])
      return false;

    v[s] = true;

    FORE(m, node_neighbours(s))
    {
      if (!v[m.first])
        if (as_path_bfs(m.first, t, v))
          return true;
    }

    return false;
  }
};

/* Print. */

template <typename T>
void __printc(const T& c)
{
  FORE(x,c)
  {
    cout << x << " ";
  }
}

template <typename T>
void print(const vector<T> &c) { __printc(c); }

template <typename T>
void print(const list<T> &c) { __printc(c); }

template <typename T>
void print(const set<T> &c) { __printc(c); }

template <typename T>
void print(const T &x) { cout << x; }

template <typename T>
void println(const T &x) { print(x); cout << endl; }

/*  *** MAIN ***  */

int main(void) 
{
  FAST_IO;

  // CODE HERE

  return EXIT_SUCCESS;
}
