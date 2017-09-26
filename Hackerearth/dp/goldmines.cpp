#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long int a[1002][1002];
int q,r,c,x1,x2,y1,y2;
int main() {
	cin>>r>>c;
	for(int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++) {
			scanf("%lld",&a[i][j]);
		}
	cin>>q;
	for(int i = 2;i <= r;i++) {
		a[i][1] += a[i-1][1]; 
	}
	for(int j = 2;j <= c;j++) {
		a[1][j] += a[1][j-1];
	}
	for(int i = 2;i <= r;i++)
		for(int j = 2;j <= c;j++) {
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	while(q--) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%lld\n",abs(a[x1-1][y1-1] + a[x2][y2] - a[x1-1][y2] - a[x2][y1-1]) );
	}
}