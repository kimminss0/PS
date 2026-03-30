#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T;
    scanf("%d", &T);
    int* H = (int *)malloc(sizeof(int) * T);
    int* W = (int *)malloc(sizeof(int) * T);
    int* N = (int *)malloc(sizeof(int) * T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &H[i], &W[i], &N[i]);
    }

    for (int i = 0; i < T; i++) {
        int X, Y;
        X = ((N[i]-1) % H[i]) + 1;
        Y = (int)(1e4 - (int)(1e4 - ((double)N[i] / H[i])));
        printf("%d%02d\n", X, Y);
    }
    
    return 0;
}