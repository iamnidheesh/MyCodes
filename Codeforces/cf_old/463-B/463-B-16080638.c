#include<stdio.h>
int main() {
	int n,h,e=0,k=0,d=0;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&h);
		if(k<h&&e<h-k) {
			d=d+h-k-e;
			e=0;
		}
		else if(k<h&&e>=h-k) {
			e=e-(h-k);
			}
		else {
			e=e+k-h;
		}
		k=h;
	}
	printf("%d",d);
	return 0;
	}