#include <stdio.h>

int main(void) {
    long long int N, X = 1;
    scanf("%lld", &N);

    int shell = 1;
    while(N > X) {
        X += 6 * shell;
        shell++;
    }
    printf("%d", shell);

    return 0;
}