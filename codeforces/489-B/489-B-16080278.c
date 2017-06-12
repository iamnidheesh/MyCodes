#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
	{return *(int*)a-*(int*)b;}
int main() {
	int a[101],b[101],n,m,i,j,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	qsort(a,n,sizeof(int),cmp);
	qsort(b,m,sizeof(int),cmp);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(abs(a[i]-b[j])<=1&&a[i]!=101&&b[j]!=101) {
				c++;
				a[i]=101;
				b[j]=101;
				break;
			}
	printf("%d",c);
	return 0;
	}