#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int main(void) {
    char a[10001], b[10001], ans[10001];
    scanf("%s %s", a, b);
    
    int i = 0;
    while (a[i] != 0)
        i++;
    int a_done = i - 1;

    i = 0;
    while (b[i] != 0)
        i++;
    int b_done = i - 1;

    int max_a_b = max(a_done, b_done);
    ans[max_a_b + 1] = 0;

    int ceil = 0;
    int triggered_a = 0;
    int triggered_b = 0;
    for (int iter = 0; iter <= max_a_b; iter++) {
        if (a[a_done - iter] == 0)
            triggered_a = 1;
        if (b[b_done - iter] == 0)
            triggered_b = 1;
        int foo = ((triggered_a == 0) ? a[a_done - iter] - '0' : 0);
        int bar = ((triggered_b == 0) ? b[b_done - iter] - '0' : 0);
        ans[max_a_b - iter] = ((foo + bar + ceil) % 10) + '0';
        ceil = (int)((foo + bar + ceil) / 10);
    }
    if (ceil == 1)
        printf("%d", ceil);
    printf("%s", ans);

    return 0;
}