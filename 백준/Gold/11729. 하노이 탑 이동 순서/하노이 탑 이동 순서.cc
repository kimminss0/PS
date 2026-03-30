#include <stdio.h>

int func1(int N) {
    if (N==1)
        return 1;
    return func1(N-1) * 2 + 1;
}
void func2(int N, int a, int b) {
    if (N==1) {
        printf("%d %d\n", a, b);
        return;
    }
    func2(N-1, a, 6/(a*b));
    printf("%d %d\n", a, b);
    func2(N-1, 6/(a*b), b);
}
int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d\n", func1(N));
    func2(N, 1, 3);
}

