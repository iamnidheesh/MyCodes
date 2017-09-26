#include<stdio.h>
int main()
	{
	int i,j,a[6],c[6],l=0,e=0;
	for(i=0;i<6;i++)
		{scanf("%d",&a[i]);c[i]=0;}
	for(i=0;i<6;i++)
		{for(j=0;j<6;j++)
			if(a[i]==a[j]&&a[i]!=0)
				{c[i]++;
				if(j!=i)
					a[j]=0;}
			a[i]=0;
		}
	for(i=0;i<6;i++)
		{if(c[i]>=4)
			{l=1;break;}
		}
	for(i=0;i<6;i++)
		{if(c[i]==2||c[i]==6)
			{e=1;break;}
		}
	if(l==1)
		if(e==1)printf("Elephant");
		else printf("Bear");
	else
		printf("Alien");
	return 0;
	}