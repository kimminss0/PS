#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for (auto &v : A) {
    cin >> v;
  }
  for (auto &v : B) {
    cin >> v;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += A[i] * B[N - i - 1];
  }
  cout << sum;
}