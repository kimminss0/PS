#include <algorithm>
#include <iostream>
using namespace std;
pair<int, int> v[100000];
int main(void) {
  int N;
  cin >> N;
  for (auto &p : v) {
    cin >> p.second >> p.first;
  }
  sort(v, v + N);
  int cnt = 0, t = 0;
  for (auto &p : v) {
    if (p.second >= t) {
      t = p.first;
      ++cnt;
    }
  }
  cout << cnt;
}