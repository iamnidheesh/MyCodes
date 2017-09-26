#include<stdio.h>
int cmp(void *a,void *b)
	{if(*(int *)a>*(int*)b)
		return 1;
	else return -1;
	}
int main() {
	long int n,l,a[1001],i,max=0;
	scanf("%ld%ld",&n,&l);
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	qsort(a,n,sizeof(long int),cmp);
	for(i=0;i<n-1;i++)
		if(a[i+1]-a[i]>max)
			max=a[i+1]-a[i];
	if(max/2.0<a[0]&&a[0]>l-a[n-1])
		printf("%.10f",a[0]*1.0);
	else if(max/2.0<l-a[n-1])
		printf("%.10f",(l-a[n-1])*1.0);
	else printf("%.10f",max/2.0);
	return 0;
	}