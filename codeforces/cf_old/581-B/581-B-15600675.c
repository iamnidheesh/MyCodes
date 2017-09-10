#include<stdio.h>
int main()
	{
	long long int n,a[100000],i,max=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=n-1;i>=0;i--)
		{
		if(a[i]>max)
			{max=a[i];a[i]=0;}
		else
			a[i]=max+1-a[i];
		}
	for(i=0;i<n;i++)
		printf("%lld ",a[i]);
	return 0;
	}