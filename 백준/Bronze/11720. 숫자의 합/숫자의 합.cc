#include <stdio.h>

int main(void){
    int N;
    char strings[101];
    scanf("%d", &N);
    scanf("%s", strings);    
    
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += (strings[i] - '0');
    }
    printf("%d", sum);

    return 0;
}