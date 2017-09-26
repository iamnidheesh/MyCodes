#include<stdio.h>
int main()
	{
	int n,i,h=0;
	scanf("%d",&n);
	for(i=1;;i++)
		{if(h+i<=n)
			{h=h+i;
			n=n-h;}
		else break;}
	printf("%d",i-1);
	return 0;
	}