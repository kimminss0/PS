#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class UnionFind {
private:
  vector<int> parent;

public:
  UnionFind(int N) : parent(N) {
    for (int i = 0; i < N; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return false;
    }
    parent[rootX] = rootY;
    return true;
  }
};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int N;
  cin >> N;

  // idx, coord
  vector<pair<int, int>> x(N), y(N), z(N);

  for (int i = 0; i < N; i++) {
    x[i].first = i;
    y[i].first = i;
    z[i].first = i;
    cin >> x[i].second >> y[i].second >> z[i].second;
  }

  if (N == 1) {
    cout << 0;
    return 0;
  }

  auto cmp = [](pair<int, int> a, pair<int, int> b) -> bool {
    return a.second < b.second;
  };
  sort(x.begin(), x.end(), cmp);
  sort(y.begin(), y.end(), cmp);
  sort(z.begin(), z.end(), cmp);

  // w, v, u
  vector<tuple<int, int, int>> edges;
  edges.reserve(N * 3);
  for (const auto &ax : {x, y, z}) {
    for (int it1 = 0, it2 = 1; it2 < N; it1++, it2++) {
      int v = ax[it1].first;
      int u = ax[it2].first;
      int w = abs(ax[it1].second - ax[it2].second);
      edges.emplace_back(make_tuple(w, v, u));
    }
  }
  std::sort(edges.begin(), edges.end(),
            [](auto a, auto b) -> bool { return get<0>(a) < get<0>(b); });

  // KruskalMST
  UnionFind uf(N);
  int mstWeight = 0;
  for (const auto [w, v, u] : edges) {
    if (uf.unite(v, u)) {
      mstWeight += w;
    }
  }
  cout << mstWeight;

  return 0;
}
