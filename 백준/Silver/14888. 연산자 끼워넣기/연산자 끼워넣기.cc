#include <stdio.h>
#include <stdlib.h>

int N, n_sum, n_sub, n_mul, n_div, n_op;
int max = (int)-1e9, min = (int)1e9;
int *arr;

void func(int cur)
{
    if(n_op == 0)
    {
        if(cur > max)
            max = cur;
        if(cur < min)
            min = cur;
        return;
    }
    if(n_sum > 0)
    {
        --n_sum;
        --n_op;
        func(cur + arr[N - (n_op + 1)]);
        ++n_sum;
        ++n_op;
    }
    if(n_sub > 0)
    {
        --n_sub;
        --n_op;
        func(cur - arr[N - (n_op + 1)]);
        ++n_sub;
        ++n_op;
    }
    if(n_mul > 0)
    {
        --n_mul;
        --n_op;
        func(cur * arr[N - (n_op + 1)]);
        ++n_mul;
        ++n_op;
    }
    if(n_div > 0)
    {
        --n_div;
        --n_op;
        func(cur / arr[N - (n_op + 1)]);
        ++n_div;
        ++n_op;
    }
    
}

int main(void)
{
    scanf("%d", &N);
    n_op = N - 1;
    arr = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", arr + i);
    }
    scanf("%d %d %d %d", &n_sum, &n_sub, &n_mul, &n_div);

    func(arr[0]);

    printf("%d\n%d", max, min);
    free(arr);
    return 0;
}