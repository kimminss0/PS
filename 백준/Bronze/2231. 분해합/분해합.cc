#include <stdio.h>

int main(void) {
    int N, M=0, k=0, sum;
    scanf("%d", &N);
    
    int tmp = N;
    do{
        tmp /= 10;
        k++;
    }
    while(tmp != 0);

   
    for (int i = N-9*k; i < N; i++) {
        tmp = i;
        sum = i;
        for (int j = 0; j < k; j++) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N)
            if (i < M || M == 0)
                M = i;
    }
    printf("%d", M);
        
}