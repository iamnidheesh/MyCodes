#include<stdio.h>
int main()
	{
	int n,m,i,j,c=0;
	char x[50][50];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",x[i]);
	for(i=0;i<n-1;i++)
		for(j=0;j<m-1;j++)
			if((x[i][j]=='f'||x[i][j]=='a'||x[i][j]=='c'||x[i][j]=='e')&&(x[i][j+1]=='f'||x[i][j+1]=='a'||x[i][j+1]=='c'||x[i][j+1]=='e')&&x[i][j+1]!=x[i][j])
					if(x[i+1][j]!=x[i][j]&&x[i+1][j]!=x[i][j+1]&&x[i+1][j+1]!=x[i][j]&&x[i+1][j+1]!=x[i][j+1]&&x[i+1][j]!=x[i+1][j+1])
						if((x[i+1][j]=='f'||x[i+1][j]=='a'||x[i+1][j]=='c'||x[i+1][j]=='e')&&(x[i+1][j+1]=='f'||x[i+1][j+1]=='a'||x[i+1][j+1]=='c'||x[i+1][j+1]=='e'))
					c++;
	printf("%d",c);
	return 0;
	}