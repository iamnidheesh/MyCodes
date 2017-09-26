#include<stdio.h>
int main()
	{
	int n,i;
	long long int s=0;
	scanf("%d",&n);
	for(i=1;i<n;i++)
		s=s+(n-i)*i;//correct switch * wrong switch
	printf("%Ld",s+n);//s+n->for all correct switches
	return 0;
	}