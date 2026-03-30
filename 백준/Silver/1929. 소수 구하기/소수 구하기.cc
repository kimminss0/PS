#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0)
            cnt++;
        if (cnt > 2)
            break;
    }
    if (n != 1)
        cnt++;
    return cnt;

}

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);
    int *arr = (int*)malloc(sizeof(int)*(N-M));

    for (int i = M; i <= N; i++) {
        if (func(i) == 2)
            printf("%d\n", i);
    }

    return 0;
}