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
		memset(dp,0,sizeof(dp));
	    dp[1][0] = 1;
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < p;j++) {
			    if(i == 1 && j == 0)
			     continue;
				else if(i > j) {
				    if(j == 0) {
				        lli temp = 0;
				        for(int k = 0;k < p;k++)
				            temp += dp[i-1][k];
				        dp[i][0] =  temp;
				    }
				    else
				        dp[i][j] = dp[i-1][j-1];
				    dp[i][j] %= MOD;
				}
				else
				    dp[i][j] = 0;
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
