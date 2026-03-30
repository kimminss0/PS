#include <stdio.h>
#include <stdlib.h>

int w[5000];

int comp(const void* a, const void* b);
int b_search(int r, int n);
int func(int r, int c, int rank);

int main(void)
{
    int N, C;

    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", w+i);
    }

    qsort(w, N, sizeof(int), comp);

    printf("%d", func(N-1, C, 1));

    return 0;
}

int func(int r, int c, int rank)
{
    int lbd = b_search(r, c);
    if (w[lbd] == c)
    {
        return 1;
    }
    else if (rank == 3 || lbd == -1)
    {
        return 0;
    }
    else
    {
        while (lbd > 0)
        {
            if (func(lbd - 1, c - w[lbd], rank + 1))
            {
                return 1;
            }
            --lbd;
        }
        return 0;
    }
}



int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int b_search(int r, int n)
{
    int l = 0;

    while (l < r)
    {
        int mid = (l + r + 1) / 2;

        if (w[mid] <= n)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (l > n)
    {
        return -1;
    }
    return l;
    
}