#include <stdio.h>
#include <stdlib.h>

int arr[1000] = {0,};

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
    int N, cnt = 0;
    scanf("%d", &N);
    int *arr = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &(arr[i]));
        if (func(arr[i]) == 2) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}