#include<stdio.h>
int main()
	{
	long long int n,i,c=0,j=-1;
	scanf("%I64d",&n);
	for(i=1;i<=n;i=i*10)
		{c=c+(i-i/10)*(++j);if((i)*10>n){c=c+(j+1)*(n-i+1);break;}}
	printf("%I64d",c);
	return 0;
	}