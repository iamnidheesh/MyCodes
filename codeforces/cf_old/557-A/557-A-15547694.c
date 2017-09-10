#include<stdio.h>
int main()
	{
	int n,s1,m1,s2,m2,s3,m3,d1=0,d2=0,d3=0;scanf("%d%d%d%d%d%d%d",&n,&s1,&m1,&s2,&m2,&s3,&m3);
	n=n-(s1+s2+s3);d1=s1;d2=s2;d3=s3;
	if(n>=0&&n+s1<m1)
		{d1=d1+n;n=0;}
	else{n=n-m1+s1;d1=m1;}
	if(n>=0&&n+s2<m2)
                {d2=n+d2;n=0;}
	else
		{n=n-m2+s2;d2=m2;}
	if(n>=0&&n+s3<m3)
                {d3=n+d3;n=0;}
	else
		{d3=m3;}
	printf("%d %d %d",d1,d2,d3);
	return 0;
	}