#include<stdio.h>
int main()
	{int n,i;
	char a[100];scanf("%d%s",&n,a);
	for(i=0;a[i]=='1';i++);
	i+1>n?printf("%d",i):printf("%d",i+1);
	return 0;
	}