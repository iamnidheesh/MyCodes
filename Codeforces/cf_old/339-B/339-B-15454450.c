#include<stdio.h>
int main()
	{
	int n,m,t,l=0;
	long long int s=0;
	scanf("%d%d",&n,&m);
	while(m--)
		{
		scanf("%I64d",&t);
		if(t>=l)
			s=s+t-l;
		else
			{s=s+n-l+t;}
		l=t;
		}
	printf("%I64d",s-1);
	return 0;
	}