#include <stdio.h>

int main(void){
    char S[100];
    int pos[26];
    scanf("%s", S);

    for(int i = 0; i < 26; i++){
        pos[i] = -1;
    }

    int i = 0;
    while(1){
        if(S[i] == '\0'){
            break;
        }
        int asdf = S[i] - 'a';
        if(pos[asdf] == -1){
            pos[asdf] = i;
        }
        i++;
    }

    for(int i = 0; i < 26; i++){
        printf("%d ", pos[i]);
    }
}