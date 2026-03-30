#include <stdio.h>
#include <stdlib.h>

void func(int**, int, int, int);

int main(void) {
    int N;
    scanf("%d", &N);
    int **arr = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; i++)
        arr[i] = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N*N; i++)
        arr[i/N][i%N] = 0;
    func(arr, N, 0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (arr[i][j])
                printf("*");
            else
                printf(" ");
        printf("\n");
    }

}

void func(int** arr, int N, int x, int y) {
    if (N == 1) {
        arr[x][y] = 1;
        return;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!(i == 1 && j == 1))
                func(arr, N/3, x+N/3*i, y+N/3*j);
    return;
}