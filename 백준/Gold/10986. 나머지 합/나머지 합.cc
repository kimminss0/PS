#include <iostream>
#include <vector>

using namespace std;
int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> r(M, 0);
  ++r[0];
  int s = 0, t;
  for (int i = 0; i < N; ++i) {
    cin >> t;
    s = (s + t) % M;
    ++r[s];
  }
  long long cnt = 0;
  for (const auto &v : r) {
    cnt += (v * (v - 1ll)) / 2;
  }
  cout << cnt;
}