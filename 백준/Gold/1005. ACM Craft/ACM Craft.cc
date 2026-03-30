#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    int k;
    cin >> n >> k;

    vector<int> vertices(n+1);
    for (int i = 1; i <= n; i++) {
      cin >> vertices[i];
    }

    vector<vector<int>> edges(n+1);
    vector<int> indegrees(n+1, 0);
    for (int i = 0; i < k; i++) {
      int tail, head;
      cin >> tail >> head;
      edges[tail].push_back(head);
      indegrees[head]++;
    }

    int w;
    cin >> w;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (!indegrees[i]) {
        q.push(i);
      }
    }

    vector<int> dp = vertices;
    while (!q.empty()) {
      const auto tail = q.front();
      q.pop();
      for (const auto head : edges[tail]) {
        dp[head] = max(dp[head], dp[tail] + vertices[head]);
        if (--indegrees[head] == 0) {
          q.push(head);
        }
      }
    }
    cout << dp[w] << endl;
  }
  return 0;
}