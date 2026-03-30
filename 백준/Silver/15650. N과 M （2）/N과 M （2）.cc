#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    void *next;
} N_;

void func(N_*, int, int, int, int);
int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    func(NULL, 1, N, M, 0);
    return 0;
}

void func(N_* foo, int min, int N, int M, int len)
{
    if(len == M)
    {
        int* arr = (int*)malloc(sizeof(int) * M);
        while(len--)
        {
            arr[len] = foo->data;
            foo = (N_*)(foo->next);
        }
        for(int i = 0; i < M; ++i)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    while(min <= N)
    {
        int new_min = min + 1;
        N_ bar;
        bar.data = min;
        bar.next = (void*)foo;
        func(&bar, new_min, N, M, len + 1);
        ++min;
    }
}