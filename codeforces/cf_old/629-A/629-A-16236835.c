#include<stdio.h>
int co[101];
int r[101];
int main() {
	char c[101][101];
	long int s=0;
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",c[i]);
	for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
			{
				if(c[i][j]=='C')
					{r[i]++;
					co[j]++;
					}
			}
		}
	for(i=0;i<n;i++)
		s=s+(co[i]*(co[i]-1))/2+(r[i]*(r[i]-1))/2;
	printf("%ld",s);
	return 0;
	}