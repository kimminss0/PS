#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y) {int a = (x); (x) = (y); (y) = a;}

int comp(const void* a, const void* b);
int main(void)
{
    int N, d;
    int *arr;

    scanf("%d %d", &N, &d);
    arr = (int*)malloc(sizeof(int) * d);
    for(int i = 0; i < d; ++i)
    {
        arr[i] = i;
    }

    while(1)
    {
        int foo = d - 2;
        int bar = 0;
        int p;
        while(1)
        {
            if(foo < 0)
            {
                printf("%d", -1);
                return 0;
            }

            if(arr[foo] > arr[foo + 1])
            {
                --foo;
                continue;
            }

            p = foo;
            for(int i = foo; i < d; ++i)
            {
                if(arr[i] < arr[foo])
                    break;
                p = i;
            }
            SWAP(arr[foo], arr[p]);
            qsort(arr + foo + 1, d - (foo + 1), sizeof(int), comp);
            break;
        }

        if(arr[0] == 0)
        {
            continue;
        }

        for(int i = 0; i < d; ++i)
        {
            bar *= d;
            bar += arr[i];
        }
        if (bar > N)
        {
            printf("%d", bar);
            return 0;
        }
        
    }
}

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}