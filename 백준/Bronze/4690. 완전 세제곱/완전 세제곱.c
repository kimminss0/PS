#include <stdio.h>
#include <math.h>
#define P(x) ((int)pow(x,3))
int main(void) {
    for (int a = 2; a <= 100; ++a) {
        int b, c, d;
        for (b = 2; b < a; ++b) {
            for (c = b; c < a; ++c) {
                for (d = c; d < a; ++d) {
                    if (P(a) == P(b)+P(c)+P(d)) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}