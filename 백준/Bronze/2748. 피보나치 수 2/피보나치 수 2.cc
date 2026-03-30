#include <stdio.h>

long long arr[91];


long long func(int n);
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%lld", func(n));	
}

long long func(int n)
{
	if(arr[n]!=0) return arr[n];
	if(n==0) return 0;
	if(n==1) return arr[1]=1;
	
	return arr[n]=func(n-1)+func(n-2);
}