#include<cstdio>
#include<bitset>
std::bitset<1000001>s;long long m,M,i,k,n,c;int main(void){scanf("%lld%lld",&m,&M);for(i=3,n=9;n<=M;i+=2,n=i*i)for(k=n-(m-1)%n-1;k<=M-m;k+=n)if(!s[k]&&(k+m)%4)s[k]=1,--c;printf("%lld",c+M-m+1-M/4+(m-1)/4);}