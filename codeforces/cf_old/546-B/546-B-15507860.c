#include<stdio.h>
int cmp(void *a,void *b)
	{return (*(int *)a-*(int*)b);}
int main()
	{
	int n,a[3000],flag,i,j,c=0;scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	while(1)
	{flag=0;
	for(i=0;i<n-1;i++)
		{if(a[i]==a[i+1]){flag=1;
			for(j=i+1;a[j]==a[i];j++)
				{a[j]++;c++;}
		}}
		if(flag==0)
			break;
	}
	printf("%d",c);
	return 0;}