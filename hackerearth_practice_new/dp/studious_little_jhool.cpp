#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n;
int dp[115];
int cal(int x) {
	if(x == 0)
		return 0;
	if(x < 10)
		return 100;
	if(dp[x] != -1)
		return dp[x];
    return dp[x] = 1 + min(cal(x-12),cal(x-10));
}
int main()
{
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--) {
		cin>>n;
		printf("%d\n",cal(n) >= 100 ? -1 : dp[n]);
	}
    return 0;
}
