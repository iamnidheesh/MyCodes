#include<stdio.h>
#include<stdlib.h>
int main()
	{
	long long int n,m,a;scanf("%I64d%I64d",&n,&m);
	if(m>abs(n-m)) if(n==1) a=1;else a=m-1;
	else a=m+1;
	printf("%I64d",a);
	return 0;
	}