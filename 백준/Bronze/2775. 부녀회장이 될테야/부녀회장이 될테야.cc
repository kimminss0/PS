#include <stdio.h>

int main(void) {
    int T, arr[15][15];
    for (int i = 1; i <= 14; i++) {
        arr[0][i] = i;
    }
    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            int foo = 0;
            for (int iter = 1; iter <= j; iter++) {
                foo += arr[i-1][iter];
            }
            arr[i][j] = foo;
        }
    }
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int k, n;
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", arr[k][n]);
    }
    
    return 0;
}