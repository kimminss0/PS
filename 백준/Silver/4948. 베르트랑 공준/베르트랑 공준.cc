#include <stdio.h>

int main(void) {
    int n = 0, cnt = 0;

    int arr[123456*2+1] = {0,};
    arr[1] = -1;
    for (int i = 2; i < 123456*2;) {
        for (int j = 2; i*j <= 123456*2; j++)
            arr[i*j] = -1;
        i++;
        while(arr[i] == -1)
            i++;
    }

    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        cnt = 0;
        for (int i = n+1; i <= 2*n; i++)
            if (arr[i]==0) cnt++;
        printf("%d\n", cnt);
    }
}