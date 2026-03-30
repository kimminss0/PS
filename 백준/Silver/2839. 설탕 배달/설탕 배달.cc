#include <iostream>

int mem[5001] = {0};

int func(int n) {
    int a, b;
    if (n < 3) {
        return -1;
    }
    if (!mem[n]) {
        a = func(n-3);
        b = func(n-5);
        if (a == -1 || b == -1) {
            mem[n] = a==-1 ? b : a;
            if (mem[n] != -1) {
                ++mem[n];
            }
        }
        else {
            mem[n] = (a<b?a:b) + 1;
        }
    }
    return mem[n];
}

using namespace std;
int main(void) {
    int N;
    cin >> N;
    mem[3] = 1;
    mem[5] = 1;
    cout << func(N);
}