#include <stdio.h>
#include <stdlib.h>

int k_arr[10000];

int comp(const void* a, const void* b);
int decision(int n, int K, int N);

int main(void)
{
    int K, N;
    int l, r;

    scanf("%d %d", &K, &N);
    for(int i = 0 ; i < K; ++i)
    {
        scanf("%d", k_arr + i);
    }
    qsort(k_arr, K, sizeof(int), comp);
    l = 1;
    r = k_arr[K-1];
    while(l<r)
    {
        int mid = (int)(((long long int)l + r + 1) / 2);
        if(decision(mid, K, N))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d", l);

    return 0;
}

int decision(int n, int K, int N)
{
    int ans = 0;
    for(int i = 0; i < K; ++i)
    {
        ans += k_arr[i] / n;
        if(ans >= N)
            return 1;
    }
    return 0;
}

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}