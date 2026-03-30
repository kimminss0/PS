#include <iostream>
#include <stack>

using namespace std;
int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, x, y, cnt(0);
  stack<int> s;
  s.push(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    while (y < s.top()) {
      s.pop();
      ++cnt;
    }
    if (y > s.top()) {
      s.push(y);
    }
  }
  cout << cnt + s.size() - 1;
}