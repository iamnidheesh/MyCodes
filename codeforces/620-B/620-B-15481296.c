#include<stdio.h>
int main()
	{
	int a,b,m,i,j,c=0;scanf("%d%d",&a,&b);
	int ai[]={6,2,5,5,4,5,6,3,7,6};
	for(i=a;i<=b;i++)
		{m=i;
		while(m)
			{for(j=0;j<10;j++)
				{if(m%10==j)
					c=c+ai[j];
				}
			m=m/10;
			}
		}
	printf("%d",c);
	return 0;
	}