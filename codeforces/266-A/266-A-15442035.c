#include<stdio.h>
int main()
	{
	int n,i,c=0;char s[55];
	scanf("%d%s",&n,s);
	for(i=0;i<n-1;i++)
		if(s[i]==s[i+1])
			{c++;}
	printf("%d",c);
	return 0;
	}