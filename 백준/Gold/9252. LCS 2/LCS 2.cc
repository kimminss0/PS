#include <iostream>
#include <cstring>
#define MAX_LEN 1001

inline int max(int a, int b) {
    return a>b?a:b;
}

using namespace std;
int main(void) {
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    int mem[MAX_LEN][MAX_LEN] = {0};
    cin >> s1;
    cin >> s2;
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for (int j = 1; j <= l2; ++j) {
        for (int i = 1; i <= l1; ++i) {
            if (s1[i-1] == s2[j-1]) {
                mem[i][j] = mem[i-1][j-1] + 1;
            }
            else {
                mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
        }
    }
    int lc = mem[l1][l2];
    cout << lc << endl;
    if (lc) {
        char lcs[MAX_LEN];
        int c = 0;
        int i = l1, j = l2;
        while (i >= 1 && j >= 1) {
            if (s1[i-1] == s2[j-1]) {
                lcs[lc-++c] = s1[i-1];
                --i;
                --j;
            }
            else {
                if (mem[i-1][j] > mem[i][j-1]) {
                    --i;
                } else {
                    --j;
                }
            }
        }
        lcs[lc] = 0;
        cout << lcs;
    }
}