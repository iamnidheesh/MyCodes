#include<stdio.h>
#include<string.h>
int main()
	{
	char s[205];
	scanf("%s",s);
	int i=0;
	while(s[i]!='\0')
		{
		while(strncmp(s+i,"WUB",3)==0)
			i=i+3;
		for( ;strncmp(s+i,"WUB",3)!=0&&s[i]!='\0';i++ )
			printf("%c",s[i]);
		printf(" ");
		}
	return 0;
	}