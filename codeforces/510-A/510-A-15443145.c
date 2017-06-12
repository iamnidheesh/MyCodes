#include<stdio.h>
int main()
	{
	int i,j,n,m,flag1=0,flag2=0;scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		{for(j=0;j<m;j++)
			{if(i%2==0)
				{printf("#");}
			else if(j==0)
				{if(flag1==0){printf(".");flag1=1;}
				else
				{printf("#");flag1=0;}}
			else if(j==m-1)
				{if(flag2==0){printf("#");flag2=1;}
				else{printf(".");flag2=0;}
				}
				
			else
				{printf(".");}
			};
		printf("\n");
		}
		return 0;
		}