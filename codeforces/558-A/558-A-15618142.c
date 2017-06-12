#include<stdio.h>
#include<stdlib.h>
int main()
	{
	int n,temp,b[100],a[100],p[100],q[100],i=0,j,c1=0,c2=0,sum=0,small=0,pos;
	for(scanf("%d",&n);i<n;i++)
		{scanf("%d%d",&b[i],&a[i]);}
	for(i=0;i<n-1;i++)
		{small=abs(b[i]);
		pos=i;
		for(j=i+1;j<n;j++)
			{if(small>abs(b[j]))
				{small=abs(b[j]);pos=j;}
			}
		temp=b[pos];
		b[pos]=b[i];
		b[i]=temp;
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;}
	for(i=0;i<n;i++)
		{if(b[i]>0)
			{p[c1]=a[i];
			c1++;}
		else
			{q[c2]=a[i];
			c2++;}
		}
	if(c1>c2)
		for(i=0;i<c2+1;i++)
			{sum=sum+p[i];
			if(i!=c2)
			sum=sum+q[i];}	
	else if(c2>c1)
		for(i=0;i<c1+1;i++)
			{sum=sum+q[i];
			if(i!=c1) sum=sum+p[i];
			}
	else
		for(i=0;i<n;i++)
			sum=sum+a[i];
	printf("%d",sum);
	return 0;
	}