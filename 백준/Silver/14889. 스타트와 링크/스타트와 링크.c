#include <stdio.h>
#include <stdlib.h>

int N, min = (int)1e9;
int **S;
int *arr;
int a, b;

void func(int sum_a, int sum_b)
{
    if(a + b == N)
    {
        int dif = sum_a - sum_b;
        dif = dif > 0 ? dif : -dif;
        if(dif < min)
        {
            min = dif;
            return;
        }
    }
    if(a < N/2)
    {
        int tmp = sum_a;
        arr[a + b] = 0;
        for(int i = 0; i < a + b; ++i)
        {
            if(arr[i] == 0)
            {
                tmp += S[i][a + b];
                tmp += S[a + b][i];
            }
        }
        ++a;
        func(tmp, sum_b);
        --a;
    }
    if(b < N/2)
    {
        int tmp = sum_b;
        arr[a + b] = 1;
        for(int i = 0; i < a + b; ++i)
        {
            if(arr[i] == 1)
            {
                tmp += S[i][a + b];
                tmp += S[a + b][i];
            }
        }
        ++b;
        func(sum_a, tmp);
        --b;
    }
}

int main(void)
{
    scanf("%d", &N);
    S = (int**)malloc(sizeof(int*) * N);
    for(int i = 0; i < N; ++i)
    {
        S[i] = (int*)malloc(sizeof(int) * N);
        for(int j = 0; j < N; ++j)
        {
            scanf("%d", &S[i][j]);
        }
    }
    arr = (int*)malloc(sizeof(int) * N);
    arr[0] = 0;
    a = 1;
    b = 0;
    func(0, 0);
    printf("%d", min);
    
    for(int i = 0; i < N; ++i)
    {
        free(S[i]);
    }
    free(S);
    return 0;
}