#include<stdio.h>
int main()
	{
	int i,a[4],c=0;
	for(i=0;i<4;i++)
		scanf("%d",&a[i]);
	char s[100001];
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
		{if(s[i]=='1')
			c=c+a[0];
		else if(s[i]=='2')
			c=c+a[1];
		else if(s[i]=='3')
			c=c+a[2];
		else c=c+a[3];
		}
	printf("%d",c);
	}