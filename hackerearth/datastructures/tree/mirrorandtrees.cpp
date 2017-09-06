#include <bits/stdc++.h>
using namespace std;
int a[1000001],n,t,visr[1000001];
void travelr(int x) {
	visr[x] = 1;
	printf("%d\n",a[x]);

	if(2*x+1 <= n && a[2*x+1])
		travelr(2*x+1);
	else if(2*x <= n && a[2*x])
		travelr(2*x);
}
void travell(int x) {
	if(!visr[x])
		printf("%d\n",a[x]);

	if(2*x <= n && a[2*x])
		travell(2*x);
	else if(2*x+1 <= n && a[2*x+1] )
		travell(2*x+1);
	
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		memset(visr,0,sizeof(visr));
		for(int i = 1;i <= n;i++) {
			scanf("%d",&a[i]);
		}
		travelr(1);
		travell(1);
		printf("\n");
	}

}