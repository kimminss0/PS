#include <stdio.h>
#include <math.h>
#define E 1e-7

int main(void) {
    int T, x1, y1, r1, x2, y2, r2, ans;
    double d;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = pow(pow(x2-x1, 2)+pow(y2-y1, 2), 0.5);
        if (d - (r1 + r2) > E || d - fabs(r1-r2) < -E)
            ans = 0;
        if (fabs(d - (r1 + r2)) < E || fabs(d - fabs(r1-r2)) < E)
            ans = 1;
        if (d - (r1 + r2) < -E && d - fabs(r1-r2) > E)
            ans = 2;
        if (d < E && fabs(r1-r2) < E)
            ans = -1;
        printf("%d\n", ans);
    }
}