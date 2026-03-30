#include <stdio.h>

int T[101];

int main(void)
{
    int N;
    int cnt = 0;
    int cur = 1;
    int lim;

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", T+i);
    }


    lim = 30;
    while (cur <= N)
    {
        if (lim >= T[cur])
        {
            lim -= T[cur++];
            ++cnt;
            if (lim == 0)
            {
                lim = 30;
            }
        }
        else
        {
            if (lim * 2 >= T[cur++])
            {
                ++cnt;
            }
            lim = 30;
        }
    }

    printf("%d", cnt);

    return 0;
}