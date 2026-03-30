#include <iostream>
const int p = 1000000007;
int N, K;
int mem[51];
int m2[52][52];
int pw(long long a, int b) {
  long long ret = 1;
  b %= p;
  a %= p;
  while (b > 0) {
    if (b&1) {
      ret *= a;
      ret %= p;
    }
    a *= a;
    a %= p;
    b >>= 1;
  }
  return ret;
}
int ff(int a, int b) {
  long long ret = 0;
  b %= p;
  a %= p;
  while (b > 0) {
    if (b&1) {
      ret += a;
      ret %= p;
    }
    a *= 2;
    a %= p;
    b >>= 1;
  }
  return ret;
}
int m(int n, int r) {
  if (r==0 || r==n) { return 1; }
  if (!m2[n][r]) {
    m2[n][r] = (m(n-1,r-1) + m(n-1,r)) % p;
  }
  return m2[n][r];
}
int main(void) {
  std::cin>>N>>K;
  mem[0] = N;
  for (int i = 1; i <= K; ++i) {
    const int foo = pw(i+1, p-2);
    long long s = pw(N+1, i+1) - 1;
    for (int j = 0; j < i; ++j) {
      s -= ff(m(i+1, j), mem[j]);
      s = (s + p) % p;
    }
    mem[i] = ff(foo, s);
  }
  std::cout<<mem[K];
}