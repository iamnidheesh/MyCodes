#include<stdio.h>
int main()
	{
	int i,j,n,m=0;
	scanf("%d",&n);
	int a[10][10];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			{if(i==0 || j==0)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j]+a[i][j-1];
			}
	if(n==1)
		printf("1");
	else
	{for(j=0;j<n;j++)
		m=m+a[n-2][j];
	printf("%d",m);}
	return 0;
	}