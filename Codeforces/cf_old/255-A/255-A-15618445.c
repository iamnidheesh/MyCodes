#include<stdio.h>
int main()
	{
	int n,max,e,sumc=0,sumbi=1,sumb=0,i=0;
	scanf("%d",&n);
	while(i<n)
		{scanf("%d",&e);
		if(i%3==0) sumc=sumc+e;
		else if(i%3==1) sumbi=sumbi+e;
		else sumb=sumb+e;i++;
		}
	max=sumc;
	if(max<sumbi)
		max=sumbi;
	if(max<sumb)
		max=sumb;
	if(max==sumc) printf("chest");
	else if(max==sumbi) printf("biceps");
	else printf("back");
	return 0;
	}