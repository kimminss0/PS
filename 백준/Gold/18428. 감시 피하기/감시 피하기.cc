#include <bitset>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int MAX_N = 6;
const int MAX_T = 5;
const int MAX_OBS_GROUPS = MAX_T * 4;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int N, num_obs_group{0};
  char board[MAX_N][MAX_N];
  vector<pair<uint8_t, uint8_t>> teachers;

  cin >> N;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      char c;
      cin >> c;

      board[i][j] = c;
      if (c == 'T') {
        teachers.push_back({i, j});
      }
    }
  }

  unordered_map<size_t, bitset<MAX_OBS_GROUPS>> obs_candidates;
  for (auto [i, j] : teachers) {
    for (auto [di, dj] : {pair{-1, 0}, {+1, 0}, {0, +1}, {0, -1}}) {
      size_t n = 1;
      bool stu_found = false;
      for (;;) {
        size_t ni{i + n * di};
        size_t nj{j + n * dj};

        if (ni < 0 || ni >= N || nj < 0 || nj >= N)
          break;

        if (board[ni][nj] == 'S') {
          stu_found = true;
          break;
        } else if (board[ni][nj] == 'T') {
          break;
        }

        n++;
      }
      if (!stu_found)
        continue;

      num_obs_group++;
      for (size_t n1 = 1; n1 < n; n1++) {
        size_t ni{i + n1 * di};
        size_t nj{j + n1 * dj};

        obs_candidates[ni * N + nj].set(num_obs_group - 1);
      }
    }
  }

  bool success = false;
  vector<bitset<MAX_OBS_GROUPS>> v;
  v.reserve(obs_candidates.size());
  for (auto &&x : obs_candidates) {
    v.emplace_back(x.second);
  }

  if (num_obs_group == 0) {
    success = true;
  }

  // potential duplication is intended
  for (size_t i = 0; i < v.size(); i++) {
    for (size_t j = i; j < v.size(); j++) {
      for (size_t k = j; k < v.size(); k++) {
        auto coverage = v[i] | v[j] | v[k];
        if (coverage.count() == num_obs_group) {
          success = true;
          goto exit_loop;
        }
      }
    }
  }
exit_loop:

  cout << (success ? "YES" : "NO") << endl;
  return 0;
}
