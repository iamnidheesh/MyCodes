#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int t,n;
lli a[10001];
lli dp[10001];
int main() {
	cin>>t;
	for(int k = 1;k <= t;k++) {
		cin>>n;
		for(int i = 1;i <= n;i++)
			scanf("%lld",&a[i]);
		memset(dp,-1,sizeof(dp));
		dp[1] = a[1];
		dp[0] = 0;
		for(int i = 2;i <= n;i++) {
			dp[i] = max(dp[i-1],a[i]+dp[i-2]);
		}
		printf("Case %d: %lld\n",k,dp[n]);
	}
}