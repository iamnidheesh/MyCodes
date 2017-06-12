#include<stdio.h>
int main()
{
int n,i,t;scanf("%d%d",&n,&t);
char s[50];scanf("%s",s);
while(t>0){
	for(i=0;i<n-1;i++)
		{if(s[i]=='B'&&s[i+1]=='G')
			{s[i]='G';s[i+1]='B';i++;}
		}
		
	t--;
	}
	printf("%s",s);
return 0;
}