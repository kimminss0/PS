#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int N, tmp;
    int cnt[8001] = {0,};

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        cnt[tmp + 4000]++;
    }
    int avg, med, mp, rng, mp_cnt;
    avg = med = rng = mp_cnt = tmp = 0;
    mp = -4000;
    int mp_cnting = 1;
    for (int i = 0; i < 8001; i++)
    {
        avg += (i - 4000) * cnt[i];
        tmp += cnt[i];
        if (cnt[i] != 0 && tmp - cnt[i] < (N+1)/2 && tmp > (N-1)/2)
            med = i - 4000;

        if (mp_cnt < cnt[i])
        {
            mp_cnting = 1;
            mp_cnt = cnt[i];
            mp = i - 4000;
        }
        else if (mp_cnt == cnt[i])
        {
            if (mp_cnting)
                mp = i - 4000;
            mp_cnting = 0;
        }
    }
    avg = (int)round((double)avg / N);
    int a = 0, b = 8000;
    while (cnt[a] == 0) a++;
    while (cnt[b] == 0) b--;
    rng = b - a;
    printf("%d\n%d\n%d\n%d",avg,med,mp,rng);

}