#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
char s[100];
int i=0;
scanf("%s",s);
for(i=0;i<strlen(s);i++)
{if(isupper(s[i]))
	s[i]=(char)((int)s[i]+32);
if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y')
	{printf(".%c",s[i]);
	}
}

return 0;
}