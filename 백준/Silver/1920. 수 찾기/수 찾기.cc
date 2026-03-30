#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[100000];
int m_arr[100000];

int comp(const void* a, const void* b);
int getExistence(int x, int* l, int* r);

int main(void)
{
    int N, M;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", arr+i);
    scanf("%d", &M);
    for(int i = 0; i < M; ++i)
        scanf("%d", m_arr+i);

    qsort(arr, N, sizeof(int), comp);

    for(int i = 0; i < M; ++i)
    {
        printf("%d\n", getExistence(m_arr[i], arr, arr+N));
    }

    return 0;    
}

int getExistence(int x, int* l, int* r)
{
    int* mid = l + (r - l) / 2;
    if(r - l == 1)
    {
        if(*l == x) return 1;
        return 0;
    }
    if(comp(&x, mid) < 0) return getExistence(x, l, mid);
    return getExistence(x, mid, r);
}

int comp(const void* a, const void* b)
{
    if (*((int*)a) > *((int*)b)) return 1;
    if (*((int*)a) < *((int*)b)) return -1;
    return 0;
}