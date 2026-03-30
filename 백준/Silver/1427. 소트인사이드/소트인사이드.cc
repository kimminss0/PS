#include <stdio.h>
#include <stdlib.h>

int comp(void const *a, void const*b)
{
    return -(*(int*)a - *(int*)b);
}

int main(void)
{
    int N, cnt = 0;
    int arr[10];
    scanf("%d", &N);
    while (N != 0)
    {
        arr[cnt++] = N % 10;
        N /= 10;
    }
    qsort(arr, cnt, sizeof(int), comp);
    for (int i = 0; i < cnt; i++)
        printf("%d", arr[i]);
}