#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
#define MOD 1000000007
int t,n,p;
lli dp[10001][11];
int main()
{
	cin>>t;
	while(t--) {
		cin>>n>>p;
		lli ans = 0;
		memset(dp,-1,sizeof(dp));
		for(int i = 0;i < p;i++)
			for(int j = 0;j <= i;j++)
				dp[j][i] = 0;
		dp[1][0] = 1;
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < p;j++) {
				if(i > j) {
					dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
					dp[i][j] %= MOD;
				}
			}
		}
		for(int i = 0;i < p;i++) {
			ans += dp[n][i];
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
    return 0;
}
