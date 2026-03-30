#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b))

int main(void){
    int M, N, P, Q;
    scanf("%d %d", &M, &N);
    char **arr = (char**)malloc(sizeof(char *) * M);
    for (int i = 0; i < M; i++){
        arr[i] = (char*)malloc(sizeof(char) * (N+1));
    }
    for (int i = 0; i < M; i++){
        scanf("%s", arr[i]);
    }
    P = M - 8 + 1;
    Q = N - 8 + 1;
    int res = 8 * 8;

    for (int i = 0; i < P; i++){
        for (int j = 0; j < Q; j++){
            int A = 0, B = 0, C = 0, D = 0;
            for (int k = 0; k < 8; k++){
                for (int l = 0; l < 8; l++){
                    A += (arr[i+k][j+l] == 'W') & ((k+l) % 2 == 0);
                    B += (arr[i+k][j+l] == 'W') & ((k+l) % 2 == 1);
                    C += (arr[i+k][j+l] == 'B') & ((k+l) % 2 == 0);
                    D += (arr[i+k][j+l] == 'B') & ((k+l) % 2 == 1);
                }
            }
            int foo = min(A+D, B+C);
            if (res > foo){
                res = foo;
            }
        }
    }
    printf("%d", res);

    return 0;
}