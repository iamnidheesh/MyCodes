#include<stdio.h>
int cmp(void * a,void *b)
	{return(*(int*)b-*(int*)a);}
int main()
	{
	int k,i;
	int a[12];
	scanf("%d",&k);
	if(k==0)
		{printf("0");return 0;}
	for(i=0;i<12;i++)
		scanf("%d",&a[i]);
	qsort(a,12,sizeof(int),cmp);
	for(i=0;i<12;i++)
		{k=k-a[i];
		if(k<=0)
			break;
		}
	if(i==12)
		printf("-1");
	else  printf("%d",i+1);
	return 0;
	}