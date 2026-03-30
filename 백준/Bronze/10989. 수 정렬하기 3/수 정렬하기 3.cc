#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, tmp;
    int cnt[10000];
    for (int i = 0; i < 10000; i++)
        cnt[i] = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        cnt[tmp-1]++;
    }

    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < cnt[i]; j++)
            printf("%d\n", i+1);
}