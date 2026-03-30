#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> dp(n+1);
  dp[0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = n; j >= 0; j--) {
      for (int s = 0; s < j; s++) {
        dp[j] = (dp[j] + dp[s]) % 1000000000;
      }
    }
  }
  cout << dp.back();
  return 0;
}