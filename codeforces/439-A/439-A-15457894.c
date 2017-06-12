#include<stdio.h>
int main()
	{
	int n,d,m,t;
	scanf("%d%d",&n,&d);
	int c=0;
	m=n;
	while(m--)
		{scanf("%d",&t);
		d=d-t;
		}
	d=d-(n-1)*10;
	if(d<0)
		printf("-1");
	else
		printf("%d",(n-1)*2+d/5);
	return 0;
	}