#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  cin >> N;
  vector<int> vec(N);
  for (auto &v : vec) {
    cin >> v;
  }
  sort(vec.begin(), vec.end());
  cin >> M;
  int t;
  for (int i = 0; i < M; ++i) {
    cin >> t;
    cout << upper_bound(vec.begin(), vec.end(), t) -
                lower_bound(vec.begin(), vec.end(), t)
         << ' ';
  }
}