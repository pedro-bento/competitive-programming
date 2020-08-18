/*
  
  **Common Header Begin**

  v0.0.1 - Graph - 18/8/2020

  Pedro Bento

*/

#include <unordered_map>
namespace Graph 
{
  template <typename N, typename A>
  struct Graph
  {
  private:
    std::unordered_map<N, std::unordered_map<N, A>> data;

  public:
    Graph()
    {
      data = std::unordered_map<N, std::unordered_map<N, A>>();
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
        data[n] = std::unordered_map<N, A>();
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

    A arc_at(const N &n, const N &m)
    {
      return data[n][m];
    }

    const std::unordered_map<N, A>& node_neighbours(const N &n) const
    {
      return data.at(n);
    }
  };
}

/* 

  **Common Header End**

  Pedro Bento

*/

#include <iostream>
int main(void) 
{
  Graph::Graph<int, int> g;

  for(int i = 0; i < 10; i++) 
  {
    g.insert_arc_node(0, i, i);
  }

  for (const auto &n : g.node_neighbours(0))
    std::cout << n.second << std::endl;

  return EXIT_SUCCESS;
}