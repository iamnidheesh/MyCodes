#include<stdio.h>
int main()
	{
	int n,x,m;
	double c=0.0;
	scanf("%d",&n);m=n;
	while(n--)
		{
		scanf("%d",&x);
		c=c+(double)x/100;
		}
	printf("%.12lf",(c*100)/m);
	return 0;
	}