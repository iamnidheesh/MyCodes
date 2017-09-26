#include<stdio.h>
int main()
	{
	int t,a,i;
	scanf("%d",&t);
	while(t--)
		{
		scanf("%d",&a);
		for(i=0;i<=(360/(180-a));i++)
			{if(i*(180-a)==360)
				{a=0;
					break;
				}
			}
		if(a==0)
			printf("YES\n");
		else
			printf("NO\n");
		}
	return 0;
	}