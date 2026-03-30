#include <stdio.h>

int main(void){
    int N;
    char voca[100][101];

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", &(voca[i]));
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        int pos = 0;
        int isGroupVoca = 1;
        int test[26];
        int prevLetter = -1;

        for(int j = 0; j < 26; j++){
            test[j] = 0;
        }

        while(1){
            if(voca[i][pos] == '\0'){
                break;
            }
            int curLetter = voca[i][pos] - 'a';
            if(prevLetter - curLetter != 0){
                if(test[curLetter] != 0){
                    isGroupVoca = 0;
                }
            }
            test[curLetter] ++;

            prevLetter = curLetter;
            pos++;
        }
        cnt += isGroupVoca;
    }
    printf("%d", cnt);

    return 0;
}