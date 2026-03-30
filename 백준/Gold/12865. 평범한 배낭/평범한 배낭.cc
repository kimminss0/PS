#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, w, v;
  cin >> n >> k;
  vector<int> dp(k+1);
  for (int i = 0; i < n; i++) {
    cin >> w >> v;
    for (int j = k; j >= w; j--) {
      dp[j] = max(dp[j], dp[j-w] + v);
    }
  }
  cout << dp.back();
  return 0;
}