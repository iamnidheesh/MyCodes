#include<stdio.h>
int main() {
	int n,a[1000001],i,j=0,m,q,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&q);
	sum=sum+q;
	for( ;j<sum;j++)
		a[j]=i+1;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++) {
		scanf("%d",&q);
		printf("%d\n",a[q-1]);
	}
	return 0;
	}