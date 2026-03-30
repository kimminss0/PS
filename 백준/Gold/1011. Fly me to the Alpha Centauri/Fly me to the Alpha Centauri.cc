#include <stdio.h>
#include <math.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int dis = y-x;
        int max_sp = (int)((sqrt(dis)));
        int res = 2*max_sp-1;

        if (dis - pow(max_sp,2) > 0)
            res++;
        if (dis - pow(max_sp,2) > max_sp) 
            res++;
        if (dis - pow(max_sp,2) > 2*max_sp)
            res++;
        printf("%d\n", res);
    }
}