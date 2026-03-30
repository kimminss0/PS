#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T;
    int *arr, *rarr;
    int barr[32];
    scanf("%d", &T);
    arr = (int*)malloc(sizeof(int)*T);
    rarr = (int*)malloc(sizeof(int)*T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", arr+i);
    }
    for (int i = 0; i < T; ++i) {
        for (int b = 2; b <= 64; ++b) {
            int n = arr[i];
            int d = 0;
            while (n) {
                barr[d++] = n % b;
                n /= b;
            }
            barr[d] = -1;
            rarr[i] = 1;
            for (int j = 0; j < d/2; ++j) {
                if (barr[j] != barr[d-j-1]) {
                    rarr[i] = 0;
                    break;
                }
            }
            if (rarr[i] == 1) break;
        }
    }
    for (int i = 0; i < T; ++i) {
        printf("%d\n", rarr[i]);
    }
    return 0;
}