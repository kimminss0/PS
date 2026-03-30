#include <iostream>

using namespace std;
int main(void) {
    int C, N;
    int cost[100], inc[100];
    int mem[1001]={0};
    cin>>C>>N;
    for (int i=0; i<N; ++i) {
        cin>>cost[i]>>inc[i];
        for (int j=1; j<=C; ++j) {
            int t=cost[i];
            if (j-inc[i]>=0)
                t+=mem[j-inc[i]];
            if (t<mem[j]||i==0)
                mem[j]=t;
        }
    }
    cout<<mem[C];
}