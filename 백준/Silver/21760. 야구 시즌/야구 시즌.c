#include <stdio.h>

int main(void){
    int T, N, M, k, D, A, B, res, ans;
    int ans_[1000];
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d %d %d", &N,&M,&k,&D);
        ans = -1;
        for(B = 1; ; B++){
            A = k * B;
            res = (int)(M*(M-1)/2)*N * A + (int)(N*(N-1)/2) * M * M * B;
            if(res > D){
                break;
            }
            ans = res;
        }
    ans_[i] = ans;
    }
    for(int i = 0; i < T; i++){
        printf("%d\n", ans_[i]);
    }
    return 0;
}