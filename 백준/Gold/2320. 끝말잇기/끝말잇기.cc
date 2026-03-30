#include <iostream>
using namespace std;
const int MAX = 1<<12;
int dp[16][1<<16];
int route[16][3];
int N;
inline int dict(char c) {
    switch (c) {
        case 'A' : return 0;
        case 'E' : return 1;
        case 'I' : return 2;
        case 'O' : return 3;
        case 'U' : default : return 4;
    }
}
int f(int cur, int mask) {
    int &d = dp[cur!=-1?cur:0][mask];
    if (d) { return d; }
    for (int i = 0; i < N; ++i) {
        if (!(mask&1<<i)&&(cur==-1||route[cur][1]==route[i][0])) {
            d = max(d, f(i, mask|1<<i));
        }
    }
    d += (cur!=-1?route[cur][2]:0);
    if (d == 0) { d = -1; }
    return d;
}
int main(void) {
    cin>>N;
    for (int i = 0; i < N; ++i) {
        string w;
        cin>>w;
        route[i][0] = dict(w.front());
        route[i][1] = dict(w.back());
        route[i][2] = w.length();
    }
    cout<<f(-1, 0);
}