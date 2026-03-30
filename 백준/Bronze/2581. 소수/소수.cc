#include <stdio.h>
#include <stdlib.h>

int arr[10000] = {0,};

int func(int n) {
    if (arr[n-1] != 0)
        return arr[n-1];
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cnt++;

    arr[n-1] = cnt;
    return cnt;

}
int main(void) {
    int M, N, a = -1, b = 0;
    scanf("%d %d", &M, &N);
    for (int i = M; i <= N; i++) {
        int cnt = func(i);
        if (cnt==2) {
            if (a == -1)
                a = i;
            b += i;
        }
    }
    if (a != -1)
        printf("%d\n", b);
    printf("%d", a);

    return 0;

}