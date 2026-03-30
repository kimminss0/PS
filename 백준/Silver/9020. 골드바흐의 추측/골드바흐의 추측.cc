#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    int arr[10001] = {0,};
    arr[1] = -1;
    for (int i = 2; i <= 10000; i++) {
        if (arr[i] != 0) continue;
        for (int j = i*2; j <= 10000; j += i)
            arr[j] = -1;
    }

    for (int i = 0; i < T; i++) {
        int n, a;
        scanf("%d", &n);
        a = n / 2;
        while(1){
            if (arr[a] == 0 && arr[n-a] == 0)
                break;
            a--;
        }
        printf("%d %d\n", a, n-a);
    }
}