/**
 * @brief BOJ No. 1368 "물대기"
 *
 * @author Minseo Kim <kimminss0@outlook.kr>
 * @details Solve minimum spanning tree using Prim's algorithm 
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  // Vertices
  // 1..N: 논
  // N+1: 임의로 도입
  //      다른 정점으로의 간선: 우물 파는 비용

  // Edges
  // dense하므로 2d vector로 구현
  vector<vector<int>> edges(N+2, vector<int>(N+2, 0));

  for (int i = 1; i <= N; i++) {
    int w;
    cin >> w;
    edges[i][N+1] = w;
    edges[N+1][i] = w;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> edges[i][j];
    }
  }

  const int inf = 100001;

  vector<bool> vertex_in_mst(N+2, false);
  vector<int> vertex_cost(N+2, inf);
  
  vector<pair<int, int>> _data;
  _data.reserve(N+1);
  for (int i = 1; i <= N+1; i++) {
    _data.emplace_back(make_pair(i, inf));
  }
  priority_queue pq(
      [](const auto &a, const auto &b) -> bool { return a.second > b.second; },
      std::move(_data));
  
  int mst_weight = -inf;
  int i = N+1;
  while (i) {
    const auto [v, w] = pq.top();
    pq.pop();
    if (vertex_in_mst[v]) continue;
    vertex_in_mst[v] = true;
    mst_weight += w;
    i--;
    for (int j = 1; j <= N+1; j++) {
      if (edges[v][j] < vertex_cost[j]) {
        vertex_cost[j] = edges[v][j];
        pq.push(make_pair(j, vertex_cost[j]));
      }
    }
  }
  cout << mst_weight;
  return 0;
}
