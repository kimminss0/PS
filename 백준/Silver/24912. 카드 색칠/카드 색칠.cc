#include <stdio.h>
#include <stdlib.h>

int func(int* l, int* r);
void func2(int* cur);
int main(void)
{
    int N;
    int *arr;
    int *l;

    scanf("%d", &N);
    arr = (int*)malloc(sizeof(int) * (N + 2));
    l = arr;
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", arr+i);
    }
    arr[0] = 0;
    arr[N + 1] = 0;
    
    while(l <= arr + N)
    {
        int *r;
        r = l + 1;
        while(*r == 0 && r <= arr + N) ++r;
        if(func(l, r) == 1)
        {
            printf("%d", -1);
            return 0;
        }
        l = r;
    }
    for(int i = 1; i <= N; ++i)
    {
        printf("%d ", *(arr+i));
    }
    return 0;
}

int func(int* l, int* r)
{
    int* cur = l + 1;
    int color = 1;
    if(r - l == 1)
    {
        if(*l == 0 || *r == 0)
            return 0;
        else
            return 1;
    }
    if(r - l == 2)
    {
        func2(l + 1);
    }
    else if(r - l == 3)
    {
        func2(l + 1);
        func2(l + 2);
    }
    else
    {
        *cur = color;
        while(cur < r)
        {
            *cur = color++;
            color = 1 + (color - 1) % 3;
            ++cur;
        }
        func2(l + 1);
        func2(r - 1);
    }
    return 0;
}

void func2(int* cur)
{
    int *l = cur - 1;
    int *r = cur + 1;
    int color = 1;

    *cur = color;
    while(*cur == *l || *cur == *r)
    {
        *cur = color++;
        color = 1 + (color - 1) % 3;
    }
}