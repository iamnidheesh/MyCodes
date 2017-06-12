#include<stdio.h>
int main()
	{
	int i,n,v,k,s,flag,c=0,a[50];
	scanf("%d%d",&n,&v);
	for(i=1;i<=n;i++)
		{flag=0;
		scanf("%d",&k);
		while(k--)
			{scanf("%d",&s);
			if(v>s&&flag==0)
				{
				a[c]=i;
				c++;flag=1;}
			}
		}
	printf("%d\n",c);
	for(i=0;i<c;i++)
		printf("%d ",a[i]);
	return 0;
	}