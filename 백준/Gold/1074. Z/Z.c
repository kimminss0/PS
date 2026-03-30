#include <stdio.h>

extern inline int len(int N) {
    return 1<<(N*2);
}

extern inline int foo(int N, int r, int c) {
    const int t1 = 1<<(N-1);
    const int t2 = len(N-1);
    return (r<t1 ? 0 : 2*t2) + (c<t1 ? 0 : t2);
}

int func(int N, int r, int c) {
    const int t = 1<<(N-1);
    if (N == 1) {
        return foo(N,r,c);
    }
    return func(N-1, r%t, c%t) + foo(N,r,c);
}

int main(void) {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d", func(N, r, c));
}
