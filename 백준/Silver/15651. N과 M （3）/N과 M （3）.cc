#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M;
    int* arr;
    int foo = 1;

    scanf("%d %d", &N, &M);
    arr = (int*)malloc(sizeof(int) * M);
    for(int i = 0; i < M; ++i)
    {
        arr[i] = 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    while(1)
    {
        if(foo > M)
        {
            break;
        }
        ++arr[M-foo];
        if(arr[M-foo] == N + 1)
        {
            arr[M-foo] = 1;
            ++foo;
            continue;
        }
        foo = 1;
        for(int i = 0; i < M; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}