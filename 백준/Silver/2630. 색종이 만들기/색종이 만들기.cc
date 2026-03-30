#include <stdio.h>

int nw, nb;
int arr[128][128];

void func(int x, int y, int w);

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &(arr[i][j]));
            
    func(0, 0, N);

    printf("%d\n%d", nw, nb);
    return 0;
}

void func(int x, int y, int w)
{
    int foo = arr[x][y];

    for(int i = x; i < x + w; ++i)
    {
        for(int j = y; j < y + w; ++j)
        {
            if(arr[i][j] != foo)
            {
                w /= 2;
                func(x, y, w);
                func(x+w, y, w);
                func(x, y+w, w);
                func(x+w, y+w, w);
                return;
            }
        }
    }
    if(foo) ++nb;
    else    ++nw;
    return;
}