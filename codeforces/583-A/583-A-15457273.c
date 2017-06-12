#include<stdio.h>
int main()
	{
	int i,h,v,n;
	scanf("%d",&n);
	int hi[50],vi[50];
	for(i=0;i<n;i++)
		{hi[i]=0;vi[i]=0;}
	for(i=0;i<n*n;i++)
	{scanf("%d%d",&h,&v);
	if(hi[h-1]==0&&vi[v-1]==0)
		{hi[h-1]=1;vi[v-1]=1;
		printf("%d ",i+1);
		}}
	return 0;
	}