#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M, sum = 0;
    scanf("%d %d", &N, &M);
    int* cards = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++)
        scanf("%d", &(cards[i]));
    for(int i = 0; i < N-2; i++)
        for(int j = i+1; j < N-1; j++)
            for(int k = j+1; k < N; k++) {
                int tmp = cards[i] + cards[j] + cards[k];
                if (tmp > sum && tmp <= M)
                    sum = tmp;
            }
    printf("%d", sum);
}