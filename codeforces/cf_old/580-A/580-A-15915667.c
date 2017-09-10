#include<stdio.h>
int main() {
	long int n,a[100000],i=0,c=0,max=0;
	scanf("%ld",&n);
	for( i=0;i<n;i++ ) 
		scanf("%ld",&a[i]);
	i=0;
	while(i<n) {c=0;
		for(;a[i]<=a[i+1]&&i<n-1;i++)
			c++;
		i=i+1;
		c=c+1;
		if(c>max)
			max=c;
		}
	printf("%ld",max);
	return 0;
	}