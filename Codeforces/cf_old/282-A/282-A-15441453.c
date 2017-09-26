#include<stdio.h>
int main()
	{
	int n,i,c=0;
	scanf("%d",&n);
	char x[10];
	while(n--)
		{scanf("%s",x);
		if(x[1]=='+')
			c++;
		else
			c--;
		}
	printf("%d",c);
	return 0;
	}