#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    
    int i = 0;
    int M = 665;
    while (i < N) {
        M++;
        int tmp = M;
        int cnt = 0;
        int next = 0;
        do {
            if (tmp % 10 == 6)
                cnt++;
            else
                cnt = 0;
            if (cnt == 3) next = 1;
            tmp /= 10;
        }
        while (tmp != 0);

        if (next) i++;
    }
    printf("%d", M);
}