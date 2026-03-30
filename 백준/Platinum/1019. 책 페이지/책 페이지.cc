#include <cstdio>
long long f(long long n, int i, int t) {
  if (n<10) {
    return (i!=0 || !t) && i <= n;
  }
  long long m = 1;
  int k = 0;
  while (n/m) {
    m *= 10;
    ++k;
  }
  m /= 10;
  --k;
  
  long long a = (t&&i==0?n/m-1:n/m) * (k * m/10);
  if (i==0 && t) {
    a += f(m-1, i, 1);
  }
  if (i<n/m) {
    if (i!=0 || !t) {
      a += m;
    }
  }
  const long long foo = n - m*(n/m);
  a += f(foo, i, 0);
  if (i == n/m) {
    a += foo + 1;
  }
  if (i == 0) {
    m /= 10;
    while (m/10 && foo/m == 0) {
      m /= 10;
      a += foo + 1;
    }
  }
  return a;
}
int main(void) {
  long long N;
  scanf("%lld", &N);
  for (int i = 0; i < 10; ++i) {
    printf("%lld ", f(N, i, 1));
  }
}