#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int i = 2;
    while (1) {
        if (N == 1)
            break;
        if (N % i == 0) {
            printf("%d\n", i);
            N /= i;
        }
        else {
            i++;
        }
    }
}