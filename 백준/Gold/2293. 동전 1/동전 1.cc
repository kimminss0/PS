#include <iostream>

using namespace std;
int main(void) {
    int n, k;
    int va[100];
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
    }
    int mem[10001] = {0};
    mem[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = va[i]; j <= k; ++j) {
            mem[j] += mem[j-va[i]];
        }
    }
    cout << mem[k];
}