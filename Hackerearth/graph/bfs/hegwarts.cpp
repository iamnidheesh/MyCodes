#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int dp[10000001];
li t,n;
int solve(li);
int rec(li x) {
	if(x <= 10000001)
		return solve(x);
	int a = INT_MAX,b = INT_MAX,c = INT_MAX;
	if(x%2 == 0)
		a = 1 + rec(x/2);
	if(x%3 == 0)
		b = 1 + rec(x/3);
	if(x%2 != 0 || x%3 != 0)
	    c = 1 + rec(x-1);
	return min(min(a,b),c);
}
int solve(li x) {
	if(x == 1)
		return 0;
	if(dp[x] != -1)
		return dp[x];
	int a = INT_MAX,b = INT_MAX,c = INT_MAX;
	if(x%2 == 0)
		a = 1 + solve(x/2);
	if(x%3 == 0)
		b = 1 + solve(x/3);
    if(x%2 != 0 || x%3 != 0)
         c = 1 + solve(x-1);
	return dp[x] = min(min(a,b),c);
}
int main() {
	cin>>t;
	int ans;
	memset(dp,-1,sizeof(dp));
	while(t--) {
		scanf("%ld",&n);
		if(n <= 10000001)
			ans = solve(n);
		else
			ans = rec(n);
		printf("%d\n",ans);
	}
}