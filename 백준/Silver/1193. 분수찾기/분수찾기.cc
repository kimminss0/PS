#include <stdio.h>
#include <math.h>
#define max(a,b) (((a)>(b))?(a):(b))

int main(void){
    int X, i, j, a_i, b_j, k, l;
    scanf("%d", &X);
    i = (int)((1+sqrt(8*X+1))/4);
    a_i = i * (2*i-1);
    j = (int)((3+sqrt(8*X-7))/4);
    b_j = 1 + (2*j-1) * (j-1);
    k = X - a_i;
    l = X - b_j;
    printf("%d", max(1, (int)(2*i+1-fabs(k-(2*i+1)))));
    printf("/%d", max(1, (int)(2*j-fabs(l-(2*j-1)))));

    return 0;
}