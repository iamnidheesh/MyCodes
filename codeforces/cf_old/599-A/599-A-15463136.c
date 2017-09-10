#include<stdio.h>
int main()
	{
	long long int d1,d2,d3;
	scanf("%I64d%I64d%I64d",&d1,&d2,&d3);
	if(d3<d1+d2)
		if(d1<d2)
			{if(d1+d3<d2)
				printf("%I64d",2*d1+2*d3);
			else printf("%I64d",d1+d2+d3);}
		else {if(d2+d3<d1)
				printf("%I64d",2*d2+2*d3);
			else printf("%I64d",d1+d2+d3);}
	else
		printf("%I64d",2*d1+2*d2);
	return 0;
	}