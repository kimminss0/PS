#include <stdio.h>
#include <stdlib.h>

int dirs[8][2] = {{0,-1}, {0,1}, {-1,-1}, {-1,0}, {-1,1}, {1,-1}, {1,0}, {1,1}};
char mbtis[4][2] = {{'E','I'},{'N','S'},{'T','F'},{'P','J'}};
int main(void) {
    int N, M, cnt = 0;
    char board[201][201];
    int* dir;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf(" %c", &board[i][j]);
        }
    }
    for (int i = 0; i < 8; ++i) {
        dir = dirs[i];
        for (int row = (dir[0]<0 ? 3 : 0); row < N - (dir[0]>0 ? 3 : 0); ++row) {
            for (int col = (dir[1]<0 ? 3 : 0); col < M - (dir[1]>0 ? 3 : 0); ++col) {
                int ncol = col;
                int nrow = row;
                for (int foo = 0; foo < 4; ++foo) {
                    if (board[nrow][ncol] != mbtis[foo][0] && board[nrow][ncol] != mbtis[foo][1]) {
                        break;
                    }
                    if (foo == 3) {
                        ++cnt;
                    }
                    nrow += dir[0];
                    ncol += dir[1];
                }          
            }
        }
    }
    printf("%d", cnt);
    return 0;
}