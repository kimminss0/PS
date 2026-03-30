#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
  vector<int> parents; // parent's id if non-root; itself's id if root.

public:
  UnionFind(int num_vertices) : parents(num_vertices + 1) {
    for (int i = 1; i <= num_vertices; i++) {
      parents[i] = i;
    }
  }

  // path compressing
  int find(int vertex) {
    if (parents[vertex] == vertex) {
      return vertex;
    }
    parents[vertex] = find(parents[vertex]); 
    return parents[vertex];
  }

  // union
  bool unite(int vertex1, int vertex2) {
    int root1 = find(vertex1);
    int root2 = find(vertex2);

    if (root1 == root2)
        return false;
      
    parents[root1] = root2;
    return true;
  }
};

struct Edge {
  int vertex1;
  int vertex2;
  int weight;
  bool operator<(const Edge &that) const { return this->weight < that.weight; }
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int num_vertices, num_edges;
  cin >> num_vertices >> num_edges;

  UnionFind uf{num_vertices};
  vector<Edge> edges;
  edges.reserve(num_edges);

  for (int i = 0; i < num_edges; i++) {
    Edge e;
    cin >> e.vertex1 >> e.vertex2 >> e.weight;
    edges.emplace_back(std::move(e));
  }
  sort(edges.begin(), edges.end());

  int mst_weight = 0;
  int foo = num_vertices - 1;
  for (const auto [u, v, weight] : edges) {
    if (uf.unite(u, v)) {
      mst_weight += weight;
      if (!--foo)
          break;
    }
  }
  cout << mst_weight;
  return 0;
}
