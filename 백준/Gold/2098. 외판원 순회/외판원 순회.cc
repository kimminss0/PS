#include <iostream>
int cost[16][16];
int dp[16][1<<16];
int N;
const int init = 0;
const int MAX = 1<<30;
using namespace std;
int f(int cur, int mask) {
    static const int FULL = (1<<N)-1;
    int &d = dp[cur][mask];
    if (d) { return d; }
    if (mask==FULL && cost[cur][init]) {
        return d = cost[cur][init];
    }
    d = MAX;
    for (int i = 0; i < N; ++i) {
        if (!(mask&1<<i) && cost[cur][i]) {
            d = min(d, f(i, mask|1<<i)+cost[cur][i]);
        }
    }
    return d;
}
int main(void) {
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>cost[i][j];
        }
    }
    cout<<f(init,1<<init);
}