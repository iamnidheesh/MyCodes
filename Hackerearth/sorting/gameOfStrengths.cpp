#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
#define MOD 1000000007
int t,n;
lli a[100001],b[100001];
int main()
{
	cin>>t;
	while(t--) {
		cin>>n;
		lli ma = 0;
		for(int i = 0;i < n;i++) {
			cin>>a[i];
			ma = max(ma,a[0]);
		}
		sort(a,a+n);
		b[0] = a[0];
		for(int i = 1;i < n;i++) {
			b[i] = a[i] + b[i-1];
		}
		lli ans = 0;
		for(int i = n-1;i > 0;i--) {
			ans += (i*a[i]) - (b[i-1]);
			ans %= MOD;
		}
		ans = (ans*ma)%MOD;
		cout<<ans<<endl;
	}
    return 0;
}
