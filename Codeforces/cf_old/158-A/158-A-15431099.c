#include<stdio.h>
#include<stdlib.h>
int main()
	{
	int i,n,k;
	scanf("%d%d",&n,&k);
	int *a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int c=0;
	for(i=0;i<n;i++)
		if(a[i]>=a[k-1]&&a[i]>0)
			c++;
	printf("%d",c);
	return 0;
	}