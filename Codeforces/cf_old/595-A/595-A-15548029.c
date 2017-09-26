#include<stdio.h>
int main()
	{
	int n,m,i,c=0,j,k;
	scanf("%d%d",&n,&m);
	k=m;
	while(n--)
		{m=k;
		while(m--)
			{scanf("%d%d",&i,&j);
			if(i==1||j==1)
				c++;}
		}
	printf("%d",c);
	return 0;
	}