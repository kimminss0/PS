#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int* left, int* right);
int comp(const void* a, const void* b);


int main(void)
{
    int N;
    char* cmp;

    scanf("%d", &N);
    char **arr = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = (char*)malloc(sizeof(char)*51);
        scanf("%s", arr[i]);
    }
    qsort(arr, N, sizeof(char*), comp);

    for(int i = 0; i < N; ++i)
    {
        if(i == 0 || comp(&cmp, &arr[i]) != 0)
        {
            printf("%s\n", arr[i]);
            cmp = arr[i];
        }
    }
    
    return 0;
}

int comp(const void* a, const void* b)
{
    int a_i = 0;
    int b_i = 0;
    int i = 0;
    while((*(char**)a)[a_i++]);
    while((*(char**)b)[b_i++]);
    if(a_i - b_i)
        return a_i - b_i;
    while(!((*(char**)a)[i] - (*(char**)b)[i]) && i < a_i) ++i;
    return ((*(char**)a)[i] - (*(char**)b)[i]);
}