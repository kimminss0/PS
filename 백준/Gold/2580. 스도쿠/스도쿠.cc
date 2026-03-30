#include <stdio.h>

int check(int (*arr)[9], int *zeros, int z_pointer, int z_len)
{
    if(z_pointer == z_len)
        return 1;
    int n = zeros[z_pointer];
    int row = n / 9;
    int col = n % 9;
    int block = 3 * (row / 3) + (col / 3);
    for(int i = 1; i <= 9; i++)
    {
        int able = 1;
        for(int a = 0; a < 9; a++)
            if(arr[row][a] == i)
                goto a;
        for(int b = 0; b < 9; b++)
            if(arr[b][col] == i)
                goto a;
        for(int c = 0; c < 9; c++)
            if(arr[3*(block/3)+(c/3)][3*(block%3)+(c%3)] == i)
                goto a;
        goto b;
a:
        able = 0;
b:
        if(able == 1)
        {
            arr[row][col] = i;
            int ret = check(arr, zeros, z_pointer + 1, z_len);
            if(ret == 1)
                return 1;
        }
    }
    arr[row][col] = 0;
    return 0;
}

int main(void)
{
    int arr[9][9];
    int zeros[81], z_len = 0;
    for(int i = 0; i < 81; i++)
    {
        int n;
        scanf("%d", &n);
        *((int*)arr+i) = n;
        if(n == 0)
        {
            zeros[z_len] = i;
            ++z_len;
        }

    }

    check(arr, zeros, 0, z_len);

    for(int i = 0; i < 81; i++)
    {
        printf("%d ", *((int*)arr+i));
        if(i % 9 == 8)
            printf("\n");
    }
    return 0;
}