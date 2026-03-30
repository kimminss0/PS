#include <stdio.h>

int main(void){
    int A, B, C, iter;
    scanf("%d %d %d", &A, &B, &C);
    
    if(B-C >= 0){
        iter = -1;
    }
    else{
        iter = (int)(A/(C-B)) + 1;
    }

    printf("%d", iter);

    return 0;
}