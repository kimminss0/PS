#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int func(vector<int> &vec, int H) {
  long long ret{0};
  for (auto v : vec) {
    ret += max(v-H, 0);
  }
  ret = min(2000000001ll, ret);
  return static_cast<int>(ret);
}

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  int hi{0};
  cin >> N >> M;
  vector<int> vec(N);
  for (auto &v : vec) {
    cin >> v;
    hi = max(hi, v);
  }
  int lo{0}, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    if (func(vec, mid) >= M) {
      lo = mid;
    }
    else {
      hi = mid - 1;
    }
  }
  cout << hi;
}