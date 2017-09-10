#include<stdio.h>
int main() {
	int n,k;
	long int a;
	scanf("%d%d",&n,&k);
	int c,ans=0;
	while(n--) {
		c=0;
		scanf("%ld",&a);
			
		while(a) {
			if(a%10==4||a%10==7) c++;
			a=a/10;
		}
		if(c<=k) ans++;
	}
	printf("%d",ans);
	return 0;
	}