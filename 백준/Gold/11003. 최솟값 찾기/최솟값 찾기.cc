#include <deque>
#include <iostream>
#include <utility>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  deque<pair<int, int>> dq; // idx, value

  int N, L;
  cin >> N >> L;

  for (int idx = 0; idx < N; idx++) {
    int val;
    cin >> val;
    while (!dq.empty() && val <= dq.back().second) {
      dq.pop_back();
    }
    dq.emplace_back(make_pair(idx, val));
    if (dq.front().first <= idx - L) {
      dq.pop_front();
    }
    cout << dq.front().second << " ";
  }
  return 0;
}
