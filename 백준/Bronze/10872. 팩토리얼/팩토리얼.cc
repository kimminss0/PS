#include <stdio.h>

int func(int N) {
    if (N == 0)
        return 1;
    return N * func(N-1);
}

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d", func(N));
}