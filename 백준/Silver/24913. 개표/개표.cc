#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<long long> cnt(N + 1);
  long long max{0}, s{0}, tmp;
  int a, x, q;
  for (int i = 0; i < Q; ++i) {
    cin >> a >> x >> q;
    if (a == 1) {
      auto &c = cnt[q - 1];
      c += x;
      if (q != N + 1) {
        s += x;
        if (c > max) {
          max = c;
        }
      }
    } else {
      tmp = cnt[N] + x;
      if (tmp <= max || tmp <= (s + q - 1) / N + 1) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }
}