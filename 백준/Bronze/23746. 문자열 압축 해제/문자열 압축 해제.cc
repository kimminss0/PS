#include <stdio.h>
#define FLUSH   while (getchar() != '\n') {}

int l_case[26][1001];
int u_case[26];
int str[1001];

int main(void)
{
    int N;
    int S, E;
    int cur;
    int cnt;
    int p;
    char ch;
    scanf("%d", &N);
    FLUSH;

    for (int i = 0; i < N; ++i)
    {
        cur = 0;

        do
        {
            ch = getchar();
            l_case[i][cur++] = ch - 'a';
        } while (ch != ' ');
        l_case[i][--cur] = -1;

        u_case[i] = getchar() - 'A';

        FLUSH;
    }

    cur = 0;
    do
    {
        ch = getchar();
        str[cur++] = ch - 'A';
    } while (ch != '\n');
    str[--cur] = -1;

    scanf("%d %d", &S, &E);

    cur = 0;
    cnt = 0;

    while (1)
    {
        int tmp = str[cur++];
        int *foo;
        int bar = 0;
        p = 0;
        
        while (u_case[p++] != tmp) {}
        --p;

        foo = l_case[p];
        while (foo[bar] != -1)
        {
            ++cnt;
            if (cnt >= S && cnt <= E)
            {
                printf("%c", foo[bar] + 'a');
            }
            if (cnt == E)
            {
                return 0;
            }
            ++bar;
        }

    }
}