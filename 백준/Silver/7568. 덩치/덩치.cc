#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int *x = (int*)malloc(sizeof(int)*N);
    int *y = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &(x[i]), &(y[i]));
    for (int i = 0; i < N; i++) {
        int R = 1;
        for (int j = 0; j < N; j++)
            if (x[j] > x[i] && y[j] > y[i])
                R++;
        printf("%d ", R);
    }
}