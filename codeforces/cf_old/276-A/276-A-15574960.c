#include<stdio.h>
int main()
	{
	long long int n,k,f,t,max=-1000000000;
	scanf("%I64d%I64d",&n,&k);
	while(n--)
		{scanf("%I64d%I64d",&f,&t);
		if(k>t&&max<f)
			max=f;
		else if(max<f-(t-k)&&k<=t)
			max=f-(t-k);
		}
	printf("%I64d",max);
	return 0;}