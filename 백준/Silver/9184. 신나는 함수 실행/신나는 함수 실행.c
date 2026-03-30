#include <stdio.h>

int arr[20][20][20];
int arr2[20][20][20];

int func(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return func(20, 20, 20);
    if(arr2[a][b][c] == 1)
        goto RET;
    arr2[a][b][c] = 1;
    if(a < b && b < c)
        arr[a][b][c] = func(a,b,c-1) + func(a,b-1,c-1) - func(a,b-1,c);
    arr[a][b][c] = func(a-1,b,c) + func(a-1,b-1,c) + func(a-1,b,c-1) - func(a-1,b-1,c-1);
RET:
    return arr[a][b][c];
}

int main(void)
{   
    int a, b, c, res;
    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1)
            break;
        res = func(a, b, c);
        printf("w(%d, %d, %d) = %d\n", a, b, c, res);
    }
    return 0;
}