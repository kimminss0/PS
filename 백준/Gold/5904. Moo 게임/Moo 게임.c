#include <stdio.h>

int len(int k);
char func(int N);

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%c", func(N));
}

int len(int k) {
    if (k == 0) {
        return 3;
    }
    return len(k-1) * 2 + (k+3);
}

char func(int N) {
    int k, tmp;
    for (k = 0; N >= len(k); ++k) {
        ;
    }
    if (k == 0) {
        return (N == 1) ? 'm' : 'o';
    }
    tmp = len(k-1) + (k+3);
    if (N <= tmp) {
        return (N==len(k-1)+1) ? 'm' : 'o';
    }
    return func(N-tmp);
}