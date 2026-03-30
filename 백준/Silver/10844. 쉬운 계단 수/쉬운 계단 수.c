#include <stdio.h>
#define DIV 1000000000

int mem[101][11];

int main(void)
{
    int N, ans = 0;
    mem[0][1] = 1;
    for(int i = 1; i < 10; ++i)
        mem[1][i] = 1;
    scanf("%d", &N);
    
    for(int n = 2; n <= N; ++n)
    {
        for(int i = 1; i < 10; ++i)
        {
            mem[n][i] = (mem[n-1][i-1] + mem[n-1][i+1]) % DIV;
        }
        mem[n][1] = (mem[n][1] + mem[n-2][1]) % DIV;
    }
    for(int i = 1; i < 10; ++i)
        ans = (ans + mem[N][i]) % DIV;
    printf("%d", ans);
    return 0;
}