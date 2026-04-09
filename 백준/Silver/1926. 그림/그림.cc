#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX_N{500};
const int MAX_M{500};

bool map[MAX_N][MAX_M];

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  int max_size{0};
  int num_pictures{0};
  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if (!map[i][j])
        continue; /* already visited(erased) or not colored */

      num_pictures++;

      int size{0};
      queue<pair<int, int>> wait_for_expand{};

      map[i][j] = false;            // erase the color
      wait_for_expand.push({i, j}); // pending to be expanded
      size++;

      while (!wait_for_expand.empty()) {
        auto [i1, j1] = wait_for_expand.front();
        wait_for_expand.pop();

        for (auto [di, dj] : {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
          int ni = i1 + di;
          int nj = j1 + dj;

          if (ni < 0 || ni >= n || nj < 0 || nj >= m)
            continue;
          if (!map[ni][nj])
            continue; /* already visited(erased) or not colored */

          map[ni][nj] = false;
          wait_for_expand.push({ni, nj});
          size++;
        }
      }

      max_size = max(max_size, size);
    }
  }

  cout << num_pictures << '\n';
  cout << max_size << endl;
  return 0;
}
