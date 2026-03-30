#include <iostream>
int mem[10001];
int va[100];

using namespace std;
int main(void) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
        if (va[i] <= k) {
            mem[va[i]] = 1;
        }
        for (int j = va[i]+1; j <= k; ++j) {
            int t = mem[j-va[i]];
            if (t && (!mem[j] || t+1 < mem[j])) {
                mem[j] = t+1;
            }
        }
    }
    cout << (mem[k] ? mem[k] : -1);
}