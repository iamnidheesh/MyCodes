#include<stdio.h>
int main()
	{
	int n,a[100],i,j,small=999,max=0;scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n-2;i++)
		{max=0;
		for(j=0;j<n-1;j++)
			{if(j+1==i){ j++;
				if(a[j+1]-a[j-1]>max) max=a[j+1]-a[j-1];}
			else if(a[j+1]-a[j]>max) max=a[j+1]-a[j];
			}
			if(max<small)
				small=max;
		}
		printf("%d",small);
	return 0;
	}