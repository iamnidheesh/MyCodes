#include<stdio.h>
int main()
	{
	int i,j,n,c=0,flag=1;
	scanf("%d",&n);
	char a[102][102];
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
			{c=0;
			if(i!=0)
				if(a[i-1][j]=='o')c++;
			if(j!=0)
				if(a[i][j-1]=='o')c++;
			if(i!=n-1)
				if(a[i+1][j]=='o')c++;
			if(j!=n-1)
				if(a[i][j+1]=='o')c++;
			if(c%2!=0){flag=0;break;}
			}
		if(flag==0)
			break;		
		}
	if(flag==1)
		printf("YES");
	else
		printf("NO");
	return 0;
	}