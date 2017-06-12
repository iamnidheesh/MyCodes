#include<stdio.h>
int main()
	{
	int n,c=0,i;
	scanf("%d",&n);
	for(i=5;i>=1;i--)
		{
		c=c+n/i;
		n=n-(n/i)*i;
		}
	printf("%d",c);
	return 0;
	}