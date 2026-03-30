#include <stdio.h>

int mem[1000001];

int func(int n)
{
    int op1, op2, op3;
    int ret;

    if(n == 1)
        return 0;
    
    for(int i = 2; i <= n; ++i)
    {
        ret = mem[i - 1] + 1;
        if(i % 3 == 0)
            ret = ret > mem[i/3] + 1 ? mem[i/3] + 1 : ret;
        if(i % 2 == 0)
            ret = ret > mem[i/2] + 1 ? mem[i/2] + 1 : ret;
        mem[i] = ret;
    }
    return ret;
}

int main(void)
{
    int N, cnt;
    scanf("%d", &N);
    cnt = func(N);    
    printf("%d", cnt);
    return 0;
}