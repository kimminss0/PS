#include <cstdio>
const int p = 1000000007;
int f(int a, int n) {
  if (n==1) { return a; }
  long long r = f(a, n/2);
  r=r*r%p;
  return (n%2?a:1)*r%p;
}
int main(void) {
  int N, K, i;
  long long a, b = 1;
  scanf("%d%d", &N, &K);
  if (K>N-K) { K=N-K; }
  for (i=2; i<=K; ++i) {
    b=b*i%p;
  }
  a=b;
  for (; i<=N-K; ++i) {
    b=b*i%p;
  }
  a=a*b%p;
  for (; i<=N; ++i) {
    b=b*i%p;
  }
  printf("%d",b*f(a, p-2)%p);
}