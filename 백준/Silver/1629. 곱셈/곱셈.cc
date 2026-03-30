#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int A, B, C;
    long long int ans = 1;
    long long int tmp;

    scanf("%d %d %d", &A, &B, &C);

    tmp = A % C;
    for(int i = 0; i < 31 + 1; ++i)
    {
        if((B>>i) & 1)
        {
            ans *= tmp;
            ans %= C;
        }
        tmp *= tmp;
        tmp %= C;
    }

    printf("%lld", ans);

    return 0;
}