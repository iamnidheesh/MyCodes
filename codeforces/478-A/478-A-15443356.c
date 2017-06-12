#include<stdio.h>
int main()
	{
	int sum=0,i,a[5];
	for(i=0;i<5;i++)
		{scanf("%d",&a[i]);
		sum=sum+a[i];
		}
	if(sum%5==0&&sum!=0)
		printf("%d",sum/5);
	else	printf("-1");
	return 0;
	}