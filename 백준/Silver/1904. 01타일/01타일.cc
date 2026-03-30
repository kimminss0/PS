#include <stdio.h>

int arr[1000000];

int func(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    for(int i = 3; i <= n; ++i)
        arr[i - 1] = (arr[i - 2] + arr[i - 3]) % 15746;
    return arr[n-1];
}

int main(void)
{
    int N;
    int res;
    scanf("%d", &N);
    arr[0] = 1;
    arr[1] = 2;
    res = func(N);
    printf("%d", res);
    
    return 0;
}