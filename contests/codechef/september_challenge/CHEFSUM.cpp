#include <bits/stdc++.h>
using namespace std;
int t,a[100001],n,val,ans;
int main() {

	cin>>t;
	while(t--) {
		cin>>n;
		val = 1000001;
		ans = 1;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&a[i]);
			if(val > a[i]) {
				val = a[i];
				ans = i;
			}
		}
		printf("%d\n",ans);
	}
}