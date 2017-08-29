#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n;
lli a[100001],k;
int main()
{
	cin>>t;
	while(t--) {
		cin>>n>>k;
		lli ans = 0,temp = 0;
		for(int i = 0;i < n;i++) {
			scanf("%lld",&a[i]);
			if(a[i] <= k) {
				temp += a[i];
				ans = max(temp,ans);
			}
			else {
				temp = 0;
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}
