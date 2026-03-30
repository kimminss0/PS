#include <cmath>
#include <iostream>
using namespace std;

int fG(int a, int b) {
  if (!(b % a)) { return a; }
  return fG(b % a, a);
}

int main(void) {
  int L, G;
  cin >> G >> L;
  const int M = L / G;
  int m = sqrt(M);
  while (1) {
    if (!(M % m) && fG(m, M/m) == 1) {
      cout << m * G << ' ' << M / m * G;
      break;
    }
    --m;
  }
}