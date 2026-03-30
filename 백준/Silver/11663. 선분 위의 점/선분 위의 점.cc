#include <stdio.h>
#include <stdlib.h>
#define MAX_THRESH 4

int point[100000];

int comp(const void* a, const void* b);

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", point + i);
    qsort(point, N, sizeof(int), comp);

    for(int i = 0; i < M; ++i)
    {
        int l, r, tmp;
        int a, b;
        scanf("%d %d", &a, &b);
        l = 0;
        tmp = N + 1;
        while(tmp - l > MAX_THRESH)
        {
            int mid = l + (tmp - l) / 2;
            
            if(a <= point[mid-1])
                tmp = mid;
            else
                l = mid;
        }
        while(point[l] < a && (N + 1) - l > 1 ) ++l;
        //--l;
        //r = 0;
        r = l;
        tmp = N + 1;
        while(tmp - r > MAX_THRESH)
        {
            int mid = r + (tmp - r) / 2;
            
            if(b < point[mid-1])
                tmp = mid;
            else
                r = mid;
        }
        while(point[r] <= b && (N + 1) - r > 1 ) ++r;
        printf("%d\n", r-l);
    }

    return 0;
}

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}