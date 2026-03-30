#include <stdio.h>

int main(void) {
    long long int A, B, V;
    scanf("%lld %lld %lld", &A, &B, &V);

    printf("%lld", (long long int)(1e9-(long long int)(1e9-((double)(V-B)/(A-B)))));

    return 0;
}