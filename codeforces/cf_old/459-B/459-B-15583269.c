#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
	{return (*(int*)a-*(int*)b);}
int main()
	{
	long long int n,a[200000],i,max=0,min=1000000000,c1=0,c=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<n;i++)
		if(a[i]<min) min=a[i];
	for(i=0;i<n;i++)
		if(a[i]>max) max=a[i];
	if(max==min)
		printf("0 %lld",(n)*(n-1)/2);
	else
	{for(i=0;i<n;i++)
		{if(a[i]==max) c++;
		if(a[i]==min)c1++;}
	printf("%lld %lld",max-min,c1*c);}
	return 0;	
	}