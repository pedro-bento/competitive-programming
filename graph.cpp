/*

  **Competitive Programming Standard File**

  v1.0.0 - Graph

  @Pedro Bento - 18/8/2020

*/

#include <bits/stdc++.h>
using namespace std;

template <typename N, typename A>
struct Graph {
private:
  unordered_map<N, unordered_map<N, A>> data;

public:
  Graph() {
    data = unordered_map<N, unordered_map<N, A>>();
  }

  ~Graph() {}

  bool as_node(const N &n) const {
    auto res = data.find(n);
    return res != data.end();
  }

  bool as_arc(const N &n, const N &m) const {
    if (as_node(n) && as_node(m)) {
      auto res = data.at(n).find(m);
      return res != data.at(n).end();
    }
    return false;
  }

  void insert_node(const N &n) {
    if (!as_node(n)) {
      data[n] = unordered_map<N, A>();
    }
  }

  void insert_arc(const N &n, const N &m, const A &a) {
    if (!as_arc(n, m)) {
      data[n][m] = a;
    }
  }

  void insert_arc_node(const N &n, const N &m, const A &a) {
    insert_node(n);
    insert_node(m);
    insert_arc(n, m, a);
  }

  const A& arc_at(const N &n, const N &m) const {
    return data[n][m];
  }

  const unordered_map<N, A>& node_neighbours(const N &n) const {
    return data.at(n);
  }

  template <size_t VSIZE>
  bool as_path_dfs(N s, N t, array<bool, VSIZE> &v) const {
    if (s == t)
      return true;
    if (v[s])
      return false;

    v[s] = true;

    for(const auto& m : node_neighbours(s)) {
      if (!v[m.first])
        if (as_path_dfs(m.first, t, v))
          return true;
    }

    return false;
  }
};

int main(void) {
  // Example use.
  Graph<int,int> g;

  g.insert_arc_node(0,1,-1);
  g.insert_arc_node(1,2,0);
  g.insert_arc_node(2,3,100);

  array<bool, 100> vis; vis.fill(false);
  cout << g.as_path_dfs(0,3,vis) << endl;
  cout << g.as_path_dfs(2,1,vis) << endl;

  return EXIT_SUCCESS;
}
