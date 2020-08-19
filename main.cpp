/*
  
  **Competitive Programming Standard File**

  v0.0.3 - Add FAST_IO, Float Types, FOR, std namespace, Includes.  
  v0.0.2 - Add Integer Types.
  v0.0.1 - Add Graph Struct. 

  @Pedro Bento - 18/8/2020

*/

/* Includes. */

#include <iostream>
#include <string>
#include <algorithm>
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

#define FAST_IO std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define FOR(i,a,b) for (u32 i = a; i < b; i++)

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

  const A& arc_at(const N &n, const N &m)
  {
    return data[n][m];
  }

  const unordered_map<N, A>& node_neighbours(const N &n) const
  {
    return data.at(n);
  }
};

/*  *** MAIN ***  */

int main(void) 
{
  FAST_IO;

  // CODE HERE

  return EXIT_SUCCESS;
}