#include <stdio.h>

int main(void){
    int T;
    int R[1000];
    char S[1000][21];

    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %s", &(R[i]), &(S[i]));
    }

    for(int i = 0; i < T; i++){
        int foo = 0;
        while(1){
            if(S[i][foo] == '\0'){
                break;
            }
            for(int j = 0; j < R[i]; j++){
                printf("%c", S[i][foo]);
            }
            foo++;
        }
        printf("\n");
    }
}