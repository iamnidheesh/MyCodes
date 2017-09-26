#include<stdio.h>
int main()
	{int n,m,c=0;scanf("%d%d",&n,&m);
	while(n!=0&&m!=0)
		{
		if(n>m)
			if(n-2>=0&&m-1>=0)
				{c++;m=m-1;n=n-2;}
			else break;
		else
			if(n-1>=0&&m-2>=0)
				{c++;m=m-2;n=n-1;}
			else break;
		}
	printf("%d",c);
	return 0;
	}