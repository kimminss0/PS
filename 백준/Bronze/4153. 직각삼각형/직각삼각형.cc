#include <stdio.h>

int main(void) {
    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if ((a|b|c) == 0)
            break;
        if ((c*c == a*a + b*b) | (b*b == a*a + c*c) | (a*a == c*c + b*b))
            printf("right\n");
        else
            printf("wrong\n");
    }
}