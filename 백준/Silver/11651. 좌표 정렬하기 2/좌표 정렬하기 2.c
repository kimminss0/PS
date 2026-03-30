#include <stdio.h>
#include <stdlib.h>

int comp(void const* a, void const* b)
{
    return (((*(int**)a)[1]-(*(int**)b)[1]) * 200001ll + ((*(int**)a)[0]-(*(int**)b)[0]) < 0 ? -1 : 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    int **ang = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; i++)
        ang[i] = (int*)malloc(sizeof(int)*2);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &ang[i][0], &ang[i][1]);
    qsort(ang, N, sizeof(int*), comp);

    for (int i = 0; i < N; i++)
        printf("%d %d\n", ang[i][0], ang[i][1]);
}