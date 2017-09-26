#include<stdio.h>
int main()
	{
	int n,q,p,r,c=0;
	scanf("%d",&n);
	while(n--)
		{
		scanf("%d%d%d",&p,&q,&r);
		if(p==1&&q==1||p==1&&r==1||q==1&&r==1)
			c++;
		}
	printf("%d",c);
	return 0;
	}