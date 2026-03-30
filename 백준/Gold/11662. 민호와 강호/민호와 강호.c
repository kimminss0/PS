#include<stdio.h>
#include<math.h>
int main(void){int a,A,b,B,c,C,d,D,s,S;scanf("%d%d%d%d%d%d%d%d",&a,&A,&b,&B,&c,&C,&d,&D);s=b-a-d+c;S=B-A-D+C;double t=0;if(s||S){t=((c-a)*s+(C-A)*S);t/=(s*s+S*S);t=t>1?1:t<0?0:t;}printf("%.10f",sqrt(pow(a-c+t*s,2)+pow(A-C+t*S,2)));}