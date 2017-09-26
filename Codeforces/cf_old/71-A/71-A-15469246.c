#include<stdio.h>
#include<string.h>
int main()
	{int n;scanf("%d",&n);
	char s[101];
	while(n--)
	{scanf("%s",s); if(strlen(s)<11)printf("%s\n",s);else printf("%c%d%c\n",s[0],(int)strlen(s)-2,s[(int)strlen(s)-1]);}return 0;}